//
// Created by DELL on 10/4/2022.
//

#include "BigDecimalInt.h"


string BigDecimalInt::validate_str(string str1){

        // Chech the string have any Letters 
        for (size_t i = str1.size() - 1 ; i <= 0; i--)
        {
            if (str1[i] > '9' || str1[i] < '0'){
                cout<<"Your BigDecimalInt is unvalid\nPlease check your BigDecimalInt and be careful when you enter it not to try again.";
                return 0;
            }
        }
    return str1;
    }


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){
        
    // anotherDec.digits = the longest number
    if (digits.size() > anotherDec.digits.size()){
        swap(digits,anotherDec.digits);
    }

    int j = digits.size() - 1;
    for (size_t i = anotherDec.digits.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        // tmp = the sum of the two numbers
        int tmp = (anotherDec.digits[i]-'0') + (digits[j]-'0');

        // store last digit of tmp in the longest number
        anotherDec.digits[i] = ((tmp % 10) + '0');

        if(tmp > 9){
            // add one to the prev digit
            anotherDec.digits[i-1] = ((anotherDec.digits[i-1]-'0') + 1) + '0';
        } 
    }
    // return the longest number
    return anotherDec;
}



BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
    // anotherDec.digits = the longest number
    if (digits.size() > anotherDec.digits.size())
    {
        swap(digits,anotherDec.digits);
    }

    int j = digits.size() - 1;
    for (size_t i = anotherDec.digits.size() - 1; i >= 0 && j >=0; i--, j--)
    {
        // tmp = difference between the two digits
        int tmp = (anotherDec.digits[i]-'0') - (digits[j]-'0');

        // if the difference is positive
        if (tmp < 0){
            // borrow one from the prev digit
            anotherDec.digits[i - 1] = ((anotherDec.digits[i - 1]-'0') - 1) + '0';
            // tmp2 = 10 + the small digit
            int tmp2 = ((anotherDec.digits[i]-'0') + 10);
            // store the difference in curr digit in the longest number
            anotherDec.digits[i] = (tmp2 - (digits[j]-'0')) + '0';
        }
        else{
            // if the difference is positive
            anotherDec.digits[i] = (tmp + '0');
        }
    }
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




