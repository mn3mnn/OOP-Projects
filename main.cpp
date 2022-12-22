#include <iostream>
#include <vector>
#include "EAVector.h"

using namespace std;

int main() {

    EAVector<int> myVec(6);
    EAVector<int> myVEC(6);
    for(int i=1; i<10 ;i++){
        myVec.push_back(i);    
    }
    // 1,2,3,4,5,6,7,8,9

    for (int i = 10; i > 1; i--){
        myVEC.push_back(i);
    }
    // 10,9,8,7,6,5,4,3,2
    
    myVec.pop_back();
    myVec.pop_back();

    myVec.erase(myVec.begin(), myVec.begin()+1);
    // 2,3,4,5,6,7

    myVec.erase(myVec.begin()+2);
    // 2,3,5,6,7

    myVec.insert(myVec.begin(),100);
    // 100,2,3,5,6,7

    if(myVEC < myVec){
        cout<<"myVec < myVEC"<<endl;
    }

    cout <<"the vector(myVec) elements is: "<<myVec<<endl;
    cout <<"the vector(myVEC) elements is: "<<myVEC<<endl;
    cout<<"my vector size is: "<<myVec.size()<<endl;
    cout<<"my vector capacity is: "<<myVec.capacity()<<endl;
    cout<<"is my vector is empty: "<<myVec.empty()<<endl;

    return 0;
}
