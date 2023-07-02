// 1.Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function.

// #include <iostream>
// using namespace std;
// struct Date
// {   
//     int mm;
//     int dd;
//     int yy;
// };

// void printDate(struct Date& date)
//     {
//         cout<<date.mm<<"/"<<date.dd<<"/"<<date.yy<<endl; 
//     }   

// int main()
// {
//     Date myDate;
//     myDate.mm=11;
//     myDate.dd=28;
//     myDate.yy=2004;
//     display(myDate);
//     return 0;
// }

#include <iostream>

// Define the date structure
struct Date {
    int month;
    int day;
    int year;
};

// Function to print the date in the specified format
void printDate(const Date& date) {
    std::cout << date.month << "/" << date.day << "/" << date.year << std::endl;
}

int main() {
    // Create a date object
    Date myDate;

    // Assign values to the members of the structure
    myDate.month = 28;
    myDate.day = 11;
    myDate.year = 2004;

    // Pass the structure to the function to print the date
    printDate(myDate);

    return 0;
}