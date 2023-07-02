#include <iostream>
using namespace std;

int findCharacterPosition(const string& sentence, char character) {
    const char* ptr = sentence.c_str();
    int position = 0;

    while (*ptr != '\0') {
        if (*ptr == character) {
            return position;
        }

        ptr++;
        position++;
    }

    return -1; // Character not found
}

int main() {
    string sentence = "idea without execution is worthless";
    char character = 'C';

    int position = findCharacterPosition(sentence, character);

    if (position != -1) {
        cout << "Position of '" << character << "' in the sentence: " << position << endl;
    } else {
        cout << "'" << character << "' not found in the sentence." << endl;
    }

    return 0;
}
