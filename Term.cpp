#include "Term.h"
Term::Term(double coefficient, int power)
{
    this->coefficient = coefficient;
    
    this->power = power;
}
void Term::set(double coefficient, int power)
{
    this->coefficient = coefficient;
    this->power = power;
}
Term Term::operator/(Term divisorTerm)
{
    Term quotient;
    quotient.coefficient = this->coefficient / divisorTerm.coefficient;
    quotient.power = this->power - divisorTerm.power;
    return quotient;
}
Term Term::operator * (Term toMultiply)
{
    Term product;
    product.coefficient = this ->coefficient * toMultiply.coefficient;
    product.power = this->power + toMultiply.power;
    return product;
}
Term::Term()
{

}
Term::Term(std::string termName, bool sign)
{
    std::string::iterator end_pos = std::remove(termName.begin(), termName.end(), ' ');
    termName.erase(end_pos, termName.end());
    std::string coeffString;
    std::string powerString;
    int start, end = -2;
    int i = -1;
    do {
        i++;
        start = end + 2;
        end = termName.find("x^", start);
        std::string termStr = termName.substr(start, end - start);
        if(i == 0)
            coeffString = termStr.length() == 0? "1":termStr;
        else
        {
            powerString = termStr;
        }
        
    } while (end != -1);
    if(powerString == "")
    {
        if(coeffString.find('x') == -1)
        {
            powerString = '0';
        }
        else if (coeffString.find('x') == 0)
        {
            powerString = '1';
            coeffString ='1';
        }
        else
        {
            powerString = '1';
            coeffString =coeffString.substr(0,coeffString.find('x'));
        }     
    }

    power = std::stoi(powerString);
    coefficient = std::stoi(coeffString);
    coefficient *= sign?1:-1;

    
}
void Term::print(Term term)
{
    std::cout<<term.coefficient<<"x^"<<term.power << std::endl;
    
}