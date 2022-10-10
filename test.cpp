#include <iostream>
#include "BigDecimalInt.h"

using namespace std;

int main(){

    BigDecimalInt n1 = BigDecimalInt(-20);
    BigDecimalInt n2 = BigDecimalInt("-12345678912345678912345678900");
    BigDecimalInt n3 = n2 + n1;
    BigDecimalInt n4 = n2 + n1 + n1;


    cout << n4 << '\n';
    cout << n1 - n2 << '\n';
    cout << n2 + n1 << '\n';
    cout << n1 + n2 << '\n';
    cout << n3 << '\n';

    cout << n4.sign() << '\n';
    cout << n4.size() << '\n';


}


