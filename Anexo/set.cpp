#include "serialPort.hpp"
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::dec;
using std::hex;

int8_t ackState(uint8_t received)
{
	static int8_t state = -1;
	static uint8_t timeout=0;
/*
 *	state=-1 => ""
 *	state=0 => "#"
 *	state=1 => "##"
 *	state=2 => "##A"
 *	state=3 => "##AC"
 *	state=4 => "##ACK"
 *
 */
	switch(state) //
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
				state=-1;
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


void ondone()
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><title>Hello</title><body>"<<endl;
	cout<<"<p>On Done!</p>"<<endl;
	cout<<"</body></html>"<<endl;
}

void offdone()
{
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><title>Hello</title><body>"<<endl;
	cout<<"<p>Off Done!</p>"<<endl;
	cout<<"</body></html>"<<endl;
}

void error(uint8_t *receive)
{
		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><title>Hello</title><body>"<<endl;
		cout<<"<p>Error:"<<receive<<"</p>"<<endl;
		cout<<"</body></html>"<<endl;
}

int main()
{
	//boost::asio::serial_port_base::baud_rate bRate(115200);
	boost::asio::serial_port_base::baud_rate bRate(57600);
	serialPort port(bRate);
	int i;


	uint8_t send[20]={0};
	uint8_t receive[20]={0};
	int8_t ret;
	cin.ignore(100,'=');
	cin>>i;
	switch(i)
	{
		case 0:
			strcpy((char *)send,"##startOFF\n\r");
			port.request(send, 13);
			port.get(receive,1);
			while((ret=ackState(receive[0]))==0)
			{
				port.get(receive,1);
			}

			if(ret==1)
			{
				offdone();
			}
			else
			{
				error(receive);
			}
			break;
		case 1:
			strcpy((char *)send,"##startON\n\r");
			port.request(send, 12);
			port.get(receive,1);
			while((ret=ackState(receive[0]))==0)
			{
				port.get(receive,1);
			}

			if(ret==1)
			{
				ondone();
			}
			else
			{
				error(receive);
			}
			break;
		case 2:
		default:
			strcpy((char *)receive,"##DEF\n\r");
			error(receive);
	}

	return 0;
}


