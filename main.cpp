#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constants
const int maxstudents = 150;
const int numtests = 10;

// Function declarations
int readDatafromfile(string filename, string students[], int tests[][numtests]);
void calculateaverages(int tests[][numtests], double averages[], int numstudents);
char getlettergrade(double average);
void printresults(string students[], double averages[], int numstudents);

// Main function
int main() {
    string students[maxstudents];
    int tests[maxstudents][numtests];
    double averages[maxstudents];
    int numstudents;

    numstudents = readDatafromfile("students.txt", students, tests);
    if (numstudents == -1) {
        cout << "Error opening file" << endl;
        return 1;
    }

    calculateaverages(tests, averages, numstudents);
    printresults(students, averages, numstudents);

    return 0;
}

// Read data from file
int readDatafromfile(string filename, string students[], int tests[][numtests]) {
    ifstream infile(filename);
    if (!infile) return -1;

    int count = 0;
    while (count < maxstudents && infile >> students[count]) {
        for (int i = 0; i < numtests; i++) {
            infile >> tests[count][i];
        }
        count++;
    }

    infile.close();
    return count;
}

// Calculate averages
void calculateaverages(int tests[][numtests], double averages[], int numstudents) {
    for (int i = 0; i < numstudents; i++) {
        double sum = 0;
        for (int j = 0; j < numtests; j++) {
            sum += tests[i][j];
        }
        averages[i] = sum / numtests;
    }
}

// Get letter grade
char getlettergrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Print results
void printresults(string students[], double averages[], int numstudents) {
    cout << "Student Name\tAverage\tLetter Grade" << endl;
    for (int i = 0; i < numstudents; i++) {
        cout << students[i] << "\t" << averages[i] << "\t" << getlettergrade(averages[i]) << endl;
    }
}
