#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"
#include <sstream>
#include <iostream>

#include <vector>
class Polynomial
{
    public:
        std::vector<Term> terms;
        Polynomial(std::string polynomial);
        Polynomial();
        Polynomial(std::vector<Term> terms);
        Polynomial operator + (const Polynomial &toAdd);
        Polynomial* add(Term toAdd);
        Polynomial operator - (Polynomial toSubtract);
        Polynomial operator - (Term toSubtract);
        void sort();  
        void clearEmpty(); 
        bool isPopulated();
        Polynomial operator * (Term toMultiply);
        static void print(Polynomial poly);
        //Polynomial operator + (Term toAdd);
        Polynomial operator / (Polynomial divisor);
};
#endif


