#pragma once
#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	for (int i = 0; i < gradesArraySize; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::UNDECIDED;
}

Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
	int studentAge, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < gradesArraySize; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

//Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->studentFirstName; }
string Student::getLastName() { return this->studentLastName; }
string Student::getEmail() { return this->studentEmail; }
int Student::getAge() { return this->studentAge; }
int* Student::getDays() { return this->daysInCourse; }
DegreeProgram Student::getProgram() { return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->studentFirstName = firstName; }
void Student::setLastName(string lastName) { this->studentLastName = lastName; }
void Student::setEmail(string email) { this->studentEmail = email; }
void Student::setAge(int age) { this->studentAge = age; }
void Student::setDays(int days[]) {
	for (int i = 0; i < gradesArraySize; ++i) {
		this->daysInCourse[i] = days[i];
	}
}
void Student::setProgram(DegreeProgram program) { this->degreeProgram = program; }

void Student::print() {
	cout << this->getID() << "\t";
	cout << this->getFirstName() << " ";
	cout << this->getLastName() << "\t";
	cout << this->getEmail() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getDays()[0] << ", "; 
	cout << this->getDays()[1] << ", ";
	cout << this->getDays()[2] << "\t";
	cout << programStrings[this->getProgram()] << "\n";
}