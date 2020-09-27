#include "library.h"
#include <iostream>
#include <iomanip>

//Use this file to include the implementations of your functions.

void getOneStudent(ifstream& input, Student& s)
{
//string Id;

//while (!input.eof())//{ 
getline(input,s.ID,',' );//Getting ID from students
getline(input,s.name,',');//Getting name from file
input>>s.unitsAttempted;//getting the units attempted
input.ignore();
input>>s.unitsEarned;
input.ignore();
input>>s.gpa;
}
//end of getOneStudent

void displayAllStudents(const Student arr[], int n) 
{ 
for(int i=0;i<n;i++)
{
cout<<arr[i].ID<<"    "<<left<<setw(25)<<arr[i].name<<setw(10)<<arr[i].unitsAttempted<<setw(8)<<arr[i].unitsEarned<<setw(8)<<fixed<<setprecision(3)<<arr[i].gpa<<endl;
}//end of displayAllStudents
}

int findStudent(const Student arr[], int n, const string& id) 
{
  for(int i=0;i<n;i++)
  {
  if(arr[i].ID==id)
    return i;
  }
 return -1;//end of findStudent
}
void updateStudent(Student& s, int units, char letter)
{
int units_received=0;
if(letter=='A')
{
units_received=4;
}
else if(letter=='B')
{
units_received=3;
}
else if(letter=='C')
{
units_received=2;
}
else if(letter=='D')
{
units_received=1;
}
else
{
units_received=0;
}

s.unitsAttempted=s.unitsAttempted+units;
s.unitsEarned=s.unitsEarned+units_received;
s.gpa=(s.unitsAttempted *s.gpa+units*units_received) / (s.unitsAttempted+units);
//(units attempted * old gpa + new units * new grade point) / (unitsattempted + new units).
} //end of updateStudent

void sortByStartSession(Student arr[], int n)
{
for(int i=0;i<n-1;i++)//one by onw movw the boundary of unsorted subarray
{
  //find minimum element in unsorted array
 int min_index = i;
  for (int j = i+1; j < n; j++)
  {
  if (arr[j].ID.substr(1,2)<arr[min_index].ID.substr(1,2))
   min_index = j;
  swap(arr[min_index],arr[i]);
  }
}
}
