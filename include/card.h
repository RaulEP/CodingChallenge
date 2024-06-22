#include <iostream>

class Card {

    private: 
        long long card_number;
        // int expire_date;
        // int CVV;
        std::string pin_code;
        long long linked_account;

    public:
        Card();
        Card(long long card_number);
        Card(long long card_number, std::string pin_code);

        bool checkValidCard(long long input);
        bool verifyPin(std::string pin);
        long long getLinkedAccount();
        long long getCardNumber();
};