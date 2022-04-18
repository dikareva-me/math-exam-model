#include <iostream>
#include <fstream>
#include "QuadEq.h"


EqRoots QuadEq::eqSolve() {
	double D = 0.0f;
	D = _b * _b - 4.0 * _a * _c;
	EqRoots root;
	if (D >= 0.0f) {
		D = sqrt(D);
		root._x1 = (-_b + D) / (2.0 * _a);
		root._x2 = (-_b - D) / (2.0 * _a);
		if (D == 0.0f)
			root._numRoots = EqRoots::numRoots::ONE;
		else
			root._numRoots = EqRoots::numRoots::TWO;
	}
	else
		root._numRoots = EqRoots::numRoots::ZERO;
	return root;
}
