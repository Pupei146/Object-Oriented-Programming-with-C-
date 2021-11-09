#include <iostream>
#include "probability.h"
using namespace std;

void main()
{
	probability A;
	probability B;
	probability C;
	probability D;
	probability E;
	probability F;
	probability G;

	A.like_setter(0.3);
	B.like_setter(0.4);

	cout << "The probability of A: " << A.like_getter() << endl;
	cout << "The probability of B: " << B.like_getter() << endl;

	C = A & B;
	cout << "The probability of both A and B occurring: " << C.like_getter() << endl;

	D = A | B;
	cout << "The probability of either A or B occurring: " << D.like_getter() << endl;

	E = A ^ B;
	cout << "The probability of either A or B but not both occurring: " << E.like_getter() << endl;

	F = A - B;
	cout << "The probability of A but not B occurring: " << F.like_getter() << endl;

	G = ~ A;
	cout << "The probability of A not occurring: " << G.like_getter() << endl;

	cout << endl;

	A.like_setter(0.2);
	B.like_setter(0.5);

	cout << "The probability of A: " << A.like_getter() << endl;
	cout << "The probability of B: " << B.like_getter() << endl;

	C = A & B;
	cout << "The probability of both A and B occurring: " << C.like_getter() << endl;

	D = A | B;
	cout << "The probability of either A or B occurring: " << D.like_getter() << endl;

	E = A ^ B;
	cout << "The probability of either A or B but not both occurring: " << E.like_getter() << endl;

	F = A - B;
	cout << "The probability of A but not B occurring: " << F.like_getter() << endl;

	G = ~A;
	cout << "The probability of A not occurring: " << G.like_getter() << endl;


}