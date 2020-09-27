#include <iostream>
#include "library.h"
using namespace std;



int main() {
int SIZE=10;
Student sar[SIZE];
ifstream fin;
Student s;
string class_name;
char grade;
int units;
string Id="";

cout<<"Before Processing records.csv"<<endl;
fin.open("records.csv");
int i = 0;//gets a total of 8 students
while(!fin.eof())
{
  getOneStudent(fin,sar[i]);
  i++;//increments so that sar gets all the students data
}
fin.close();
displayAllStudents(sar,i);
cout<<"After processing grades.csv"<<endl;
fin.open("grades.csv");
int index;
int num_index=0;
int total_units=0;
findStudent(sar,SIZE,Id);
while(!fin.eof())
{

  getline(fin,Id,',');
  getline(fin,class_name,',');
  fin>>units;
  fin.ignore();
  fin>>grade;
  updateStudent(sar[num_index],units,grade);
  num_index++;
}
displayAllStudents(sar,i);



cout<<"After sorting"<<endl;
sortByStartSession(sar, i);
displayAllStudents(sar, i);

return 0;
}


