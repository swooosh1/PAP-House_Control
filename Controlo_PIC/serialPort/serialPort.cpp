#include "serialPort.hpp"

#include <iostream>
using namespace std;
using std::cout;
using std::endl;


	serialPort::serialPort(const char* pName, boost::asio::serial_port_base::baud_rate bRate, boost::asio::serial_port_base::character_size bNumber, boost::asio::serial_port_base::parity par, boost::asio::serial_port_base::stop_bits sBits): io(), baud(bRate), bitNumber(bNumber), parity(par), stopBits(sBits), port(io, pName)
	{
		port.set_option( baud );
		port.set_option( bitNumber );
		port.set_option( parity );
		port.set_option( stopBits );
		
		
	}
	serialPort::serialPort(boost::asio::serial_port_base::baud_rate bRate): io(), baud(bRate), bitNumber(8), parity(boost::asio::serial_port_base::parity::none), stopBits(boost::asio::serial_port_base::stop_bits::one), port(io,"/dev/ttyUSB0")
 	{
		port.set_option( baud );
		port.set_option( bitNumber );
		port.set_option( parity );
		port.set_option( stopBits );
	
	}

	serialPort::serialPort(): io(), baud(115200U), bitNumber(8), parity(boost::asio::serial_port_base::parity::none), stopBits(boost::asio::serial_port_base::stop_bits::one), port(io,"/dev/ttyUSB0")
 	{
		port.set_option( baud );
		port.set_option( bitNumber );
		port.set_option( parity );
		port.set_option( stopBits );
	}

	void serialPort::request(uint8_t* sendData, uint16_t sendSize)
	{
		port.write_some(boost::asio::buffer(sendData, sendSize));
	}
	void serialPort::get(uint8_t* receiveData, uint16_t receiveSize)
	{
		port.read_some(boost::asio::buffer(receiveData, receiveSize));
	}	

	size_t serialPort::send(uint8_t* data, uint16_t size)
	{
		return port.write_some(boost::asio::buffer(data, size));
		
	}

	void serialPort::receive(uint8_t* data, uint16_t size)
	{
		
	}





