//===========================================================================
// File Name : main.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Main() for assignment 4. Instantiate, initialize and run a
//	dynamically allocated SmartCarrier object.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260619	    1.0         000         Zachary Rowson    Initial version
// 20260619	    2.0         000         Zachary Rowson    Unit testing of AccountNotFoundException class
// 20260619	    3.0         000         Zachary Rowson    Unit testing of Media class
//===========================================================================

#include "Message.h"
#include "Media.h"
#include <iostream>

int main() {
	Message<Media> message_1{};
	Message<Media> message_2{ "123-456-7890", Media(50.0) };
	Message<std::string> message_3{ "987-654-3210", "Hello, world!" };
	
	std::cout << "|--- Test Accessors ---|" << std::endl;
	std::cout << "To: " << message_1.get_to() << std::endl;
	std::cout << "To: " << message_2.get_to() << std::endl;
	std::cout << "To: " << message_3.get_to() << std::endl;
	std::cout << "Message data: " << message_1.get_message_data().get_size() << " MB" << std::endl;
	std::cout << "Message data: " << message_2.get_message_data().get_size() << " MB" << std::endl;
	std::cout << "Message data: " << message_3.get_message_data() << std::endl;
	
	std::cout << "|--- Test Mutators ---|" << std::endl;
	message_1.set_to("555-555-5555");
	Media media_1(75.0);
	message_1.set_message_data(media_1);
	std::cout << "To: " << message_1.get_to() << std::endl;
	std::cout << "Message data: " << message_1.get_message_data().get_size() << " MB" << std::endl;

	std::cout << "|--- Test Charges ---|" << std::endl;
	std::cout << "Charge for message 1: $" << message_1.get_message_data().GetCharge() << std::endl;

	return 0;
}