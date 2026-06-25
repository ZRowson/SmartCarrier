//===========================================================================
// File Name : SmartCarrier.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration of SmartCarrier class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260620     1.0         000         Zachary Rowson    Initial version
// 20260621     1.1         001         Zachary Rowson    Implementing functions
// 20250621     1.2         002         Zachary Rowson    Adding helper functions GetPhoneNumber(), CatchCinFail(), and FindAccount()
//===========================================================================

#include "SmartCarrier.h"

const std::string SmartCarrier::DEFAULT_CARRIER_NAME{ "XYZ Wireless" };
const bool SmartCarrier::DEFAULT_INIT{ false };

// constructors and destructor
SmartCarrier::SmartCarrier() :
	carrier_name(SmartCarrier::DEFAULT_CARRIER_NAME),
	init(SmartCarrier::DEFAULT_INIT),
	account_map()
{}
SmartCarrier::SmartCarrier(std::string carrier_name, bool init) :
	carrier_name(carrier_name),
	init(init),
	account_map()
{}
SmartCarrier::~SmartCarrier() {
	std::map<std::string, std::vector<Message<Media>*>>::iterator account_iter;
	std::vector<Message<Media>*>::iterator message_iter;

	for (account_iter = account_map.begin();
			account_iter != account_map.end();
			++account_iter
	) {
		for (message_iter = account_iter->second.begin();
				message_iter != account_iter->second.end();
				++message_iter
		) {
			delete *message_iter;
		}
		account_iter->second.clear();
	}
	account_map.clear();
}

// public methods
bool SmartCarrier::Init() {
    // Account 1 — no messages
    account_map["312-555-9827"];

    // Account 2 — one message
    account_map["714-333-6621"].push_back(new Message<Media>("213-444-5567", Media(45.75)));

    // Account 3 — two messages
    account_map["503-888-2241"].push_back(new Message<Media>("971-222-3345", Media(90.50)));
    account_map["503-888-2241"].push_back(new Message<Media>("503-777-9981", Media(67.33)));

    // Account 4 — three messages
    account_map["206-444-7732"].push_back(new Message<Media>("425-111-8893", Media(534.21)));
    account_map["206-444-7732"].push_back(new Message<Media>("206-999-4456", Media(23.08)));
    account_map["206-444-7732"].push_back(new Message<Media>("360-555-7712", Media(891.44)));

    // Account 5 — four messages
    account_map["602-777-3345"].push_back(new Message<Media>("480-333-6678", Media(345.90)));
    account_map["602-777-3345"].push_back(new Message<Media>("623-888-2234", Media(78.55)));
    account_map["602-777-3345"].push_back(new Message<Media>("602-111-9923", Media(456.12)));
    account_map["602-777-3345"].push_back(new Message<Media>("520-444-5567", Media(234.77)));

	// Account 6 — five messages, one large message at end
    account_map["415-222-8834"].push_back(new Message<Media>("510-666-3321", Media(189.34)));
    account_map["415-222-8834"].push_back(new Message<Media>("415-999-7745", Media(56.89)));
    account_map["415-222-8834"].push_back(new Message<Media>("650-333-4456", Media(34.22)));
    account_map["415-222-8834"].push_back(new Message<Media>("415-777-1123", Media(73.45)));
    account_map["415-222-8834"].push_back(new Message<Media>("408-444-9987", Media(91.67)));

	// Account 7 — six messages, one large message in middle
    account_map["773-555-4423"].push_back(new Message<Media>("312-888-7756", Media(45.33)));
    account_map["773-555-4423"].push_back(new Message<Media>("773-222-3389", Media(67.89)));
    account_map["773-555-4423"].push_back(new Message<Media>("847-666-5512", Media(34.56)));
    account_map["773-555-4423"].push_back(new Message<Media>("773-999-8834", Media(789.01)));
    account_map["773-555-4423"].push_back(new Message<Media>("312-333-7767", Media(23.45)));
    account_map["773-555-4423"].push_back(new Message<Media>("708-777-2245", Media(67.23)));

	// Account 8 — seven messages, one large message at end
    account_map["404-111-6678"].push_back(new Message<Media>("678-444-3312", Media(45.67)));
    account_map["404-111-6678"].push_back(new Message<Media>("404-888-5523", Media(89.12)));
    account_map["404-111-6678"].push_back(new Message<Media>("770-222-9967", Media(56.78)));
    account_map["404-111-6678"].push_back(new Message<Media>("404-555-1134", Media(34.90)));
    account_map["404-111-6678"].push_back(new Message<Media>("678-999-4478", Media(78.34)));
    account_map["404-111-6678"].push_back(new Message<Media>("404-333-8812", Media(23.56)));
    account_map["404-111-6678"].push_back(new Message<Media>("770-666-2289", Media(101.23)));

    // Account 9 — three messages
    account_map["917-888-5534"].push_back(new Message<Media>("212-444-7789", Media(456.78)));
    account_map["917-888-5534"].push_back(new Message<Media>("718-777-3323", Media(234.56)));
    account_map["917-888-5534"].push_back(new Message<Media>("917-222-6645", Media(78.90)));

	// Account 10 — five messages, 3 large messages at beginning, middle, and end
    account_map["305-666-9912"].push_back(new Message<Media>("786-333-4478", Media(567.89)));
    account_map["305-666-9912"].push_back(new Message<Media>("305-999-2256", Media(23.45)));
    account_map["305-666-9912"].push_back(new Message<Media>("954-444-8823", Media(890.12)));
    account_map["305-666-9912"].push_back(new Message<Media>("305-777-3367", Media(45.67)));
    account_map["305-666-9912"].push_back(new Message<Media>("786-111-5589", Media(267.34)));

	return init = true;
}
void SmartCarrier::StartService() {
    if (!init) {
        std::cout << "*** System not initialized. Exiting... ***" << std::endl;
        return;
    }

    do {
        try {
            SmartCarrier::Menu();
            switch (SmartCarrier::GetChoice()) {
            case 1:
                SmartCarrier::ListAccounts();
                break;
            case 2:
                SmartCarrier::InsertMessage();
                break;
            case 3:
                SmartCarrier::PurgeLargeMessages();
                break;
            case 4:
                SmartCarrier::DisconnectAccount();
                break;
            case 5:
                std::cout << "Exiting SmartCarrier service..." << std::endl;
                return;
            default:
                break;
            }
        }
        catch (const AccountNotFoundException& e) {
			std::cout << e.what() << std::endl;
        }
    } while (true);

    return;
}

// private methods
void SmartCarrier::Menu() const {
    std::ios::fmtflags old_flags = std::cout.flags();

    std::string carrier_name_upper = carrier_name;
    for (int i = 0; i < carrier_name.length(); i++) {
        carrier_name_upper[i] = std::toupper(carrier_name[i]);
    }

    const int kMenuWidth = 47;
    const std::string kSubtitle = "ACCOUNT ADMIN";

    std::string name_padding{ "" };
    std::string subtitle_padding{ "" };

    if (carrier_name_upper.length() < kMenuWidth) {
       name_padding = std::string((kMenuWidth - carrier_name_upper.length()) / 2, ' ');
    }
    if (kSubtitle.length() < kMenuWidth) {
        subtitle_padding = std::string((kMenuWidth - kSubtitle.length()) / 2, ' ');
    }

    std::cout <<
		std::left <<
        '\n' << name_padding << carrier_name_upper << '\n' << '\n' <<
        subtitle_padding << kSubtitle << '\n' << '\n' <<
        "1. List all accounts and their messages' usages" << '\n' <<
        "2. Add a message to an account" << '\n' <<
        "3. Purge large messages from an account" << '\n' <<
        "4. Disconnect an account" << '\n' <<
        "5. Quit" <<
        std::endl;

    std::cout.flags(old_flags);

    return;
}
void SmartCarrier::ListAccounts() const {
    std::streamsize old_precision = std::cout.precision();
    std::ios::fmtflags old_flags = std::cout.flags();

    std::cout << std::right << std::fixed << std::setprecision(2);
    std::cout <<
        std::setw(15) << "Account" <<
        std::setw(18) << "Total Messages" <<
        std::setw(25) << "Total Data Usage (MB)" <<
        std::setw(20) << "Total Charge ($)" <<
        std::endl;

	std::map<std::string, std::vector<Message<Media>*>>::const_iterator account_iter;
	std::vector<Message<Media>*>::const_iterator message_iter;

    for (account_iter = account_map.cbegin();
            account_iter != account_map.cend();
            ++account_iter
    ) {
		double total_data_usage{ 0.0 };
		double total_charge{ 0.0 };

        for (message_iter = account_iter->second.cbegin();
                message_iter != account_iter->second.cend();
                ++message_iter
        ) {
			total_data_usage += (*message_iter)->get_message_data().get_size();
			total_charge += (*message_iter)->get_message_data().GetCharge();
        }

        std::cout <<
			std::setw(15) << account_iter->first <<
			std::setw(18) << account_iter->second.size() <<
			std::setw(25) << total_data_usage <<
			std::setw(20) << total_charge <<
			std::endl;
    }

    std::cout.precision(old_precision);
    std::cout.flags(old_flags);

	return;
}
bool SmartCarrier::InsertMessage() {
    double message_size{};
	bool cin_fail{ false };

    std::cout << "Please provide the account's phone number: ";
    std::string account_number{ SmartCarrier::GetPhoneNumber() };

    std::map<std::string, std::vector<Message<Media>*>>::iterator account_iter{
        SmartCarrier::FindAccount(account_number)
    };

	std::cout << "Please provide a message size (MB): ";
	std::cin >> message_size;
	if (SmartCarrier::CatchCinFail()) {
		std::cout << "*** invalid input ***" << std::endl;
		return false;
	}

	std::cout << "Please provide the recipient's phone number: ";
    std::string message_to{ SmartCarrier::GetPhoneNumber() };

	account_iter->second.push_back(
        new Message<Media>(message_to, Media(message_size))
    );
    
	return true;
}
void SmartCarrier::PurgeLargeMessages() {
    std::streamsize old_precision = std::cout.precision();
    std::ios::fmtflags old_flags = std::cout.flags();
    
    double total_data_purged{ 0.0 };
    
    std::cout << "Please provide the account's phone number: ";
    std::string account_number{ SmartCarrier::GetPhoneNumber() };

    std::map<std::string, std::vector<Message<Media>*>>::iterator account_iter{
        SmartCarrier::FindAccount(account_number)
    };

    std::vector<Message<Media>*>::iterator message_iter{ account_iter->second.begin() };
    while (message_iter != account_iter->second.end()) {
        double message_size = (*message_iter)->get_message_data().get_size();
		if (message_size > Media::SIZE_THRESHOLD) {
            delete *message_iter;
			message_iter = account_iter->second.erase(message_iter);
            total_data_purged += message_size;
		}
		else {
			++message_iter;
		}
    }

    std::cout << std::fixed << std::setprecision(2);
	std::cout << "Total data purged: " << total_data_purged << " MB" << std::endl;
	
    std::cout.precision(old_precision);
    std::cout.flags(old_flags);

    return;
}
bool SmartCarrier::DisconnectAccount() {
    std::cout << "Please provide the account's phone number: ";
    std::string account_number{ SmartCarrier::GetPhoneNumber() };

    std::map<std::string, std::vector<Message<Media>*>>::iterator account_iter{
        SmartCarrier::FindAccount(account_number)
    };

	std::vector<Message<Media>*>::iterator message_iter{};
    for (message_iter = account_iter->second.begin();
            message_iter != account_iter->second.end();
            ++message_iter
    ) {
        delete* message_iter;
    }
	account_map.erase(account_iter);

    return true;
}

// input handling helper functions
int SmartCarrier::GetChoice() const {
    int user_option{};
    bool cin_fail{ false };

    std::cout << "\nSelect an option (1-5): ";
    std::cin >> user_option;
    std::cout << std::endl;

    cin_fail = SmartCarrier::CatchCinFail();

    if (user_option > 5 || user_option < 1 || cin_fail) {
        std::cout << "*** please select an integer 1-5 ***" << std::endl;
        return -1;
    }

    return user_option;
}
std::string SmartCarrier::GetPhoneNumber() const {
    std::string phone_number{};
    std::getline(std::cin, phone_number);
    return phone_number;
}
bool SmartCarrier::CatchCinFail() const {
    bool cin_fail{ false };
    if (cin_fail = std::cin.fail()) {
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return cin_fail;
}

// helpers to reduce code duplication
std::map<std::string, std::vector<Message<Media>*>>::iterator
    SmartCarrier::FindAccount(const std::string& account_number)
{
    std::map<std::string, std::vector<Message<Media>*>>::iterator account_iter{
        account_map.find(account_number)
    };

    if (account_iter == account_map.end()) {
        throw AccountNotFoundException(account_number);
    }

    return account_iter;
}