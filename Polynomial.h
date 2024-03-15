#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "Term.h"
#include <sstream>
#include <iostream>

#include <vector>
class Polynomial
{
    private:
        std::vector<Term> terms;
        Polynomial* add(const Term &toAdd);
        void sort();
        void clearEmpty(); 
    public:
        Polynomial(std::string polynomial);
        Polynomial();
        Polynomial(std::vector<Term> terms);
        Polynomial operator + (const Polynomial &toAdd) const;
        
        Polynomial operator - (const Polynomial& toSubtract) const;
        Polynomial operator - (Term toSubtract) const;
        Polynomial operator * (const Term & toMultiply) const;
        Polynomial operator * (const Polynomial & toMultiply) const;
        bool isPopulated() const;
        static void print(const Polynomial& poly);
        Polynomial operator + (const Term& toAdd) const;
        Polynomial operator / (const Polynomial& divisor) const;
        Polynomial operator % (const Polynomial& divisor) const;
};
#endif


