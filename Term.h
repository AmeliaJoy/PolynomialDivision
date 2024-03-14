#ifndef TERM_H
#define TERM_H
#include <iostream>
#include <algorithm>
class Term
{   friend class Polynomial;
    private:
        double coefficient;
        int power; 
    public:
        
        Term(std::string termName, bool sign);
        int getPower();
        Term operator / (const Term& divisorTerm) const;
        Term operator * (const Term& toMultiply) const;
        Term(double coefficient, int power);
        Term();
        static void print(Term term);
        void set(double coefficient, int power);
};
#endif


