#include <iostream>
#include "atm.h"

int main() {

    //TEST DATABSE CASES
    std::vector<CUSTOMER> customer_list;

    CUSTOMER customer1 = {"oliver", 500, "savings", std::vector<Card> {Card(6682805795962558, "1234")}};
    CUSTOMER customer2 = {"kim"   , 200, "savings", std::vector<Card> {Card(2973208582578615, "4321")}};
    CUSTOMER customer3 = {"bear"  , 100, "savings", std::vector<Card> {Card(5729530215776072, "5421")}};
    CUSTOMER customer4 = {"adolfo", 0  , "savings", std::vector<Card> {Card(2094410478141323, "9876")}};

    customer_list.push_back(customer1);
    customer_list.push_back(customer2);
    customer_list.push_back(customer3);
    customer_list.push_back(customer4);

    bool accounts_initialized = false;

    std::vector<Institution> institutions_list = {Institution("bear robotics", 0001)};
    ATM atm_controller(institutions_list);

    Institution BearRoboticsATM = atm_controller.institutions[0];

    std::cout << "Welcome to Bear Robotics ATM "<< std::endl;
    std::cout << " " << std::endl;
    if (!accounts_initialized) {
        // create accounts
        BearRoboticsATM.insertCustomerData(customer_list);
        accounts_initialized = true;
        std::cout << "Customer Database for Bear Robotics was succesfully loaded" << std::endl;
        
    }

    std::vector<Account> account_list = BearRoboticsATM.getAccountList();

    long long input_card_number;
    std::cout << " " << std::endl;
    std::cout << "Insert your 16-digit card number" << std::endl;
    std::cin >> input_card_number;
    // Insert Card
    
    int account_number = 0;
    Card matched_card;
    for (int i = 0; i < account_list.size(); i++) {

        matched_card = account_list[i].findCard(input_card_number);
        if (matched_card.getCardNumber() == 0) {
            continue;
        }
        else {
            std::cout << "Card Number: " << matched_card.getCardNumber() << std::endl;
            account_number = i;
            break;
        }
    }

    std::string pin_code;
    bool result = false;
    int count = 0;
    while(result == false) {
        
        if (count >= 3) {
            std::cout << "You excedeed the amount of attempts" << std::endl;
            break;
        }
        
        std::cout << "Input your 4-digit PIN code: " << std::endl;
        std::cin >> pin_code;
        result = matched_card.verifyPin(pin_code);
    
        if(result == true) {
    
            std::cout << "Welcome customerName: " << account_list[account_number].getCustomerName() << std::endl;
            
            int option;
            int account_option = 0;
            int cash;
            bool exit = false;

            while(exit == false) {

                if (account_option == 0) {

                    std::cout << "Select your Account" << std::endl;
                    std::cout << "  1. Savings " << std::endl;
                    std::cin >> account_option;

                    if (account_option !=  1) {
                        std::cout << " " << std::endl;
                        std::cout << "Invalid option - Choose One Option From the Menu" << std::endl;
                        account_option = 0;
                        continue;
                    }
                    
                }

                std::cout << "Choose one option(input only numbers)" << std::endl;
                std::cout << "  1. See Account Balance " << std::endl;
                std::cout << "  2. Deposit " << std::endl;
                std::cout << "  3. Withdraw " << std::endl;
                std::cout << "  4. Exit " << std::endl;
                std::cin >> option;

                if (option == 1) {
                    std::cout << " " << std::endl;
                    std::cout << "Account Balance: " << account_list[account_number].getAccountBalance() << std::endl;
                }
                else if (option == 2) {
                    std::cout << " " << std::endl;
                    std::cout << "How much money you like to deposit(Only enter whole numbers)" << std::endl;
                    std::cin >> cash;
                    account_list[account_number].depositCash(cash);
                    std::cout << "Cash Deposited Succesfully" << std::endl;
                }
                else if (option == 2) {
                    std::cout << " " << std::endl;
                    std::cout << "How much money you like to deposit(Only enter whole numbers)" << std::endl;
                    std::cin >> cash;
                    account_list[account_number].depositCash(cash);
                    std::cout << "Cash Deposited Succesfully" << std::endl;
                }
                else if (option == 3) {
                    std::cout << " " << std::endl;
                    std::cout << "How much money you like to withdraw(Only enter whole numbers)" << std::endl;
                    std::cin >> cash;
                    account_list[account_number].withdrawCash(cash);
                    std::cout << "Cash Withdraw Succesfully" << std::endl;
                }
                else if (option == 4) {
                    std::cout << " " << std::endl;
                    std::cout << "Exit Menu" << std::endl;
                    exit = true;
                    break;
                }
                else {
                    std::cout << " " << std::endl;
                    std::cout << "Invalid option - Choose One Option From the Menu" << std::endl;
                }

                option = 0;
            }

        }
        count++;
    }

    return 0;
}
