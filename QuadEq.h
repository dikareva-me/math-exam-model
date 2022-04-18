#pragma once



class EqRoots {
public:
	enum class numRoots {
		ZERO,
		ONE,
		TWO
	};
	double _x1;
	double _x2;
	numRoots _numRoots;

	EqRoots() :_x1(0), _x2(0), _numRoots(numRoots::ZERO) {}

};

class QuadEq {
public:
	double _a, _b, _c;
	//EqRoots _root;
	QuadEq() : _a(0), _b(0), _c(0) {}
	QuadEq(const double a, const double b, const double c) : _a(a), _b(b), _c(c) {}
	EqRoots eqSolve();
};
