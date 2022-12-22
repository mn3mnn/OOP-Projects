/*

 * // Created by Monem on 12/15/2022.
 *
 * Implementation of Stack using:
 * Linked list
 * templates
 * exceptions

 */

#include <string>
#include <iostream>
using namespace std;


class StackEmptyException : public exception{
public:
    const char* what(){
        return "\nError: Stack is empty !\n";
    }
};


class StackOverflowException : public exception{
public:
    const char* what(){
        return "\nError: Stack is full !\n";
    }
};


template<class T>
class Node {
public:
    Node<T>* next = nullptr;
    T val;
    Node(T x) : val(x), next(nullptr) {}
    Node() : val(), next(nullptr) {}
};



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

// copy constructor
template<class T>
Stack<T>::Stack(const Stack<T>& other){
    this->MAX_SIZE = other.MAX_SIZE;
    this->top_ptr = new Node<T>();
    for (int i = 0; i <other.size(); ++i) {
        (top_ptr + i)->val = (other.top_ptr + i)->val;
        (top_ptr + i)->next = (other.top_ptr + i)->next;
    }
}

// copy assignment
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &other) {
    if (other == *this){
        throw exception();
    }
    this->MAX_SIZE = other.MAX_SIZE;
    this->top_ptr = new Node<T>();
    for (int i = 0; i <other.size(); ++i) {
        (top_ptr + i)->val = (other.top_ptr + i)->val;
        (top_ptr + i)->next = (other.top_ptr + i)->next;
    }
    return *this;
}


template<class T>
void Stack<T>::push(T x) {
    if (sz == MAX_SIZE){
        throw StackOverflowException();
    }
    else{
        Node<T> *node = new Node<T>(x);
        node->next = top_ptr;
        top_ptr = node;
        ++sz;
    }
}

template<class T>
T Stack<T>::top() {
    if (!top_ptr){
        throw StackEmptyException();
    }
    else{
        return top_ptr->val;
    }
}

template<class T>
T Stack<T>::pop() {
    if (top_ptr == nullptr){
        throw StackEmptyException();
    }
    else{
        Node<T> *top_ptr2 = top_ptr;
        T val = top_ptr2->val;
        top_ptr = top_ptr->next;
        delete top_ptr2;
        --sz;
        return val;
    }
}

template<class T>
bool Stack<T>::empty() {
    return top_ptr == nullptr;
}

template<class T>
size_t Stack<T>::size() {
    return sz;
}

// generic function to manage stack of type T
template<typename T>
void manageStack(){
    bool displaying = true;
    size_t sz = 0;

    cout << "Welcome to Stack manager.\n";

    while (sz <= 0){
        cout << "enter size of the stack: ";
        cin >> sz;
    }

    Stack<T> stk(sz);

    while(displaying) {
        int choice = -1;
        while (choice < 0 || choice > 3){
            cout << "\nSelect option: \n"
                 << "1- Push \n2- Pop \n3- Top \n0- to exit\n\n";
            cin >> choice;
        }
        if (choice == 1){
            try{
                T data;
                cout << "\nenter data to push: ";
                cin >> data;
                stk.push(data);
            }
            catch (StackOverflowException & e){
                cout << '\n' << e.what() <<'\n';
            }
        }
        else if(choice == 2){
            try{
                stk.pop();
                cout << "\nitem deleted.\n";
            }
            catch (StackEmptyException & e){
                cout << '\n' << e.what() <<'\n';
            }

        }
        else if (choice == 3){
            try{
                T data = stk.top();
                cout << "\nTop: " << data << '\n';
            }
            catch (StackEmptyException & e){
                cout << '\n' << e.what() <<'\n';
            }
        }
        else if (choice == 0){
            displaying = false;
        }
    }

}


int main() {

//    // manage stack of strings
//    manageStack<string>();

    // manage stack of int
    manageStack<string>();

    system("pause");
    return 0;
}

