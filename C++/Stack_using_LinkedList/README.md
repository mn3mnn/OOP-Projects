# Stack-using-linkedlist

### Stack data structure using **Linked list**, **Templates**, and **Exceptions handling**

header file:

```
template<class T>
class Stack {
    // ptr to the top of the stack
    Node<T>* top_ptr = nullptr;
    size_t MAX_SIZE;
    // curr size of the stack
    size_t sz = 0;
public:
    // constructors
    Stack() : top_ptr(nullptr), MAX_SIZE(2), sz(0) {}
    Stack(size_t size1) : top_ptr(nullptr), MAX_SIZE(size1) {}
    // copy constructor
    Stack(const Stack<T>& other);
    // destructor
    ~Stack() {}
    // copy assignment
    Stack& operator=(const Stack<T>& other);
    // methods
    void push(T x);
    T pop();
    T top();
    bool empty();
    size_t size();

};
```
