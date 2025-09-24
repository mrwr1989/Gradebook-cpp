using namespace std;
// constants
const int maxstudents = 150;
const int numtests = 10;
// function declarations
int readDatafromfile(string filename, int students[], int tests[][numtests]);
void calculateaverages(int tests[][numtests], double averages[],
                       int numstudents);)
char getlettergrade(double average);
void printresults(int students[], double averages[], int numstudents);
// main function
int main() string names[maxstudents];
int tests[maxstudents][numtests];
double averages[maxstudents];
int numstudents;
ifstream numstudents = readDatafromfile("students.txt", names, tests);
if (not infile) {
  cout << "Error opening file" << endl;
  return 1;
}
students = readDatafromfile("students.txt", names, tests);
calculateaverages(tests, averages, numstudents);
printresults(names, averages, numstudents);
infile.close();
return 0;
}
// readDatafromfile function
int readDatafromfile(string filename, int students[],
                     int tests[][numtests]) int numstudents = 0;
while (count < maxstudents && infile >> names[count]) {
  for (int i = 0; i < numtests; i++) {
    infile >> tests[count][i];
  }
  count++;
}
}
// calculateaverages for each student
void calculateaverages(int tests[][numtests], double averages[],
                       int numstudents) for (int i = 0; i < numstudents; i++) {
  double sum = 0;
  for (int j = 0; j < numtests; j++) {
    sum += tests[i][j];
  }
  averages[i] =
      // getlettergrade function
      char getlettergrade(double average) if (average >= 90) {
    return 'A';
  }
  else if (average >= 80) {
    return 'B';
  }
  else if (average >= 70) {
    return 'C';
  }
  else if (average >= 60) {
    return 'D';
  }
  else {
    return 'F';
  }
  // printresults function
  void printresults(int students[], double averages[], int numstudents) cout
      << "Student Name\tAverage\tLetter Grade" << endl;
