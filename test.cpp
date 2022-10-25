#include "BigDecimalInt.h"


using namespace std;

int main(){

    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num3("-200000000000000000000000000000");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    BigDecimalInt num6("-12034965290020210238");
    BigDecimalInt num7("11298614660020210276");
    BigDecimalInt num8("10977508070020210000");
    BigDecimalInt num9("10977508070020210000");
    BigDecimalInt num10 = num6 + num9 ;


    cout<<"Num1 + Num2 = "<<num1 +num2 <<endl;
    cout<<"Num3 - Num7 = "<<num3 -num7 <<endl;
    cout<<"Num4 = "<<num4<<endl;
    cout<<"Num5 = "<<num5<<endl;
    cout<<"Num6 + Num8 = "<<num6 + num8<<endl;
    cout<<"Num10 + Num9 + Num10 = "<<num10 + num9 + num10<<endl;
    if (num8 == num9) {
        cout << "Num8 is == Num9"<<endl;
    }
    if (num1 > num2) {                   // +ve and +ve
        cout << "Num1 > Num2"<<endl;
    }
    if (num6 < num7) {                  // -ve and +ve
        cout << "Num6 < Num7"<<endl;
    }
    if (num3 < num6) {                 // -ve and -ve
        cout << "Num3 < Num6"<<endl;
    }
    cout<<"The Size of Num1 is "<<num1.size()<<endl;
    cout<<"The Sign of Num2 is "<<num2.sign()<<endl;




}


