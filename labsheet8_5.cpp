// 5. Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information (account-number, last-name, first-name, total-balance).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Define the structure for the account
struct Account {
    int accountNumber;
    string lastName;
    string firstName;
    double totalBalance;
};

// Function to display an account's information
void displayAccount(const Account& acc) {
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Last Name: " << acc.lastName << endl;
    cout << "First Name: " << acc.firstName << endl;
    cout << "Total Balance: " << fixed << setprecision(2) << acc.totalBalance << endl;
    cout << "---------------------------------------------" << endl;
}

// Function to add an account to the file
void addAccount(fstream& file) {
    Account acc;

    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;

    cout << "Enter Last Name: ";
    cin.ignore(); // Clear the newline character left by previous input
    getline(cin, acc.lastName);

    cout << "Enter First Name: ";
    getline(cin, acc.firstName);

    cout << "Enter Total Balance: ";
    cin >> acc.totalBalance;

    file.seekp((acc.accountNumber - 1) * sizeof(Account));
    file.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
    cout << "Account added successfully." << endl;
}

// Function to update an existing account
void updateAccount(fstream& file) {
    int accountNumber;
    cout << "Enter Account Number to update: ";
    cin >> accountNumber;

    file.seekg((accountNumber - 1) * sizeof(Account));
    Account acc;
    file.read(reinterpret_cast<char*>(&acc), sizeof(Account));

    if (file.eof()) {
        cout << "Account not found." << endl;
        return;
    }

    displayAccount(acc);

    cout << "Enter new Total Balance: ";
    cin >> acc.totalBalance;

    file.seekp((accountNumber - 1) * sizeof(Account));
    file.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
    cout << "Account updated successfully." << endl;
}

// Function to delete an account
void deleteAccount(fstream& file) {
    int accountNumber;
    cout << "Enter Account Number to delete: ";
    cin >> accountNumber;

    file.seekg((accountNumber - 1) * sizeof(Account));
    Account acc;
    file.read(reinterpret_cast<char*>(&acc), sizeof(Account));

    if (file.eof()) {
        cout << "Account not found." << endl;
        return;
    }

    displayAccount(acc);

    char confirmation;
    cout << "Are you sure you want to delete this account? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {
        acc.accountNumber = 0; // Mark the account as deleted
        file.seekp((accountNumber - 1) * sizeof(Account));
        file.write(reinterpret_cast<const char*>(&acc), sizeof(Account));
        cout << "Account deleted successfully." << endl;
    } else {
        cout << "Deletion canceled." << endl;
    }
}

// Function to display all accounts in the file
void displayAllAccounts(fstream& file) {
    file.clear();
    file.seekg(0, ios::beg);

    Account acc;
    while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
        if (acc.accountNumber != 0) { // Check if the account is marked as deleted
            displayAccount(acc);
        }
    }
}

int main() {
    fstream accountFile("accounts.dat", ios::in | ios::out | ios::binary);

    if (!accountFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Account" << endl;
        cout << "2. Update Account" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAccount(accountFile);
                break;
            case 2:
                updateAccount(accountFile);
                break;
            case 3:
                deleteAccount(accountFile);
                break;
            case 4:
                displayAllAccounts(accountFile);
                break;
            case 5:
                accountFile.close();
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
