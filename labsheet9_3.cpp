// 3. Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.

#include <iostream>
#include <vector>
#include <stdexcept> // for std::overflow_error and std::underflow_error

using namespace std;

template <typename T>
class MyStack {
private:
    vector<T> stack;
    size_t capacity;

public:
    MyStack(size_t capacity) : capacity(capacity) {}

    void push(const T& item) {
        if (stack.size() >= capacity) {
            throw overflow_error("Stack is full. Cannot push more elements.");
        }
        stack.push_back(item);
    }

    T pop() {
        if (stack.empty()) {
            throw underflow_error("Stack is empty. Cannot pop elements.");
        }
        T topItem = stack.back();
        stack.pop_back();
        return topItem;
    }

    bool isEmpty() const {
        return stack.empty();
    }

    size_t size() const {
        return stack.size();
    }
};

int main() {
    // Example with integer stack
    MyStack<int> intStack(5);

    try {
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);
        intStack.push(4);
        intStack.push(5);

        // Uncommenting the line below will cause an overflow error
        // intStack.push(6);
    }
    catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        while (!intStack.isEmpty()) {
            cout << "Popping: " << intStack.pop() << endl;
        }

        // Uncommenting the line below will cause an underflow error
        // intStack.pop();
    }
    catch (const underflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
