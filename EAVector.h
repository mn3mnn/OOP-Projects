//
// Created by DELL on 12/16/2022.
//

#ifndef EAVECTOR_EAVECTOR_H
#define EAVECTOR_EAVECTOR_H


#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;


template<class T>
class EAVector {
    T* arr_ = nullptr;
    int capacity_;
    int size_;

public:
    // iterator' constructor takes a pointer to an element in the vector
    struct iterator;

    /// Constructors and Big 4
    EAVector(int cap);
    EAVector(T* arr, int n);
    EAVector(const EAVector<T> & other);
    EAVector(EAVector<T> && other);
    ~EAVector();
    EAVector &operator=(const EAVector<T>& other);  // Copy assignment
    EAVector &operator=(EAVector<T>&& other); // Move assignment

    /// Access operations
    T& operator[](int index); // Access item by reference, Throw an exception if out of range
    const T& operator[](int index) const;

    /// Modifying operations
    int push_back(T item);
    T pop_back();
    // Remove item at iterator, Throw exception if invalid iter
    void erase(iterator pos);
    // Remove items between iterator 1 <= iterator 2 , otherwise do nothing
    // Throw exception if any iterator outside range
    void erase(iterator pos1, iterator pos2);
    void clear();
    // Insert item at iterator, Throw exception if invalid
    void insert(iterator itr, T val);
    iterator begin() const;	// Return an iterator
    iterator end() const;	// Return an iterator

    /// Comparison operations
    bool operator==(const EAVector<T>&);
    // Compares item by item, Return true if first different item in this is < in other
    bool operator< (const EAVector<T>&);

    /// Capacity operations
    int size() const;     // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize();         // Relocate to bigger space
    bool empty();

    /// Friends
    friend ostream& operator <<(ostream& out, const EAVector<T>& vec){
        for(auto  i : vec ){
            out << i << ' ';
        }
        out << '\n';
        return out;
    }

};

template<class T>
struct EAVector<T>::iterator
{
    // Without these 5 directives, functions in the standard library that use iterators will not work.
    using iterator_category = std::random_access_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;

    // constructor
    explicit iterator(pointer ptr) : ptr(ptr) {}
    // dereference
    reference operator*() const { return *ptr; }
    iterator operator+(int n){ return iterator(ptr + n);}
    iterator operator+(const iterator& other){ return iterator(ptr + other.ptr);}
    iterator operator-(int n){ return iterator(ptr - n);}
    // Prefix increment
    iterator& operator++() { ++ptr; return *this; }
    // Postfix increment
    iterator operator++(int) { iterator tmp = *this; ++ptr; return tmp; }
    // Prefix decrement
    iterator& operator--() { --ptr; return *this; }
    // Postfix decrement
    iterator operator--(int) { iterator tmp = *this; --ptr; return tmp; }

    friend bool operator== (const iterator& a, const iterator& b) { return a.ptr == b.ptr; };
    friend bool operator!= (const iterator& a, const iterator& b) { return a.ptr != b.ptr; };
    friend bool operator< (const iterator& a, const iterator& b) { return a.ptr < b.ptr; };
    friend bool operator<= (const iterator& a, const iterator& b) { return (a.ptr < b.ptr) || (b.ptr == a.ptr); };
    friend bool operator> (const iterator& a, const iterator& b) { return a.ptr > b.ptr; };
    friend bool operator>= (const iterator& a, const iterator& b) { return (a.ptr > b.ptr) || a.ptr == b.ptr; };

private:
    // pointer to element in the vector
    pointer ptr;
};



#include "EAVector.cpp"


#endif //EAVECTOR_EAVECTOR_H
