## Requirements
At least the following flow should be implemented:

Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.

Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code. Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.

Based on your work, another engineer should be able to implement the user interface. You don't need to implement any REST API, RPC, network communication etc, but just functions/classes/methods, etc.

You can simplify some complex real world problems if you think it's not worth illustrating in the project.

## How to submit
Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository. Please attach the test code(or Test Case), too.

## Instructions to Run this Project

#### To clone this repository
```
 git clone https://github.com/RaulEP/CodingChallenge.git
```

This project can be build using Cmake

#### To build this project go to root directory
```
cd CodingChallenge
```
#### create build folder
```
mkdir build
cd build
```

#### build the project
```
cmake ..
make
```

#### Now go to executable directory and run:
```
cd bin
./atm_controller
```

## Test Project

Everytime you Run this project, the ATM System loads a mock customer database with the following data:

Customer Name | Balance | Account Type | Card Number | PIN |
|----------|----------|----------|----------|----------|
oliver     | 500   | savings    | 6682805795962558   | 1234   |
kim        | 200   |  savings    | 2973208582578615   | 4321   |
bear       | 100   | savings    | 5729530215776072   | 5421   |
adolfo     | 0   | savings    | 2094410478141323   | 9876   |

You can use this data to interact with the different options in the ATM to Test its perfomance.