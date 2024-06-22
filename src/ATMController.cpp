#include <iostream>
#include "atm.h"

std::vector<CUSTOMER> customer_list;

//ACCOUNT
Account::Account(std::string name, int initial_balance, std::string type, int institutional_code, int account_number, std::vector<Card> account_cards) {
    customer_name = name;
    balance = initial_balance;
    account_type = type;

    account_number = account_number;
    institution_code = institutional_code;

    for (int i = 0; i < account_cards.size(); i++) {
        linked_cards.push_back(account_cards[i]);
    }
}

int Account::getAccountBalance() {
    return balance;
}

int Account::getAccountNumber() {
    return account_number;
}

std::string Account::getCustomerName() {
    return customer_name;
}

std::string Account::getAccountType() {
    return account_type;
}

std::vector<Card> Account::getLinkedCards() {
    return linked_cards;
}


void Account::depositCash(int cash) {
    balance = balance + cash;
}

bool Account::withdrawCash(int cash) {
    if (cash > balance) {
        std::cout << "Not Enough Balance, Can't Withdraw" << std::endl;
        return false;
    }
    balance = balance - cash;
}

Card Account::findCard(long long input_card_number) {

    for(int card_id = 0; card_id < linked_cards.size(); card_id++) {
        long long card_number = linked_cards[card_id].getCardNumber();
        // std::cout << "card_number " <<  card_number << std::endl;
        // std::cout << "input_number " <<  input_card_number << std::endl;
        if (card_number == input_card_number) {
            Card matched_card = linked_cards[card_id];
            std::cout << "Card Found on Database" << std::endl;
            return matched_card;
        }
    }
    
    return Card(0);
    
}

//CARD
Card::Card() {
    
}

Card::Card(long long number) {
    bool is_valid = checkValidCard(card_number);
    if (is_valid == true) {
        card_number = number;
    }
}

Card::Card(long long number, std::string code) {
    bool is_valid = checkValidCard(card_number);
    if (is_valid == true) {
        card_number = number;
        pin_code = code;
    }
}

bool Card::checkValidCard(long long card_number){
    if (std::to_string(card_number).length() > 14) { //rounding sometimes makes it 16 or 15 digit
        return true;
    }
    else {
        std::cout << "Card Number Invalid! Enter a 16-digit Card Number! "<< std::endl;
        return false;
    }
        
}

bool Card::verifyPin(std::string input) {
    if(input.length() == 4 && input == pin_code) {
        std::cout << "Correct Pin"  << std::endl;
        return true;
    }
    else {
        std::cout << "Incorrect Pin" << std::endl;
        return false;
    }
}

long long Card::getLinkedAccount() {
    return linked_account;
}

long long Card::getCardNumber() {
    return card_number;
}

//Institution (BEAR ROBOTICS)
Institution::Institution() {
    institution_name = "Bear Robotics";
    institution_code = 1;
}

Institution::Institution(std::string name, int code) {
    institution_name = name;
    institution_code = code;
}

void Institution::insertCustomerData(std::vector<CUSTOMER> customer_list) {

    int account_number = customer_list.size() + 1;
    for(int customer_id = 0; customer_id < customer_list.size(); customer_id++) {
        CUSTOMER customer = customer_list[customer_id];
        addAccount(customer.name, customer.initial_deposit, customer.account_type, account_number, customer.card_list);
        account_number = account_number + 1;
    }

}

void Institution::addAccount(std::string name, int initial_balance, std::string account_type, int account_number, std::vector<Card> account_cards) {
    Account account(name, initial_balance, account_type, institution_code, account_number, account_cards);
    account_list.push_back(account);
}

std::vector<Account> Institution::getAccountList(){
    return account_list;
}

ATM::ATM(std::vector<Institution> available_institutions) {
    
    for (int i = 0; i < available_institutions.size(); i++) {
        institutions.push_back(available_institutions[i]);
    }
}