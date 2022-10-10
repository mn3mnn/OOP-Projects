
#include "BigDecimalInt.h"

//-------------------------------------------------------------------------------------------------------------------//


bool BigDecimalInt::is_valid_num(string& str1){
    regex valid_num_reg;
    valid_num_reg = "^(\\-|\\+)?[0-9]{1,}$";

    if (!regex_match(str1, valid_num_reg)){
        return false;
    }
    return true;
}


bool BigDecimalInt::is_positive(string digits){
    return digits[0] != '-';
}

//-------------------------------------------------------------------------------------------------------------------//


// return the sum of two positive nums
BigDecimalInt BigDecimalInt::pos_plus_pos(BigDecimalInt& anotherDec){
    // store this->digits in tmp_dig
    string tmp_dig = digits;

    // make anotherDec.digits = the longest number (the result)
    if (tmp_dig.size() > anotherDec.digits.size()){
        swap(tmp_dig,anotherDec.digits);
    }

    int j = tmp_dig.size() - 1;
    for (size_t i = anotherDec.digits.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        // tmp = the sum of the two digits

        int tmp = (anotherDec.digits[i]-'0') + (tmp_dig[j]-'0');

        // store last digit of tmp in the longest number (the result)
        anotherDec.digits[i] = ((tmp % 10) + '0');

        if(tmp > 9){
            if (i == 0){
                // example: "500 + 500" , here we need to add extra digit
                anotherDec.digits.insert(0, 1, '1');
            }
            else{
                // add one to the prev digit
                anotherDec.digits[i-1] = ((anotherDec.digits[i-1]-'0') + 1) + '0';
            }
        }
    }
    // return the sum
    return anotherDec;
}


// return the abs value of the difference between two pos numbers
BigDecimalInt BigDecimalInt::pos_minus_pos(BigDecimalInt& anotherDec){

    // anotherDec.digits =  the 'greatest' number
    anotherDec.digits = (stoull(anotherDec.digits) > stoull(digits) ? anotherDec.digits : digits);

    int j = digits.size() - 1;
    for (size_t i = anotherDec.digits.size() - 1; i >= 0 && j >=0; i--, j--)
    {
        // tmp = difference between the two digits
        int tmp = (anotherDec.digits[i]-'0') - (digits[j]-'0');

        // if the difference is positive
        if (tmp < 0){
            int k = i - 1;
            while (anotherDec.digits[k] == '0'){
                // if we borrow 1 from digit that is equal to zero, make it 9 and borrow 1 from the prev digit

                anotherDec.digits[k] = (anotherDec.digits[k] == '0' ? '9' : anotherDec.digits[k]--);
                k--;
            }
            // borrow one from the prev digit
            anotherDec.digits[k] = ((anotherDec.digits[k]-'0') - 1) + '0';

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
    // remove zeros to the left
    int i = 0;
    while (anotherDec.digits[i++] == '0'){
        anotherDec.digits.erase(0, 1);
    }
    return anotherDec;
}

//-------------------------------------------------------------------------------------------------------------------//


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){
    
    // if pos + pos
    if (is_positive(digits) && is_positive(anotherDec.digits)){
        // remove +ve sign if it's found
        if (digits[0] == '+'){
            digits.erase(0, 1);
        }
        if (anotherDec.digits[0] == '+'){
            anotherDec.digits.erase(0, 1);
        }
        // add the two nums
        anotherDec = pos_plus_pos(anotherDec);
    }
    
    // if negative + negative
    else if(!is_positive(digits) && !is_positive(anotherDec.digits)){
        // remove -ve sign
        digits.erase(0, 1);
        anotherDec.digits.erase(0, 1);
        // add the 2 nums
        anotherDec = pos_plus_pos(anotherDec);
        // add -ve sign to the result
        anotherDec.digits.insert(0, 1, '-');
    }

    // if we add numbers with different signs
    else if (is_positive(digits) && !is_positive(anotherDec.digits)){
        // anotherDec.digits = the difference between the two nums
        // add the sign of the greater number (abs value)  to the result (anotherDec.digits)
        char sign = (abs(stoll(anotherDec.digits)) > abs(stoll(digits)) ? anotherDec.digits[0] : digits[0]);
        anotherDec.digits.erase(0, 1);
        anotherDec = pos_minus_pos(anotherDec);
        if (sign == '-' && anotherDec.digits != "0"){
            anotherDec.digits.insert(0, 1, '-');
        }
    }

    // if we add numbers with different signs
    else if (!is_positive(digits) && is_positive(anotherDec.digits)){
        // anotherDec.digits = the difference between the two nums
        // add the sign of the greater number to the result (anotherDec.digits)
        char sign = (abs(stoll(anotherDec.digits)) > abs(stoll(digits)) ? anotherDec.digits[0] : digits[0]);
        digits.erase(0, 1);
        anotherDec = pos_minus_pos(anotherDec);
        if (sign == '-' && anotherDec.digits != "0"){
            anotherDec.digits.insert(0, 1, '-');
        }
    }

    return anotherDec;
}


BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){

    return anotherDec;
}


//-------------------------------------------------------------------------------------------------------------------//


BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec){
    digits = anotherDec.digits;
    return digits;
}


//-------------------------------------------------------------------------------------------------------------------//


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
    return false;
}


//-------------------------------------------------------------------------------------------------------------------//


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
    return false;
}


//-------------------------------------------------------------------------------------------------------------------//


bool BigDecimalInt::operator== (BigDecimalInt anotherDec){
    if (strcmp(anotherDec.digits.c_str(), digits.c_str()) == 0) {
        return true;
    }
    return false;
}


//-------------------------------------------------------------------------------------------------------------------//


int BigDecimalInt::size(BigDecimalInt test) {
    string str_tmp = test.digits;
    return str_tmp.size();
}


//-------------------------------------------------------------------------------------------------------------------//

string BigDecimalInt::sign(BigDecimalInt testForSign){
    string str_temp = testForSign.digits;
    if(str_temp[0] == '-'){return "Signed Negative";}
    else {return "Signed Positive";}
}
