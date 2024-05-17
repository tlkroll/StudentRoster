#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
	public:
		const static int gradesArraySize = 3;
		Student();
		Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, 
			int studentAge, int daysInCourse[], DegreeProgram degreeProgram);
		//~Student();

		string getID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDays();
		DegreeProgram getProgram();

		void setID(string ID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDays(int days[]);
		void setProgram(DegreeProgram program);

		void print();

	private:
		string studentID;
		string studentFirstName;
		string studentLastName;
		string studentEmail;
		int studentAge;
		int daysInCourse[gradesArraySize];
		DegreeProgram degreeProgram;
};

