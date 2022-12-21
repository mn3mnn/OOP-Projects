//
// Created by DELL on 12/15/2022.
//

#include "EAVector.h"

// Initialize by specific capacity, size = 0
template<class T>
EAVector<T>::EAVector(int cap) : capacity_(cap), size_(0) {
    arr_ = new T[cap];
}

// Delete allocated memory
template<class T>
EAVector<T>::~EAVector() {
    delete[] arr_;
}

// Initialize by n items from array
template<class T>
EAVector<T>::EAVector(T *arr, int n) : capacity_(n * 2), size_(0) {
    arr_ = new T[capacity_];
    try{
        for (int i = 0; i < n; ++i) {
            push_back(arr[i]);
        }
    }
    /// if any exception caught throw it and make the vector empty
    catch (...){
        delete[] arr_;
        arr_ = new T[capacity_];
        size_ = 0;
        throw;
    }

}

// copy constructor
template<class T>
EAVector<T>::EAVector(const EAVector<T> &other) : capacity_(other.capacity_), size_(0) {

    arr_ = new T[capacity_];
    // copy other data into arr_
    for (int i = 0; i < other.size(); ++i) {
        push_back(other[i]);
    }

}

// copy assignment
template<class T>
EAVector<T> &EAVector<T>::operator=(const EAVector<T> & other) {
    // throw an exception in case of self assignment, ( vec1 = vec1 )
    if (this == &other){
        throw invalid_argument("Can't assign a Vector to itself!\n");
    }
    /// if there is an allocated memory delete it then copy the other vector
    if (arr_ != nullptr){
        delete[] arr_;
    }
    capacity_ = other.capacity_;
    size_ = 0;
    for (int i = 0; i < other.size_; ++i) {
        push_back(other[i]);
    }

    return *this;
}

// move assignment
template<class T>
EAVector<T> &EAVector<T>::operator=(EAVector<T> &&other) {
    if (this != &other){
        capacity_ = std::move(other.capacity_);
        size_ = std::move(other.size_);
        arr_ = std::move(other.arr_);
    }
    return *this;
}

// move constructor
template<class T>
EAVector<T>::EAVector(EAVector<T> &&other) : capacity_(std::move(other.capacity_)),
                                            size_(std::move(other.size_)),
                                            arr_(std::move(other.arr_)){

}


template<class T>
T &EAVector<T>::operator[](int index) {
    try{
        if (index < size_ && index >= 0){
            return arr_[index];
        }
        else{
            throw invalid_argument("index out of range !");
        }
    }
    catch (invalid_argument& e){
        cerr << e.what();
    }
}


template<class T>
const T &EAVector<T>::operator[](int index) const {
    try{
        if (index < size_ && index >= 0){
            return arr_[index];
        }
        else{
            throw invalid_argument("index out of range !");
        }
    }
    catch (invalid_argument& e){
        cerr << e.what();
        throw;
    }

}

// push item to the end of vector, increase the size_ by 1, and call resize() if needed
template<class T>
int EAVector<T>::push_back(T item) {
    if (size() == capacity()){
        resize();
    }
    arr_[size_] = item;
    // increase the size by 1 and return it
    return ++size_;
}

// Remove and return last element in vec, decrease the size_ by 1
template<class T>
T EAVector<T>::pop_back() {
    if (empty()){
        throw range_error("Empty Vector !\n");
    }else {
        T val = arr_[size_ - 1];
        // destruct the last element
        arr_[--size_].~T();
        return val;
    }

}

// if pos is equal to end(), erase the last element
template<class T>
void EAVector<T>::erase(iterator pos) {
    if (pos >= begin() && pos < end()) {
        iterator copy_itr = pos;
        while (pos != (end() - 1)) { // copies elements one position left
            *copy_itr++ = *++pos;
        }
        // then pop the last one
        pop_back();
    }
    // if pos is = end(),it erases the last element
    else if (pos == end()){
        pop_back();
    }
    else{
        throw range_error("index out of range !\n");
    }
}

// pos2 NOT included
template<class T>
void EAVector<T>::erase(iterator pos1, iterator pos2) {
    if (pos1 >= begin() && pos2 <= end() && pos1 < pos2){
        for (iterator it = pos1; it < pos2; ++it) {
            erase(pos1);
        }
    }
    else{
        throw invalid_argument("index out of range!!\n");
    }
}


template<class T>
void EAVector<T>::insert(iterator pos, T val) {
    if (pos >= begin() && pos < end() - 1) {
        // push back the val to the end
        push_back(val);
        // swap every pair of elements from the end to the pos
        iterator it = end() - 1;
        while (it > pos) {
            iterator prev_it = it - 1;
            swap(*it, *prev_it);
            --it;
        }
    }
    else if(pos == end() - 1 || pos == end()){
        push_back(val);
    }
    else{
        throw range_error("index out of range !\n");
    }
}


template<class T>
void EAVector<T>::clear() {
    erase(begin(), end());
}


template<class T>
typename EAVector<T>::iterator EAVector<T>::begin() const {
    // return iterator points to the first element
    return iterator(arr_);
}


template<class T>
typename EAVector<T>::iterator EAVector<T>::end() const {
    // return iterator points to index of the last element + 1
    return iterator(arr_ + size_);
}


template<class T>
int EAVector<T>::size() const {
    return size_;
}

template<class T>
int EAVector<T>::capacity() const {
    return capacity_;
}

// allocates new array with doubled capacity
// return the new capacity
template<class T>
int EAVector<T>::resize() {
    EAVector<T> vec_new(capacity_ * 2);

    std::for_each(begin(), end(),
                  [&vec_new](T const& v){vec_new.push_back(v);}
    );

    std::swap(size_, vec_new.size_);
    std::swap(capacity_, vec_new.capacity_);
    delete[] arr_;
    std::swap(arr_, vec_new.arr_);
    return capacity_;
}

template<class T>
bool EAVector<T>::empty() {
    return size_ == 0;
}


template<class T>
bool EAVector<T>::operator==(const EAVector<T> & other) {
    if (size_ != other.size_){
        return false;
    }
    for (int i = 0; i < size_; ++i) {
        if (arr_[i] != other.arr_[i]){
            return false;
        }
    }
    return true;
}

// Compares item by item
// Return true if first different item in this is < in other
template<class T>
bool EAVector<T>::operator<(const EAVector<T> &other) {
    for (int i = 0; i < size_ && i < other.size_; ++i) {
        if (arr_[i] >= other.arr_[i]){
            return false;
        }
    }
    return true;
}

