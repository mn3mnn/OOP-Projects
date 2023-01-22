//
// Created by Monem on 11/10/2022.
//

#include <iostream>
#include "StringSet.h"
using namespace std;


int main() {
    cout << "-------------------------------------------------------------------\n";

    StringSet set_1("Milk, Chocolate bars, and coffee.");
    cout << "*************** set_1(\"Milk, Chocolate bars, and coffee.\") :\n";
    set_1.print();

    cout << "\n-------------------------------------------------------------------\n";

    cout << "*************** set_2 (\"test.txt\") :\n";
    StringSet set_2("test.txt", true);
    set_2.print();

    cout << "\n-------------------------------------------------------------------\n";

    cout << "*************** set_1.add(\"ice-cream?\") :\n";
    set_1.add("ice-cream?");
    set_1.print();

    cout << "\n-------------------------------------------------------------------\n";

    cout << "*************** set_2.add(\"coffee!\") :\n";
    cout << "*************** set_2.remove(\"are\") :\n";
    set_2.add("coffee!");
    set_2.remove("are");
    set_2.print();

    cout << "\n-------------------------------------------------------------------\n";

    StringSet set_union = set_1 + set_2;
    cout << "*************** set_1 + set_2 :\n";
    set_union.print();

    cout << "\n-------------------------------------------------------------------\n";

    StringSet set_intersection = set_1 * set_2;
    cout << "*************** set_1 * set_2 :\n";
    set_intersection.print();

    cout << "\n-------------------------------------------------------------------\n";

    cout << "*************** set_1.is_similar_to(set_2) : \n";
    set_1.is_similar_to(set_2);

    cout << "\n-------------------------------------------------------------------\n";

    set_1.clear();
    set_2.clear();

    return 0;
}

