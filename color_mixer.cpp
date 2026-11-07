#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    const int COLOR_SIZE = 20;
    char first_color[COLOR_SIZE];
    char second_color[COLOR_SIZE];
    const char* mixed_color;

    cout << "Enter first primary color (red, blue, or yellow): ";
    cin >> setw(COLOR_SIZE) >> first_color;
    cout << "Enter second primary color (red, blue, or yellow): ";
    cin >> setw(COLOR_SIZE) >> second_color;

    bool first_valid = strcmp(first_color, "red") == 0 ||
                       strcmp(first_color, "blue") == 0 ||
                       strcmp(first_color, "yellow") == 0;
    bool second_valid = strcmp(second_color, "red") == 0 ||
                        strcmp(second_color, "blue") == 0 ||
                        strcmp(second_color, "yellow") == 0;

    if (!first_valid || !second_valid) {
        cout << "Error: enter red, blue, or yellow." << endl;
        return 1;
    }

    if (strcmp(first_color, second_color) == 0) {
        mixed_color = first_color;
    } else if ((strcmp(first_color, "red") == 0 && strcmp(second_color, "blue") == 0) ||
               (strcmp(first_color, "blue") == 0 && strcmp(second_color, "red") == 0)) {
        mixed_color = "purple";
    } else if ((strcmp(first_color, "red") == 0 && strcmp(second_color, "yellow") == 0) ||
               (strcmp(first_color, "yellow") == 0 && strcmp(second_color, "red") == 0)) {
        mixed_color = "orange";
    } else {
        mixed_color = "green";
    }

    cout << "Mixed color: " << mixed_color << endl;
    return 0;
}
