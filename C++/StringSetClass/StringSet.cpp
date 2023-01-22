//
// Created by Monem on 11/10/2022.
//

#include "StringSet.h"
using namespace std;


// constructor that takes a string to add it to the set
StringSet::StringSet(const string& str1) {
    // insert keywords from str1 into the set
    break_into_tokens(str1, set);
}

// constructor to open a .txt file
// parameter isFileName is just a temporary parameter
// to identify the constructor that takes a file_name as a parameter
StringSet::StringSet(const string &file_name, bool isFileName) {
    fstream myFile;
    myFile.open(file_name, ios::in);
    if (!myFile) {
        cerr << "No such file exist.\n";
        exit(1);
    }
    cout << "File: " << file_name << " opened successfully.\n";
    // read the file line by line
    // add every line to the set
    string tmp;
    while (getline(myFile, tmp)){
        // function add() will insert keywords of each line into the set
        this->add(tmp);
    }
    myFile.close();
}


// initialize the set with lowercase str1 keywords
void StringSet::break_into_tokens(string str1, vector<string>& vec) {
    // turn str1 into lowercase
    for (auto & c : str1) {
        c = tolower(c);
    }
    // capture keywords from str1
    regex words_regex;
    words_regex = "([\\w]+)";
    smatch match;
    while (regex_search(str1, match, words_regex)) {
        vec.push_back(match[0]);
        str1 = match.suffix();
    }
    // sort the set
    std::sort(vec.begin(), vec.end());
}


// return a sorted vector of keywords from lowercase str1
vector<string> StringSet::break_into_tokens(string str1) {
    vector<string> res;
    // turn str1 into lowercase
    for (auto & c : str1) {
        c = tolower(c);
    }
    // capture keywords from str1
    regex words_regex;
    words_regex = "([\\w]+)";
    smatch match;
    while (regex_search(str1, match, words_regex)) {
        res.push_back(match[0]);
        str1 = match.suffix();
    }
    // sort the set
    std::sort(res.begin(), res.end());
    return res;
}


// insert keywords of str1 into the set and remove duplicates from the set
void StringSet::add(const string& str1) {
    vector<string> tmp;
    tmp = break_into_tokens(str1);
    set.insert(set.end(), tmp.begin(), tmp.end());

    // remove duplicates
    std::sort(set.begin(), set.end());
    set.erase(unique(set.begin(), set.end()), set.end());
}


// remove a given string from the set
void StringSet::remove(string str1) {
    set.erase(remove_if(set.begin(), set.end(), [&](const auto &item) {
        if (item == str1)
            return true;
        else
            return false;
    }), set.end());
}


// clear all the set
void StringSet::clear() {
    set.clear();
}


// return n of elements in the set
size_t StringSet::size() {
    return set.size();
}


// print all keywords in the set
void StringSet::print() {
    if (set.empty()){
        cout << "Set is empty. \n";
        return;
    }

    for (auto & word : set){
        cout << '\'' << word << '\'' << ", ";
    }
    cout << '\n';
}


// return the union of the two sets
StringSet StringSet::operator+(const StringSet &other) {
    StringSet result("");

    // this->set and other.set vectors should be SORTED
    set_union(set.begin(), set.end(), other.set.begin(), other.set.end(),
              back_inserter(result.set));

    return result;
}


// return the intersection of two sets
StringSet StringSet::operator*(const StringSet &other) {
    StringSet result("");

    // this->set and other.set vectors should be SORTED
    set_intersection(set.begin(), set.end(), other.set.begin(), other.set.end(),
                     back_inserter(result.set));

    return result;
}


// return true if the two sets are very similar to each other and print Similar or Not similar
bool StringSet::is_similar_to(const StringSet &other) {

    size_t sim = 0;
    // size of intersection of two sets
    size_t sz_of_common = ((*this) * other).size();
    size_t sz1 = other.set.size();
    size_t sz2 = set.size();

    sim = (sz_of_common) / (size_t) (sqrt(sz1) * sqrt(sz2));

    if (sim){
        cout << "Similar.\n";
    }
    else {
        cout << "Not Similar.\n";
    }
    return sim;
}
