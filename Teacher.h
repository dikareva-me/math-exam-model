#pragma once
#include <iostream>
#include "Student.h"
#include "QuadEq.h"
#include <vector>
#include <string>
using namespace std;

struct result {
	result(const string& name_) : name(name_), numCorrectSolved(0) {}
	string name;
	int numCorrectSolved;
};

class Teacher {
public:
	Teacher(string& name) noexcept : _name(name) {}
	Teacher(const Teacher& teacher) noexcept : _name(teacher._name) {}
	friend void Student::sendEmail(Teacher& teacher, vector <QuadEq> eqList) const;
	void checkSolutions();
	void printResults() const;
	void clearResults();
	void clearEmails();
	bool cmpRoots(email& checkEq);
private:
	string _name;
	std::vector<email> _emails;
	std::vector <result> _results;
};

