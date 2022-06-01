//==============================================
//				Workshop 1
// Student Number: Harsh BharatBhai Khunt
// Email:          hbkhunt1@myseneca.ca
// Student Id:     145227211
// Date:           3/6/22
//==============================================

#include "Army.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace sdds {

    
    void Army::setEmpty() 
    {
        strcpy(Nationality, "");
        numOfUnits = 0;
    }

    void Army::createArmy(const char* country, double pow, int troops) {
        if (country != nullptr && country[0] != '\0' && troops > 0 && pow > 0) {
            strncpy(Nationality, country, MAX_NAME_LEN);
            this->numOfUnits = troops;
            this->Power = pow;
        }
        else {
            Nationality[0] = '\0';
            numOfUnits = 0;
            Power = 0;
        }
    }

    void Army::updateUnits(int troops) {
        numOfUnits += troops;
        Power += 0.25 * troops;
    }

   
    const char* Army::checkNationality() const {
        return Nationality;
    }

    
    int Army::checkCapacity() const {
        return numOfUnits;
    }

    double Army::checkPower() const 
    {
        int check_power;
        check_power = Power;
        return check_power;
    }

    bool Army::isEmpty() const {
        bool result = false;
        if (strcmp(Nationality, "") == 0 && numOfUnits == 0) {
            result = true;
        }

        return result;
    }

   
    bool Army::isStrongerThan(const Army& army) const {
        bool result = false;

        if (Power > army.Power) {
            result = true;
        }

        return result;
    }

    
    void battle(Army& arm1, Army& arm2) {
  
        if ((strcmp(arm1.checkNationality(), "") != 0 && arm1.checkCapacity() != 0) && (strcmp(arm2.checkNationality(), "") != 0 && arm2.checkCapacity() != 0)) {
            Army winner;

            if (arm1.isStrongerThan(arm2)) {
                arm2.updateUnits((int)(0.5 * (0 - arm2.checkCapacity()))); 
                winner = arm1;

            else {
                arm1.updateUnits((int)(0.5 * (0 - arm1.checkCapacity()))); 
                winner = arm2; 
            }

           
            cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", "
                << winner.checkNationality() << " is victorious!" << endl;
        }
    }

   
    void displayDetails(const Army* armies, int size) {
        int i;
        cout << "Armies reporting to battle: " << endl;

        for (i = 0; i < size; i++) {
            if (strcmp(armies[i].checkNationality(), "") != 0 && armies[i].checkCapacity() != 0) {

        
                cout.setf(ios::fixed);
                cout.precision(1);

         
                cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << armies[i].checkPower() << endl;
            }
        }
    }
} 