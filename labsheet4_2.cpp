//2. Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as arguments. Display the concatenated string through a member function. Use constructors to allocate and initialize the data member. Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two strings.


#include <iostream>
#include <cstring>

using namespace std;

class Concatenator {
private:
    char* str;

public:
    Concatenator(const char* initialStr) {
        int length = strlen(initialStr) + 1;
        str = new char[length];
        strcpy(str, initialStr);
    }

    ~Concatenator() {
        delete[] str;
    }

    void join(const Concatenator& obj1, const Concatenator& obj2) {
        int length = strlen(obj1.str) + strlen(obj2.str) + 1;
        delete[] str;
        str = new char[length];
        strcpy(str, obj1.str);
        strcat(str, obj2.str);
    }

    void displayConcatenatedString() const {
        cout << "Concatenated String: " << str << endl;
    }
};

char* concatenateStrings(const char* str1, const char* str2) {
    int length = strlen(str1) + strlen(str2) + 1;
    char* result = new char[length];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    Concatenator obj1("Engineers are");
    Concatenator obj2(" Creatures of logic");

    Concatenator result("");

    result.join(obj1, obj2);
    result.displayConcatenatedString();

    // Using the standalone concatenateStrings function
    char* concatenated = concatenateStrings(obj1.getStr(), obj2.getStr());
    cout << "Standalone Concatenated String: " << concatenated << endl;
    delete[] concatenated;

    return 0;
}
