#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>

class Roster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;

public:
	Student* classRosterArray[numStudents] = {};
	void parse(string row);
	void add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, 
		int days1, int days2, int days3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};