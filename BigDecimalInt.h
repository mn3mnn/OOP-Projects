//
// Created by DELL on 10/4/2022.
//

#ifndef A1_TASK1_BIGDECIMALINT_H
#define A1_TASK1_BIGDECIMALINT_H
#include <string>
#include <cstring>
#include <regex>
#include <iostream>

using namespace std;


class BigDecimalInt {
    string digits;
    bool is_valid_num(string& str1);
    bool is_positive(string digits);
    BigDecimalInt pos_plus_pos(BigDecimalInt& anotherDec);
    BigDecimalInt pos_minus_pos(BigDecimalInt& anotherDec);

public:
    // constructors
    BigDecimalInt(string decStr){
        if (is_valid_num(decStr)){
            digits = decStr;
        }
        else{
            std::cout << "invalid number";
            exit(1);
        }
    }
    BigDecimalInt(long long decInt) : digits(to_string(decInt)) {}


    // methods
    int size(BigDecimalInt test);
    string sign(BigDecimalInt testForSign);


    // operators overloading
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);

    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);


    friend ostream& operator<< (ostream& out, BigDecimalInt num){
        out << num.digits;
        return out;
    }

};


#endif //A1_TASK1_BIGDECIMALINT_H