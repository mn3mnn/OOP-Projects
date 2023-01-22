//
// Created by Monem on 10/17/2022.
//

#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;


template<class T, size_t N>
class MyArray{
    T* ptr = nullptr;
    size_t MAX_SIZE = 0;

    // arr1 is the array to be copied
    MyArray<T, N>& deep_copy(const MyArray & arr1);

public:
    // constructor
    MyArray () : ptr(new T[N]{}), MAX_SIZE(N) {}
    // destructor
    ~MyArray () {
        delete[] ptr;
    }
    // copy constructor
    MyArray (const MyArray & arr1);

    // operator= copy the right-side(arr1)  into the left-side array
    MyArray& operator=(const MyArray & arr1);

    // access n-th element of the array with []
    T& operator[](int index);

    size_t size();

};


template<class T, size_t N>
size_t MyArray<T, N>::size(){
    return MAX_SIZE;
}


// copy constructor
// arr1 is the array to be copied
template<class T, size_t N>
MyArray<T, N>::MyArray(const MyArray<T, N> &arr1) : MAX_SIZE(arr1.MAX_SIZE) {
    // copy arr1 values into this->ptr
    deep_copy(arr1);
}


// deep copying
// arr1 is the array to be copied
// the function will delete the allocated array if exist to avoid memory leak
template<class T, size_t N>
MyArray<T, N>& MyArray<T, N>::deep_copy(const MyArray & arr1){
    try{
        if (this->MAX_SIZE != arr1.MAX_SIZE){
            throw invalid_argument("Arrays size should be equal !");
        }
        else if (this->ptr == arr1.ptr){
            throw invalid_argument("Can't assign array to itself !");
        }
        else {
            if (this->ptr){
                // delete the array to avoid memory leak
                delete[] this->ptr;
            }
            // then copy arr1 values into this->ptr
            this->ptr = new T[MAX_SIZE]{};
            for (int i = 0; i < MAX_SIZE; ++i) {
                *(this->ptr + i) = *(arr1.ptr + i);
            }
            return *this;
        }
    }
    catch (invalid_argument& e){
        cerr << e.what();
        exit(1);
    }
}


template<class T, size_t N>
MyArray<T, N> & MyArray<T, N>::operator=(const MyArray & arr1){
    try{
        if (arr1.ptr != this->ptr){
            this->MAX_SIZE = arr1.MAX_SIZE;
            deep_copy(arr1);
            return *this;
        }
        else{
            throw invalid_argument("can't assign array to itself !");
        }
    }
    catch (invalid_argument& e){
        cerr << e.what();
        exit(1);
    }
}


template<class T, size_t N>
T & MyArray<T, N>::operator[](int index) {
    try{
        if (index < MAX_SIZE && index >= 0){
            return *(ptr + index);
        }
        else{
            throw invalid_argument("index error!");
        }
    }
    catch (invalid_argument& e){
        cerr << e.what();
        exit(1);
    }
}


template<class T, size_t N>
void print_arr(MyArray<T, N>& arr1){
    cout << endl;
    for (int i = 0; i < arr1.size(); ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl << "##################################################" <<endl;
    cout << endl;
}


void test_MyArray(){

    // init using constructors, all values are initially = zero
    MyArray<int, 5> arr1_int;
    MyArray<long long, 5> arr1_ll{};
    MyArray<char, 5> arr1_char{};

    // init using copy constructors
    MyArray<int, 5> arr2_int = MyArray<int, 5>(arr1_int);
    MyArray<long long, 5> arr2_ll = arr1_ll;
    MyArray<char, 5> arr2_char = arr1_char;

    // assign values from 0 to 4 in the array  using operator[]
    for (int i = 0; i < 5; ++i) {
        arr1_int[i] = i;
        arr1_char[i] = i + 48;
        arr1_ll[i] = i;
    }

    // print arr1
    cout << "\narr1 : \n";
    print_arr(arr1_int);
    print_arr(arr1_char);
    print_arr(arr1_ll);
    // print arr2
    cout << "\narr2 : \n";
    print_arr(arr2_int);
    print_arr(arr2_char);
    print_arr(arr2_ll);
    //


    // using assignment operator
    arr2_int = arr1_int;
    arr2_char = arr1_char;
    arr2_ll = arr1_ll;

    // change value by reference using operator[]
    arr2_int[0] = 1;
    arr2_char[0] = 1 + 48;
    arr2_ll[0] = 1;


    // print arr1
    cout << "\narr1 : \n";
    print_arr(arr1_int);
    print_arr(arr1_char);
    print_arr(arr1_ll);

    // print arr2
    cout << "\narr2 : \n";
    print_arr(arr2_int);
    print_arr(arr2_char);
    print_arr(arr2_ll);


}


int main() {

    test_MyArray();
    int n = 9;

}






