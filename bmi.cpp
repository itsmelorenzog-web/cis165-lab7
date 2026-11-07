#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight;
    double height;
    double bmi;

    cout << "Enter weight in pounds: ";
    cin >> weight;
    cout << "Enter height in inches: ";
    cin >> height;

    if (weight <= 0 || height <= 0) {
        cout << "Error: weight and height must be positive." << endl;
        return 1;
    }

    bmi = weight * 703.0 / (height * height);

    cout << fixed << setprecision(2);
    cout << "BMI: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Category: Underweight" << endl;
    } else if (bmi <= 25.0) {
        cout << "Category: Optimal weight" << endl;
    } else {
        cout << "Category: Overweight" << endl;
    }

    return 0;
}
