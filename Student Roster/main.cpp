#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
using namespace std;

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Thomas,Kroll,tlkroll@pm.me,41,14,15,20,SOFTWARE"
	};

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; ++i) {
		classRoster.parse(studentData[i]);
	}

	cout << "Application created for C++ course" << endl << endl << "Student: Thomas Kroll" << endl <<
		"Student ID #: 999999" << endl << "Programming Language: C++ 14 " << endl << endl;

	cout << "All students in class roster:" << endl << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Invalid emails:" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	for(int i = 0; i < 5; ++i){
		string currStudent = classRoster.classRosterArray[i]->getID();
		cout << "Student " << currStudent << " has spent an average of ";
		classRoster.printAverageDaysInCourse(currStudent);
		cout << " days per class over three classes." << endl;
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	cout << "Updated class roster after removing A3:" << endl << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Attempt to remove A3 after already removed:" << endl << endl;
	classRoster.remove("A3");
	cout << endl << endl;
}
