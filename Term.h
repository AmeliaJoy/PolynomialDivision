#ifndef TERM_H
#define TERM_H
#include <iostream>
#include <algorithm>
class Term
{   
    public:
        double coefficient;
        int power; 
        Term(std::string termName, bool sign);
        Term operator / (Term divisorTerm);
        Term operator * (Term toMultiply);
        Term(double coefficient, int power);
        Term();
        static void print(Term term);
        void set(double coefficient, int power);
};
#endif


