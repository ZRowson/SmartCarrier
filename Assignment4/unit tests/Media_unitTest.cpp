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

#include "Media.h"
#include <iostream>

int main() {
	// Unit testing for Media class
	Media media_1;
	Media media_2(50.0);
	Media media_3(200.0);
	
	std::cout << "|--- Class constants ---|\n";
	std::cout << "Default size: " << Media::DEFAULT_SIZE << " MB" << std::endl;
	std::cout << "Charge per MB: $" << Media::CHARGE_PER_MB << std::endl;
	std::cout << "Minimum charge: $" << Media::MINIMUM_CHARGE << std::endl;
	std::cout << "Size threshold: " << Media::SIZE_THRESHOLD << " MB" << std::endl;
	std::cout << "\n|--- Accessors ---|\n";
	std::cout << "Size: " << media_1.get_size() << " MB" << std::endl;
	std::cout << "Size: " << media_2.get_size() << " MB" << std::endl;
	std::cout << "Size: " << media_3.get_size() << " MB" << std::endl;
	std::cout << "|--- Mutators ---|\n";
	media_1.set_size(25.0);
	std::cout << "Size: " << media_1.get_size() << " MB" << std::endl;
	std::cout << "|--- Charges ---|\n";
	std::cout << "Charge: $" << media_1.GetCharge() << std::endl;
	std::cout << "Charge: $" << media_2.GetCharge() << std::endl;
	std::cout << "Charge: $" << media_3.GetCharge() << std::endl;
	
	return 0;
}