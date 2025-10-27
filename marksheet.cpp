#include <iostream>
#include <iomanip> // for setw()
#include <string>
using namespace std;

class Student {
private:
    string name;
    int roll;
    int mark[5];
    int total = 0;

public:
    float perc = 0.0;

    void input(int i) {
        cout << "\nStudent " << i + 1 << " Details:\n";

        cout << "Enter Name: ";
        cin.ignore(); // clears any leftover input buffer
        getline(cin, name);

        cout << "Enter Roll No: ";
        cin >> roll;

        cout << "Enter Marks for 5 subjects (C++, Stats, Maths, R Programming, FA):\n";
        total = 0;
        for (int i = 0; i < 5; i++) {
            cin >> mark[i];
            total += mark[i];
        }

        perc = (total / 500.0f) * 100;
    }

    void display(int i) {
        cout << left << setw(4) << i + 1
             << setw(15) << name
             << setw(8) << roll;
        for (int j = 0; j < 5; j++) {
            cout << setw(8) << mark[j];
        }
        cout << fixed << setprecision(2) << perc << "%" << endl;
    }

    float markperc() const {
        return perc;
    }

    void topper() {
        cout << "🏆 Topper of the Class 🏆\n";
        cout << "Name        : " << name << endl;
        cout << "Roll Number : " << roll << endl;
        cout << "Percentage  : " << fixed << setprecision(2) << perc << "%" << endl;
    }
};

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    Student s[n];

    cout << "\n===== Enter Student Details =====\n";
    for (int i = 0; i < n; i++) {
        s[i].input(i);
    }

    cout << "\n===== Student Marksheet =====\n\n";
    cout << left << setw(4) << "No"
         << setw(15) << "Name"
         << setw(8) << "Roll"
         << setw(8) << "C++"
         << setw(8) << "Stats"
         << setw(8) << "Maths"
         << setw(8) << "R-Pro"
         << setw(8) << "FA"
         << "Percentage" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < n; i++) {
        s[i].display(i);
    }

    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].markperc() > s[topperIndex].markperc()) {
            topperIndex = i;
        }
    }

    cout << "\n===== Topper Details =====\n\n";
    s[topperIndex].topper();

    return 0;
}
