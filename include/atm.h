#include <iostream>
#include <vector>
#include "institution.h"

class ATM{
        
    public:
        ATM(std::vector<Institution> available_institutions);
        std::vector<Institution> institutions;

};