#include <iostream>
using namespace std;

const int NUM_YEARS = 3;
const int NUM_MONTHS = 12;

void displayExpenditureTable(int expenditure_table[NUM_YEARS][NUM_MONTHS]) {
    cout << "Expenditure Table:" << endl;
    for (int i = 0; i < NUM_YEARS; i++) {
        for (int j = 0; j < NUM_MONTHS; j++) {
            cout << expenditure_table[i][j] << "\t";
        }
        cout << endl;
    }
}

void calculateAverageExpenditure(int expenditure_table[NUM_YEARS][NUM_MONTHS], int start_year, int end_year) {
    int monthly_totals[NUM_YEARS][NUM_MONTHS] = {0};
    int yearly_totals[NUM_YEARS] = {0};
    int overall_total = 0;
    int num_years = end_year - start_year + 1;

    // Calculate monthly totals and yearly totals
    for (int i = 0; i < NUM_YEARS; i++) {
        for (int j = 0; j < NUM_MONTHS; j++) {
            monthly_totals[i][j] = expenditure_table[i][j];
            yearly_totals[i] += expenditure_table[i][j];
            overall_total += expenditure_table[i][j];
        }
    }

    // Display monthly averages
    cout << "Monthly Averages:" << endl;
    for (int i = 0; i < NUM_YEARS; i++) {
        for (int j = 0; j < NUM_MONTHS; j++) {
            double monthly_average = static_cast<double>(monthly_totals[i][j]) / num_years;
            cout << monthly_average << "\t";
        }
        cout << endl;
    }

    // Display yearly averages
    cout << "Yearly Averages:" << endl;
    for (int i = 0; i < NUM_YEARS; i++) {
        double yearly_average = static_cast<double>(yearly_totals[i]) / NUM_MONTHS;
        cout << yearly_average << "\t";
    }
    cout << endl;

    // Display overall average
    double overall_average = static_cast<double>(overall_total) / (NUM_YEARS * NUM_MONTHS);
    cout << "Overall Average: " << overall_average << endl;
}

int main() {
    int expenditure_table[NUM_YEARS][NUM_MONTHS] = {
        {100, 150, 200, 300, 250, 200, 150, 100, 200, 250, 300, 150},
        {200, 250, 150, 100, 300, 250, 200, 150, 200, 300, 150, 250},
        {300, 200, 250, 150, 100, 300, 250, 200, 150, 250, 200, 300}
    };

    displayExpenditureTable(expenditure_table);

    int start_year, end_year;
    cout << "Enter the start year: ";
    cin >> start_year;
    cout << "Enter the end year: ";
    cin >> end_year;

    calculateAverageExpenditure(expenditure_table, start_year, end_year);

    return 0;
}
