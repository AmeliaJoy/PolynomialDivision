#include "Polynomial.h"

bool compare(Term a, Term b)
{
    return a.power > b.power;
}
void Polynomial::sort()
{
    std::sort(terms.begin(),terms.end(),compare);
}
bool Polynomial::isPopulated()
{
    return terms.size() != 0;
}
void Polynomial::clearEmpty()
{
    for(int i = 0; i < terms.size(); i++)
    {
        if(terms.at(i).coefficient == 0)
        {
            terms.erase(terms.begin()+i);
        }
    }
}
Polynomial Polynomial::operator / (Polynomial divisor)
{
    Polynomial workingDividend(*this);
    Polynomial workingDivisor(divisor);
    Polynomial quotient;
    Term factor(0,0);
    while(workingDividend.isPopulated() && workingDivisor.isPopulated() && workingDividend.terms.at(0).power >= divisor.terms.at(0).power)
    {
        factor = workingDividend.terms.at(0) / divisor.terms.at(0);
        workingDivisor = divisor * factor;
        workingDividend = workingDividend - workingDivisor;
        quotient.add(factor);
    }
    return quotient;
}
Polynomial Polynomial::operator - (Polynomial toSubtract)
{
    Polynomial difference(*this);
    for(int i = 0; i < toSubtract.terms.size();i++)
    {
        difference = difference - toSubtract.terms.at(i);
    }
    difference.clearEmpty();
    difference.sort();
    return difference;
}
Polynomial Polynomial::operator - (Term toSubtract)
{
    Polynomial difference(*this);
    for(int i = 0; i < difference.terms.size(); i++)
    {
        if(difference.terms.at(i).power == toSubtract.power)
        {
            difference.terms.at(i).coefficient -= toSubtract.coefficient;
            return difference;
        }
    }
    toSubtract.coefficient = -toSubtract.coefficient;
    difference.terms.push_back(toSubtract);
    
    return difference;
}
Polynomial Polynomial::operator * (Term toMultiply)
{
    Polynomial product(*this);
    for(int i = 0; i < product.terms.size(); i++)
    {
        product.terms.at(i) = product.terms.at(i) * toMultiply;
    }
    return product;
}

Polynomial Polynomial::operator + (const Polynomial &toAdd)
{
    Polynomial sum(*this);
    for(int i = 0; i < toAdd.terms.size();i++)
    {
        sum.add(toAdd.terms.at(i));
    }
    sum.clearEmpty();
    sum.sort();
    return sum;
}
Polynomial* Polynomial::add(Term toAdd)
{
    for(int i = 0; i < terms.size(); i++)
    {
        if(terms.at(i).power == toAdd.power)
        {
            terms.at(i).coefficient += toAdd.coefficient;
            return this;
        }
    }
    terms.push_back(toAdd);

    return this;
}
Polynomial::Polynomial(std::string polynomial)
{
   int start, end = -1;
    do {
        start = end + 1;
        end = std::min(polynomial.find('+', start),polynomial.find('-', start));
        if(end == -1)
            end = std::max(polynomial.find('+', start),polynomial.find('-', start));
        std::string termStr = polynomial.substr(start, end - start);
        bool sign = start - 1 < 0 ? true : (polynomial.at(start-1) =='-'?false:true);
        add(Term(termStr, sign));
    } while (end != -1);
}
Polynomial::Polynomial(std::vector<Term> newTerms)
{
    terms = newTerms;
    std::sort(terms.begin(),terms.end(),compare);
}
Polynomial::Polynomial()
{ 
}


 void Polynomial::print(Polynomial poly)
{
    if(poly.terms.size() == 0)
        return;
    std::cout << (poly.terms.at(0).coefficient < 0?"-":"") << abs(poly.terms.at(0).coefficient) << "x^"<<poly.terms.at(0).power;
    for(int i = 1; i < poly.terms.size(); i++)
    {
       std::cout << (poly.terms.at(i).coefficient < 0 || i == 0?" - ":" + ") << abs(poly.terms.at(i).coefficient) << "x^"<<poly.terms.at(i).power;
    }
    std::cout << std::endl;
}