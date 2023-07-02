//3.Define two namespaces: Square and Cube. In both the namespaces, define an integer variable named "num" and a function named "fun". The "fun" function in "Square" namespace, should return the square of an integer passed as an argument while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument. In the main function, set the integer variables "num" of both the namespaces with different values. Then, compute and print the cube of the integer variable "num" of the "Square" namespace using the "fun" function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace using the "fun" function of the "Square" namespace.

#include <iostream>

namespace Square {
    int num;
    int fun(int x) {
        return x * x;
    }
}

namespace Cube {
    int num;
    int fun(int x) {
        return x * x * x;
    }
}

int main() {
    Square::num = 2;
    Cube::num = 3;

    int squareOfNum = Square::fun(Cube::num);
    int cubeOfNum = Cube::fun(Square::num);

    std::cout << "Cube of Square::num: " << squareOfNum << std::endl;
    std::cout << "Square of Cube::num: " << cubeOfNum << std::endl;

    return 0;
}
