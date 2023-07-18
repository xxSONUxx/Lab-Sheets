//4. Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).

#include <iostream>

using namespace std;

class TollBooth {
private:
    int num_vehicle;
    int hour;
    double rate;

public:
    TollBooth(int numVehicles, int h, double r) {
        num_vehicle = numVehicles;
        hour = h;
        rate = r;
    }

    TollBooth(const TollBooth& other) {
        num_vehicle = other.num_vehicle;
        hour = other.hour;
        rate = other.rate;
    }

    void applyDiscount() {
        if (num_vehicle > 10) {
            rate *= 0.9; // Apply a 10% discount
        }
    }

    double calculateCharge() const {
        return num_vehicle * hour * rate;
    }

    void displayTotalCharge() const {
        cout << "Total Charge: $" << calculateCharge() << endl;
    }
};

int main() {
    TollBooth booth1(8, 2, 10.0); // 8 vehicles, 2 hours, $10 per hour
    TollBooth booth2 = booth1; // Bit-by-bit copy using the copy constructor

    booth2.applyDiscount();

    booth1.displayTotalCharge(); // Original charge without discount
    booth2.displayTotalCharge(); // Charge with discount applied

    return 0;
}
