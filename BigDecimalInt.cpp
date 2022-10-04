//
// Created by DELL on 10/4/2022.
//

#include "BigDecimalInt.h"

string BigDecimalInt::validate_str(string& str1){
    return str1;
}


BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec){
    return anotherDec;
}


BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
    return anotherDec;
}


BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec){
    return anotherDec;
}


bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
    return true;
}


bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
    return true;
}


bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    return true;
}


int BigDecimalInt::size() {
    return digits.size();
}


int BigDecimalInt::sign() {
    return 1;
}


friend ostream& BigDecimalInt::operator<< (ostream& out, BigDecimalInt b){
    return out;
}

