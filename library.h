#include <string>
#include <fstream>

using namespace std;
const int SIZE=10;
//Do not alter the definition for Student
struct Student {
  string ID;
  string name;
  unsigned unitsAttempted;
  unsigned unitsEarned;
  double gpa;
};

//This function retrieves one student data from “records.csv” file and stores them in the  parameter s.
void getOneStudent(ifstream& input, Student& s);
//This function displays data for all students in a nice columnized format. The IDs and student names shall be left justified while the other columns shall be right justified. In addition, display the GPA using three digits after the decimal point and show trailing 0s.
void displayAllStudents(const Student arr[], int n);

//This function returns the index of the Student object in the array whose ID matches the id parameter.
int findStudent(const Student arr[], int n, const string& id);

//This function updates the unitsAttempted, unitsEarned, and gpa data members of the parameter s using the values provided in the parameters units and letter.
void updateStudent(Student& s, int units, char letter);

//This function sorts the array of Student objects based on when they started with the university. 
void sortByStartSession(Student arr[], int n);
