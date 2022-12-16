//
// Created by DELL on 12/16/2022.
//
#include <iostream>
#include <vector>
#include "EAVector.h"

using namespace std;

int main() {

    EAVector<int> myVec(4);
    myVec.push_back(1);
//    myVec.push_back(2);
//    myVec.push_back(3);
//    myVec.push_back(4);
//    myVec.push_back(5);

    myVec.pop_back();
//    myVec.pop_back();

//    myVec.erase(myVec.end());
//    myVec.erase(myVec.begin(), myVec.begin() + 2);

    cout << myVec;

    return 0;
}



