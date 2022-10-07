//
// Created by DELL on 10/4/2022.
//

#include "BigDecimalInt.h"

void BigDecimalInt::num1PlusNum2(BigDecimalInt &anotherDec){

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
}

// in case that i want to make number1 - number2 (number1 is the bigger )
void BigDecimalInt::num1MinusNum2(BigDecimalInt &anotherDec){

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
}

string BigDecimalInt::validate_str(string str1){
    if (!(str1[0] == '+' || str1[0] == '-' || (str1[0] < '9' && str1[0] > '0'))){
        cout<<"Your BigDecimalInt is unvalid\nPlease check your BigDecimalInt and be careful when you enter it not to try again.";
        return 0;
    }

    // Chech the string have any Letters 
    for (size_t i = 1; i < str1.size(); i++)
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
        
    // add two positive numbers
    if(signPositive(anotherDec.digits) && signPositive(digits)){
        num1PlusNum2(anotherDec);
    }
    // add two negative numbers
    else if (!signPositive(anotherDec.digits)  && !signPositive(digits)){
        digits.erase(0,1);
        anotherDec.digits.erase(0,1);
        anotherDec.digits.insert(0,"-");
        num1PlusNum2(anotherDec);
    }
    // add positive number to negative number (positive number is the smaller) 
    else if (!signPositive(anotherDec.digits)  && signPositive(digits)){
        anotherDec.digits.erase(0,1);
        anotherDec.digits.insert(0,"-");
        num1MinusNum2(anotherDec);
    }
    // add postive number to negative number (positive number is the bigger)
    else if (signPositive(anotherDec.digits)  && !signPositive(digits)){
        digits.erase(0,1);
        num1MinusNum2(anotherDec);
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

//not done (- and + case)
bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
	if (digits.size() < anotherDec.digits.size()) {
        return true;
    }
	else if (digits.size() == anotherDec.digits.size()) {
        int COMP = digits.compare(anotherDec.digits);
        if (COMP == 0) {
            return false;   //strings are uqual
        }
	    else if (COMP < 0) {
            return true;   
        }
		else if (COMP > 0){
            return false;   //string 1 is bigger
        }
	}	
    // else if () {
	// 	"for - and +"
	// }
    return false;
}

//not done (- and + case)
bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
	if (digits.size() > anotherDec.digits.size()) {
        return true;
    }
	else if (digits.size() == anotherDec.digits.size()) {
        int COMP = digits.compare(anotherDec.digits);
        if (COMP == 0) {
            return false;   //strings are uqual
        }
	    else if (COMP < 0) {
            return false;   //string 1 is smaller
        }
		else if (COMP > 0){
            return true;   
        }
	}	
    // else if () {
	// 	"for - and +"
	// }
    return false;
}


bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    if (strcmp(anotherDec.digits.c_str(), digits.c_str()) == 0) {
        return true;
    }
	else {
		return false;
	}
    return false;
}


int BigDecimalInt::size() {
    return digits.size();
}


bool BigDecimalInt::signPositive(string temp_str){
    if(temp_str[0] == '-'){return false;}
    else {return true;}
}

ostream& operator<< (ostream& out, BigDecimalInt num){
    out << num.digits;
    return out;
}



