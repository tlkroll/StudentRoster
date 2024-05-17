#pragma once
#include "roster.h"
#include "degree.h"
#include <iostream>
using namespace std;

void Roster::parse(string row) {
	int rhs = row.find(',');
	string sID = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(',', lhs);
	string sFN = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	string sLN = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	string sEmail = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	int sAge = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	int days1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	int days2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	int days3 = stoi(row.substr(lhs, rhs - lhs));

	char lastChar = row.back();
	DegreeProgram degree = UNDECIDED;

	switch (lastChar)
	{
	case 'Y':
		degree = SECURITY;
		break;
	case 'K':
		degree = NETWORK;
		break;
	case 'E':
		degree = SOFTWARE;
		break;
	default:
		degree = UNDECIDED;
		break;
	}
	add(sID, sFN, sLN, sEmail, sAge, days1, days2, days3, degree);
}

void Roster::add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, 
	int days1, int days2, int days3, DegreeProgram degreeProgram) {

	int days[3] = { days1, days2, days3 };

	classRosterArray[++lastIndex] = new Student(studentID, studentFirstName, studentLastName, studentEmail, studentAge,
		days, degreeProgram);
}

void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students pursuing " << programStrings[degreeProgram] << " degree:" << endl << endl;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (Roster::classRosterArray[i]->getProgram() == degreeProgram) {
			classRosterArray[i]->print();	
		}
	}
}

void Roster::printInvalidEmails() {
	bool invalidEntries = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		string sEmail = (classRosterArray[i]->getEmail());
		if ((sEmail.find('@') == string::npos || sEmail.find('.') == string::npos) || sEmail.find(' ') != string::npos) {
			invalidEntries = true;
			cout << sEmail << " is invalid" << endl;
		}
	}
	if (!invalidEntries) {
		cout << "No invalid entries" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (classRosterArray[i]->getID() == studentID) {
			cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) / 3;
		}
	}
}

void Roster::remove(string studentID) {
	bool studentFound = false;
	for (int i = 0; i <= Roster::lastIndex; ++i) {
		if (classRosterArray[i]->getID() == studentID) {
			studentFound = true;
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
			cout << studentID << " removed from roster." << endl;
		}
	}
	if (!studentFound) {
		cout << "Student ID not found." << endl;
	}
}

Roster::~Roster(){
	cout << "Destructor called - freeing memory..." << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Removing student " << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}