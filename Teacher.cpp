#include "Teacher.h"
#include <fstream>

bool Teacher::cmpRoots(email& checkEq) {
	EqRoots correctRoot = checkEq.eq.eqSolve();
	if (correctRoot._numRoots == checkEq.root._numRoots
		&& (correctRoot._x1 == checkEq.root._x1 && correctRoot._x2 == checkEq.root._x2
			|| correctRoot._x1 == checkEq.root._x2 && correctRoot._x2 == checkEq.root._x1))
		return true;
	else 
		return false;
}

void Teacher::checkSolutions() {
	bool isStudentAccounted;
	for (int i = 0; i < _emails.size(); i++) {
		isStudentAccounted = 0;
		for (int j = 0; j < _results.size(); ++j)
			if (_emails[i].name == _results[j].name) {
				isStudentAccounted = 1;
				if (cmpRoots(_emails[i])) 
					++_results[j].numCorrectSolved;
				break;
			}

		if (isStudentAccounted == 0) {
			_results.push_back(result(_emails[i].name));
			if (cmpRoots(_emails[i]))
				++_results.back().numCorrectSolved;
		}
	}
}

void Teacher::printResults() const {
	setlocale(LC_ALL, "Russian");
	int nameLength = 40;
	cout << "Students' names" << "\t\t " << "Solved correctly" << endl;
	for (auto& result : _results)
		cout << result.name << "\t\t " << result.numCorrectSolved << endl;
}


void Teacher::clearResults() {
	_results.clear();
}

void Teacher::clearEmails() {
	_emails.clear();
}