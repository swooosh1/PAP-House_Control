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
		// Inicio Construtores
		serialPort(const char* pName, boost::asio::serial_port_base::baud_rate bRate, boost::asio::serial_port_base::character_size bNumber, boost::asio::serial_port_base::parity par, boost::asio::serial_port_base::stop_bits sBits);
		serialPort(boost::asio::serial_port_base::baud_rate bRate);
		serialPort();
		// Fim Construtores



		// Ler e Escrever da Porta Serie
		void get(uint8_t* receiveData, uint16_t receiveSize);
		void request(uint8_t* sendData, uint16_t sendSize);
	

	protected:

		boost::asio::io_service io;

		boost::asio::serial_port_base::baud_rate baud;

		boost::asio::serial_port_base::character_size bitNumber;

		boost::asio::serial_port_base::parity parity;

		boost::asio::serial_port_base::stop_bits stopBits;

		boost::asio::serial_port port;



	private:

};


#endif
