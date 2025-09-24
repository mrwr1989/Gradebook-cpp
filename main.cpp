#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//constants
const int maxstudents = 150;
const int numtests = 10;

//function declarations
int readDatafromfile(string filename, string names[], int tests[][numtests]);
void calculateaverages(int tests[][numtests], double averages[], int numstudents);
char getlettergrade(double average);
void printresults(string names[], double averages[], int numstudents);

//main function
int main() {
    string names[maxstudents];
    int tests[maxstudents][numtests];
    double averages[maxstudents];
    int numstudents;
    
    numstudents = readDatafromfile("students.txt", names, tests);
    if (numstudents == -1) {
        cout << "Error opening file" << endl; 
        return 1;
    }
    
    calculateaverages(tests, averages, numstudents);
    printresults(names, averages, numstudents);
    
    return 0;
}

//readDatafromfile function
int readDatafromfile(string filename, string names[], int tests[][numtests]) {
    ifstream infile(filename);
    if (!infile) {
        return -1;
    }
    
    int count = 0;
    string header;
    getline(infile, header); // Skip header line
    
    while (count < maxstudents && infile >> names[count]) {
        for (int i = 0; i < numtests; i++) {
            infile >> tests[count][i];
        }
        count++;
    }
    
    infile.close();
    return count;
}

//calculateaverages for each student
void calculateaverages(int tests[][numtests], double averages[], int numstudents) {
    for (int i = 0; i < numstudents; i++) {
        double sum = 0;
        for (int j = 0; j < numtests; j++) {
            sum += tests[i][j];
        }
        averages[i] = sum / numtests;
    }
}

//getlettergrade function
char getlettergrade(double average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

//printresults function
void printresults(string names[], double averages[], int numstudents) {
    cout << "Student Name\tAverage\tLetter Grade" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < numstudents; i++) {
        cout << names[i] << "\t\t" << averages[i] << "\t" << getlettergrade(averages[i]) << endl;
    }
}