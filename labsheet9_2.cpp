// 2. Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class MyQueue {
private:
    queue<T> q;

public:
    void push(const T& item) {
        q.push(item);
    }

    T pop() {
        T frontItem = q.front();
        q.pop();
        return frontItem;
    }

    bool isEmpty() const {
        return q.empty();
    }

    size_t size() const {
        return q.size();
    }
};

int main() {
    // Queue of integers
    MyQueue<int> intQueue;
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    
    cout << "Integer Queue Size: " << intQueue.size() << endl;
    cout << "Popping from Integer Queue: " << intQueue.pop() << endl;

    // Queue of doubles
    MyQueue<double> doubleQueue;
    doubleQueue.push(1.1);
    doubleQueue.push(2.2);
    doubleQueue.push(3.3);
    
    cout << "Double Queue Size: " << doubleQueue.size() << endl;
    cout << "Popping from Double Queue: " << doubleQueue.pop() << endl;

    // Queue of strings
    MyQueue<string> stringQueue;
    stringQueue.push("Hello");
    stringQueue.push("World");
    
    cout << "String Queue Size: " << stringQueue.size() << endl;
    cout << "Popping from String Queue: " << stringQueue.pop() << endl;

    return 0;
}
