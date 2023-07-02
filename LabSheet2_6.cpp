// Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are

// Chief executive officer Rs. 35000/m
// Information officer Rs. 25000/m
// System analyst Rs. 24000/m
// Programmer Rs. 18000/m
// Make a function that takes two arguments; one salary and the other increment. Use proper default argument

#include <iostream>

// Function to calculate the updated salary based on the given increment
double calculateSalary(double salary, double increment = 0.0) {
    return salary + (salary * increment / 100);
}

int main() {
    // Salaries in year 2009
    double ceoSalary = 35000;
    double infoOfficerSalary = 25000;
    double sysAnalystSalary = 24000;
    double programmerSalary = 18000;

    // Percentage increments for year 2010
    double ceoIncrement = 9;
    double infoOfficerIncrement = 10;
    double sysAnalystIncrement = 12;
    double programmerIncrement = 12;

    // Calculate the updated salaries for year 2010
    double updatedCeoSalary = calculateSalary(ceoSalary, ceoIncrement);
    double updatedInfoOfficerSalary = calculateSalary(infoOfficerSalary, infoOfficerIncrement);
    double updatedSysAnalystSalary = calculateSalary(sysAnalystSalary, sysAnalystIncrement);
    double updatedProgrammerSalary = calculateSalary(programmerSalary, programmerIncrement);

    // Display the of 2009 salaries
    std::cout << "Salaries for Year 2009:" << std::endl;
    std::cout << "Chief Executive Officer: " << ceoSalary << "/m" << std::endl;
    std::cout << "Information Officer: " << infoOfficerSalary << "/m" << std::endl;
    std::cout << "System Analyst: " << sysAnalystSalary << "/m" << std::endl;
    std::cout << "Programmer: " << programmerSalary << "/m" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    
    
    std::cout << "Updated Salaries for Year 2010:" << std::endl;
    std::cout << "Chief Executive Officer: " << updatedCeoSalary << "/m" << std::endl;
    std::cout << "Information Officer: " << updatedInfoOfficerSalary << "/m" << std::endl;
    std::cout << "System Analyst: " << updatedSysAnalystSalary << "/m" << std::endl;
    std::cout << "Programmer: " << updatedProgrammerSalary << "/m" << std::endl;

    return 0;
}
