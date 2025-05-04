
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
const int SUBJECTS = 3;

class Student {
private:
    string name;
    int roll;
    int marks[SUBJECTS];
    int total;
    double percentage;
    char grade;

public:
    void input() {
        cout << "Name: ";

    //! cin.ignore();
        //?  This discards (ignores) any leftover characters in the input buffer.
        //?  Most commonly, it ignores the newline character (\n) left in the buffer 
        //?      after a previous cin >> operation.
        //?  Without it, getline() might read an empty line.

    //! getline(cin, name);
        //?  This reads an entire line of input (including spaces) into the name string.
        //?  Unlike cin >> name; (which stops at whitespace), getline() reads until a 
        //?     newline is encountered.
        //*  This allows for names with spaces (e.g., "John Doe").

        cin.ignore();
        getline(cin, name);
        cout << "Roll Number: ";
        cin >> roll;

        cout << "Enter marks for 3 subjects (Math, Science, English):\n"; 
        for (int i = 0; i < SUBJECTS; ++i) {
            cout << "  Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }

        calculate();
    }

    void calculate() {
        total = 0;
        for (int i = 0; i < SUBJECTS; ++i)
            total += marks[i];

        //! Using a static_cast to ensure double division
        //~ This avoids integer division which would truncate the result

        //* “truncate” means to cut off the fractional part of a number, 
        //& leaving only the integer portion. Unlike rounding—which might push a 
        //? value up or down—truncation simply drops everything after the decimal point.
        //*  For example, truncating 5.9 would yield 5, while truncating -2.3 would yield -2.

        percentage = static_cast<double>(total) / SUBJECTS;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else if (percentage >= 50)
            grade = 'E';
        else
            grade = 'F';
    }

    void display() const {
        cout << "--------------------------------------\n";
        cout << "Report Card for " << name << " (Roll No: " << roll << ")\n";
        cout << "--------------------------------------\n";
        cout << "Subject    : Marks\n";
        cout << "--------------------------------------\n";
        cout << "Math       : " << marks[0] << "\n";
        cout << "Science    : " << marks[1] << "\n";
        cout << "English    : " << marks[2] << "\n";
        cout << "--------------------------------------\n";
        cout << "Total      : " << total << "\n";

        // *  Using setf and unsetf to control the formatting of floating-point output
        //?  This allows us to specify how we want the floating-point number to be displayed.
        //?  In this case, we want to display it in fixed-point notation with two decimal places.
        cout.setf(ios::fixed);
        // *  The precision() function sets the number of digits to be displayed after the decimal point.
        //?  In this case, we set it to 2, meaning we want to display two decimal places.
        cout.precision(2);
        cout << "Percentage : " << percentage << "%\n";
        cout.unsetf(ios::floatfield);
        cout << "Grade      : " << grade << "\n\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    cin >> n;
    if (n < 1 || n > MAX_STUDENTS) {
        cout << "Invalid number of students. Please run again." << endl;
        return 1;
    }

    Student students[MAX_STUDENTS];
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for student " << (i + 1) << " ---" << endl;
        students[i].input();
    }

    cout << "\n\n**** STUDENT REPORT CARDS ****\n";
    for (int i = 0; i < n; ++i) {
        students[i].display();
    }

    return 0;
}
