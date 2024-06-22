#include <iostream>
#include <string>
#include <vector>
#include <card.h>

class Account {

    private: 
        std::string customer_name;
        std::string account_type;
        int account_number;
        int balance;
        int institution_code;
        
        std::vector<Card> linked_cards;

    public:

        Account(std::string customer_name, int initial_balance, std::string account_type, int institution_code, int account_number, std::vector<Card> account_cards);

        std::string getAccountType();
        int getAccountBalance();
        int getAccountNumber();
        std::string getCustomerName();
        std::vector<Card> getLinkedCards();

        Card findCard(long long input_card_number);
        void depositCash(int cash);
        bool withdrawCash(int cash);
        
};