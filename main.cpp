#include <iostream>
#include "library.h"
using namespace std;



int main() {
int SIZE=10;
Student sar[SIZE];
ifstream fin;
Student s;
int total=0;
string class_name;
char grade;
int units;
string Id;
//int index;
//int units;
//char grade;
//int unitsAttempted;
//int unitsEarned;

cout<<"Before Processing records.csv"<<endl;
fin.open("records.csv");
int i = 0;//gets a total of 8 students
while(!fin.eof())
{
  getOneStudent(fin,sar[i]);
  i++;
}
fin.close();
displayAllStudents(sar,i);
cout<<"After processing records.csv"<<endl;
fin.open("grades.csv");
int index;
int num_index=0;
while(!fin.eof())
{
  getline(fin,Id,',');
  getline(fin,class_name,',');
  fin>>units;
  fin.ignore();
  fin>>grade;
  //index=findStudent(sar,SIZE,Id);
  updateStudent(sar[num_index],units,grade);
  num_index++;
}
displayAllStudents(sar, i);

cout<<"After sorting"<<endl;
sortByStartSession(sar, i);
displayAllStudents(sar, i);
