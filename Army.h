//==============================================
//				Workshop 1
// Student Number: Harsh BharatBhai Khunt
// Email:          hbkhunt1@myseneca.ca
// Student Id:     145227211
// Date:           3/6/22
//==============================================

#ifndef SDDS_ARMY_H
#define SDDS_ARMY_H

namespace sdds {
    const int MAX_NAME_LEN = 50;

    
    class Army {
    private:
        char Nationality[MAX_NAME_LEN];
        int numOfUnits;
        double Power;

    public:
        void setEmpty();

        void createArmy(const char* country, double pow, int troops);

        void updateUnits(int troops);

        const char* checkNationality() const;

        int checkCapacity() const;

        double checkPower() const;

        bool isEmpty() const;

        bool isStrongerThan(const Army& army) const;
    };

    void battle(Army& arm1, Army& arm2);

    void displayDetails(const Army* armies, int size);
}

#endif 