#include <iostream>
#include <string>

using namespace std;

// Define constants
const int START_SUPERBOWL = 1967;
const int MIN_ROMAN = 1;
const int MAX_ROMAN = 3999;
const int MIN_YEAR = 1967;
const int MAX_YEAR = 5965;


// Function to convert an integer to its  Roman numeral
string roman_numeral(int n) {
    // Define arrays for Roman numeral characters
    string thousands[] = {"", "M", "MM", "MMM"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    // Convert each digit into its Roman numeral counterpart
    string roman = thousands[n / 1000] + hundreds[(n % 1000) / 100] + tens[(n % 100) / 10] + ones[n % 10];

    return roman;
}
// Function to print the Super Bowl message
void print_message() {
    cout << "***********************************************************" << endl;
    cout << "*     The Super Bowl is the annual final playoff game     *" << endl;
    cout << "*         of the NFL to determine the league champion     *" << endl;
    cout << "* The first Super Bowl took place on January 15, 1967.   *" << endl;
    cout << "*    Super Bowl I (Los Angeles Memorial Coliseum) --> 1967*" << endl;
    cout << "* This Roman Numerals Converter is written by Zac Thompson.*" << endl;
    cout << "* If you had a time machine, which year of Super Bowl     *" << endl;
    cout << "*   you want to attend (1967 - 5965)?                    *" << endl;
    cout << "***********************************************************" << endl;
    cout << "Please enter the year you want to attend (or 'Q' to quit): ";
}


int main() {
    string input;

    do {
        print_message();
        cin >> input;

        // Check if the input is a character 'Q' or 'q' to quit
        if (input == "Q" || input == "q") {
            cout << "Thank you for using my program." << endl;
            break; // Exit the loop
        }

        // Check if the input contains only digits
        bool validInput = true;
        for (char c : input) {
            if (!isdigit(c)) {
                validInput = false;
                break;
            }
        }
        // if the input doesn't contain only digits valid input is false
        if (!validInput) {
            cout << "Invalid input. Please enter a valid year or 'Q' to quit." << endl;
            continue;
        }

        // Convert the string input to an integer year
        int year = stoi(input);

        // Check if the year is within the valid range
        if (year >= MIN_YEAR && year <= MAX_YEAR) {
            int superBowlNumber = year - START_SUPERBOWL + 1;
            if (superBowlNumber >= MIN_ROMAN && superBowlNumber <= MAX_ROMAN) {
                string roman = roman_numeral(superBowlNumber);
                cout << year << " is Super Bowl " << roman << "." << endl;
            } else {
                cout << "Year out of range. Please enter a year between " << MIN_YEAR << " and " << MAX_YEAR << " or 'Q' to quit." << endl;
            }
        } else {
            cout << "Year out of range. Please enter a year between " << MIN_YEAR << " and " << MAX_YEAR << " or 'Q' to quit." << endl;
        }
    //do loop while true
    } while (true);

    return 0;
}