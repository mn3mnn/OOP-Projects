//
// Created by Monem on 11/10/2022.
//

#ifndef DOCUMENTSIMILARITY_STRINGSET_H
#define DOCUMENTSIMILARITY_STRINGSET_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <fstream>
#include <cmath>
using namespace std;

// class to store set of keywords of a string
class StringSet {
    // set is always SORTED
    vector<string> set;

    /// private methods
    // return a sorted vector of keywords from str1
    static vector<string> break_into_tokens(string str1);
    // initialize the set with str1 keywords
    void break_into_tokens(string str1, vector<string>& vec);


public:
    /// constructors
    // constructor that takes a string to add it to the set
    StringSet(const string& str1);
    // constructor to open a .txt file
    // parameter isFileName is just a temporary parameter
    // to identify the constructor that takes a file_name as a parameter
    StringSet(const string& file_name, bool isFileName);

    /// methods
    // insert keywords of str1 into the set and remove duplicates from the set
    void add(const string& str1);
    // remove str1 from the set
    void remove(string str1);
    void clear();
    size_t size();
    void print();
    // return true if the two sets are very similar to each other and print Similar or Not similar
    bool is_similar_to(const StringSet & other);

    /// operators overloading
    // return the union of the two sets
    StringSet operator+ (const StringSet & other);
    // return the intersection of the two sets
    StringSet operator* (const StringSet & other);

};

#endif //DOCUMENTSIMILARITY_STRINGSET_H

