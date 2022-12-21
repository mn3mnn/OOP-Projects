#include <iostream>
#include <vector>
#include "EAVector.h"

using namespace std;

int main() {

    EAVector<int> myVec(4);
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);
    myVec.push_back(5);

//    myVec.pop_back();
//    myVec.pop_back();

    myVec.erase(myVec.begin() + 2);
    myVec.erase(myVec.begin() + 1, myVec.begin() + 2);

    myVec.insert(myVec.begin() + 1, 3);

    cout << myVec;

    return 0;
}
