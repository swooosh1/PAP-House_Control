#ifndef __SERIALPORT_HPP__
#define __SERIALPORT_HPP__

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <stdint.h>

using namespace std;

class serialPort
{
	public:
		serialPort(const char* pName, boost::asio::serial_port_base::baud_rate bRate, boost::asio::serial_port_base::character_size bNumber, boost::asio::serial_port_base::parity par, boost::asio::serial_port_base::stop_bits sBits);
		serialPort(boost::asio::serial_port_base::baud_rate bRate);
		serialPort();




		
		void get(uint8_t* receiveData, uint16_t receiveSize);
		void request(uint8_t* sendData, uint16_t sendSize);
		size_t send(uint8_t *data, uint16_t size);
		void receive(uint8_t* data, uint16_t size);

	protected:

		boost::asio::io_service io;

		boost::asio::serial_port_base::baud_rate baud;

		boost::asio::serial_port_base::character_size bitNumber;

		boost::asio::serial_port_base::parity parity;

		boost::asio::serial_port_base::stop_bits stopBits;

		boost::asio::serial_port port;

		boost::thread runThread;

	private:

};


#endif
