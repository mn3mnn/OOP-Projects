//
// Created by DELL on 10/4/2022.
//

#ifndef A1_TASK1_BIGDECIMALINT_H
#define A1_TASK1_BIGDECIMALINT_H
#include <string>
#include<iostream>

using namespace std;


class BigDecimalInt {
    string digits;

public:
    // constructors
    BigDecimalInt(string& decStr){
        digits = validate_str(decStr);
    }
    BigDecimalInt(int& decInt) : digits(to_string(decInt)) {}

    // take valid bigInt string
    string validate_str(string str1);

    // operators overloading
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);

    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);

    int size();
    int sign();

   friend ostream& BigDecimalInt::operator<< (ostream& out, BigDecimalInt num){
        out << num.digits;
        return out;
    }

};


#endif //A1_TASK1_BIGDECIMALINT_H
