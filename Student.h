#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <queue>
#include <any>
#include <vector>
#include <iomanip>
#include "QuadEq.h"

using namespace std;

class Teacher;

vector <QuadEq> readFile(const string& filename, vector <QuadEq> eqs);

struct email {
	QuadEq eq;
	const EqRoots root;
	const string name;
	email(QuadEq& eq_, const EqRoots& eqRoots_, const string& name_) :
		eq(eq_), root(eqRoots_), name(name_) {}
};

class Student {
public:
	Student(const string& name) : _name(name) {}
	Student() : _name("Unindentified Student") {}
	string getName() { return _name; }
	void sendEmail(Teacher& teacher, vector <QuadEq> eqList) const;
	virtual void solveEq(vector <QuadEq> eqList) = 0;
protected:
	const string _name;
	vector <EqRoots> _roots;
};

class GoodStudent : public Student {
public:
	GoodStudent() : Student() {};
	GoodStudent(const string& name)  : Student(name) {};
	void solveEq(vector <QuadEq> eqList) override;
};


class OkayStudent : public Student {
public:
	OkayStudent() : Student() {};
	OkayStudent(const string& name) : Student(name) {};
	void solveEq(vector <QuadEq> eqList) override;
};

class BadStudent : public Student {
public:
	BadStudent() : Student() {};
	BadStudent(const string& name) : Student(name) {};
	void solveEq(vector <QuadEq> eqList) override;
};