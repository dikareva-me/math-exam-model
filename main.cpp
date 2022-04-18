#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "QuadEq.h"
#include "Student.h"
#include "Teacher.h"
#define NUM_EQ 50
#define MAX_KOEF 100.0
#define MIN_KOEF -100.0
using namespace std;


const vector<string> studentNames = { "Polina Soboleva", "Julia Danilova", "Maria Sergeeva",
"Valeria Volkova", "Daria Lebedeva"};

inline double Random() {
    return rand() / (double)RAND_MAX * (MAX_KOEF - MIN_KOEF) + MIN_KOEF;
}

vector<unique_ptr<Student>> generateStudents() {
    vector<unique_ptr<Student>> students;
	for (int i = 0; i < studentNames.size(); ++i) {
        switch (rand() % 3) {
        case 0:
            students.push_back(make_unique<BadStudent>(studentNames[i]));
            break;
        case 1:
            students.push_back(make_unique<OkayStudent>(studentNames[i]));
            break;
        case 2:
            students.push_back(make_unique<GoodStudent>(studentNames[i]));
            break;
        }
	}
    return students;
}

void generateQuadEqs(const string& filename) {
    ofstream fileOut(filename);
    if (!fileOut.is_open())
        throw runtime_error(string("Failed to open file"));
    for (int i = 0; i < NUM_EQ; ++i)
        fileOut << Random() << " " << Random() << " " << Random() << "\n";
    fileOut.close();
}

void studentsWork(const vector<unique_ptr<Student>>& students, 
    const string& filename, Teacher& teacher) {
    vector <QuadEq> eqList;
    eqList = readFile(filename, eqList);
    for (int i = 0; i < students.size(); ++i) {
        students[i]->solveEq(eqList);
        students[i]->sendEmail(teacher, eqList);
    }
    teacher.checkSolutions();
    teacher.printResults();
}
//for some reason there is 31 eqs instead of 30
int main() {
    const string filename = "input.txt";
    string nameTeacher = "Moiseev-a-a";
    Teacher teacher(nameTeacher);
    generateQuadEqs(filename);
    auto students = generateStudents();
    studentsWork(students, filename, teacher);
    
    return 0;
}