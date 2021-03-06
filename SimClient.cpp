// SimClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void send_something(boost::asio::ip::tcp::socket& socket, std::string message)
{
	boost::array<char, 128> buf;
	std::copy(message.begin(), message.end(), buf.begin());
	boost::system::error_code error;
	socket.write_some(boost::asio::buffer(buf, message.size()), error);
}

int main()
{
	boost::asio::io_service ios;

	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 2014);

	boost::asio::ip::tcp::socket socket(ios);

	try {
		socket.connect(endpoint);
	}
	catch (std::exception& e) {
		std::cout << "Couldn't open connection: " << e.what() << std::endl;
		return -1;
	}

	while (true) {
		try {
			send_something(socket, "Test message\n");

			std::chrono::milliseconds timespan(500);

			std::this_thread::sleep_for(timespan);
		}
		catch (std::exception& e) {
			std::cout << "error: " << e.what() << std::endl;
			socket.close();
			return -1;
		}
	}
}