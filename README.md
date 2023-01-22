# Array-Class

### Implementation of STL' array class using **Templates** and **Exception handling**. 

header: 

```
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

```
