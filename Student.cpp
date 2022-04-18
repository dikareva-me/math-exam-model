#pragma once
#include "Teacher.h"
#include <fstream>
#include <vector>
#define OKAY_STUDENT_PROBABILITY 0.5


vector <QuadEq> readFile(const string& filename, vector <QuadEq> eqList) {
	ifstream fileIn(filename);
	if (!fileIn.is_open())
		throw runtime_error(string("Failed to open file"));
	QuadEq newEq;
	string str;
	while(fileIn >> newEq._a >> newEq._b >> newEq._c) {
		eqList.push_back(newEq);
		if (fileIn.fail())
			break;
	}
	return eqList;
}

void Student::sendEmail(Teacher& teacher, vector <QuadEq> eqList) const {
	for (int i = 0; i < eqList.size(); ++i)
		teacher._emails.push_back(email(eqList[i], _roots.at(i), _name));
}

void GoodStudent::solveEq(vector <QuadEq> eqList){
	for (int i = 0; i < eqList.size(); ++i) 
		_roots.push_back(eqList[i].eqSolve());

}

void OkayStudent::solveEq(vector <QuadEq> eqList) {
	EqRoots root;
	for (int i = 0; i < eqList.size(); ++i) {
		root = rand() / (double)RAND_MAX < OKAY_STUDENT_PROBABILITY ? eqList[i].eqSolve() : EqRoots();
		_roots.push_back(root);
	}
}

void BadStudent::solveEq(vector <QuadEq> eqList) {
	for (int i = 0; i < eqList.size(); ++i)
		_roots.push_back(EqRoots());
}