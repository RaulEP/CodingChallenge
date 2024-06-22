#include <iostream>
#include <vector>
#include "account.h"

struct CUSTOMER {
    std::string name;
    int initial_deposit;
    std::string account_type;
    std::vector<Card> card_list;
};

class Institution {

    private:
        int institution_code;
        std::string institution_name;
        std::vector<Account> account_list;
        
    public:
        
        Institution();
        Institution(std::string institution_name, int institution_code);

        void insertCustomerData(std::vector<CUSTOMER> customer_list);
        std::vector<Account> getAccountList();
        std::vector<int> getCardNumberList();
        void addAccount(std::string name, int initial_balance, std::string account_type, int account_number, std::vector<Card> account_cards);

};