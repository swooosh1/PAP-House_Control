#include "serialPort.hpp"
#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::dec;
using std::hex;
int8_t ackState(uint8_t received, float &pwm)
{
	static int8_t state = -1;
	static uint8_t timeout=0;
	static uint8_t fnumber[10]={0};
	static uint8_t count=0;
/*
 *	state=-1 => ""
 *	state=0 => "#"
 *	state=1 => "##"
 *	state=2 => "##A"
 *	state=3 => "##AC"
 *	state=4 => "##ACK"
 *	state=5 => "##ACK*."
 *	state=6 => "##ACK*.?"
 *	state=6 => "##ACK*.??"
 *
 */
	switch(state)
	{
		case -1:
			if(received=='#')
			{
				state++;
				timeout=0;
			}
			else
			{
				state=-1;
				timeout++;
				if(timeout==20) 
				{
					timeout=0;
					return -1;
				}
				return 0;
			}
			break;
		case 0:
			if(received=='#')
			{
				state++;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		case 1:
			if(received=='A')
			{
				state++;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		case 2:
			if(received=='C')
			{
				state++;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		case 3:
			if(received=='K')
			{
				state++;
			}

			else
			{
				state=-1;
				return -1;
			}
			break;
		case 4:
			if((received>='0')&&(received<='9'))
			{
				fnumber[count++]=received;
			}
			else if(received=='.')
			{
				state++;
				fnumber[count++]=received;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		case 5:
			if((received>='0')&&(received<='9'))
			{
				fnumber[count++]=received;
				state++;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		case 6:
			if((received>='0')&&(received<='9'))
			{
				fnumber[count++]=received;
				fnumber[count]=0;
				count=0;
				pwm=atof((char*)fnumber);
				state = -1;
				return 1;
			}
			else
			{
				state=-1;
				return -1;
			}
			break;
		default:
			state=-1;
			return -1;
	}
	return 0;
}

void info(float pwmVal)
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><title>Hello</title><body>"<<endl;
	cout<<"PWM is at: "<<pwmVal<<"%"<<endl;
	cout<<"</body></html>"<<endl;
}

void error()
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><title>Hello</title><body>"<<endl;
	cout<<"Error! "<<endl;
	cout<<"</body></html>"<<endl;
}


int main()
{

	boost::asio::serial_port_base::baud_rate bRate(57600);
	serialPort port(bRate);
	uint8_t send[20];
	uint8_t receive[20];
	float pwm;
	int8_t ret=0;
	strcpy((char *)send,"##startGET\n\r");

	port.request(send, 13);
	port.get(receive,1);
	while((ret=ackState(receive[0],pwm))==0)
	{
		port.get(receive,1);
	}
	if(ret==1)
	{
		info(pwm);
	}
	else
	{
		error();
	}
	return 0;
}


