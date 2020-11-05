#include <iostream>
#include <string>
#include "TriangleArea.h"
using namespace std;

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const string CONTINUE_MESSAGE = "Continue? (Y/N)>";
const string INCORRECT_MESSAGE = "Input is incorrect. Try again>";
const string SKIP_CHARACTERS = " ";
const string ABOUT_MESSAGE = "Input vertex coordinates separated by a space. Like this: x1 y1 x2 y2 x3 y3>";
const string OUT_OF_BOUNDS_MESSAGE = "This number is out of bounds";
const string TITLE = "Area of a triangle with integer vertex coordinates.";

void ClearInputStream(istream &in)
{
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF) 
	{
		in.get();
	}
}

//ищет следующий пробел или перенос строки
int Seek(istream &in)
{
	while (in.peek() != EOLN && SKIP_CHARACTERS.find((char)in.peek()) != string::npos)
	{
		in.get();
	}
	return in.peek();
}

bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <=
		RIGHT_BOUND);
	if (!ok)
	{
		cout << OUT_OF_BOUNDS_MESSAGE << "[" << LEFT_BOUND << ", " << RIGHT_BOUND << "]" << endl;
	}
	return ok;
}

bool NeedContinue(istream &in)
{
	cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR && ans != NO_CHAR)
	{
		ClearInputStream(in);
		cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main()
{
	cout << TITLE << endl;
	bool cont = true;
	while (cont)
	{
		cout << ABOUT_MESSAGE << endl;
		int* vx = new int[6];
		bool c = true;
		do {
			c = true;
			for (int i = 0; i < 6; i++) {
				cin >> vx[i];
				if (!cin)
				{
					ClearInputStream(cin);
					cout << INCORRECT_MESSAGE;
					c = false;
					break;
				}
			}
		} while (!c);

		cout << "Vertex coordinates: ";
		for (int i = 0; i < 3; i++) {
			cout << "(" << vx[i*2] << ", " << vx[i*2 + 1] << ") ";
		}
		cout << endl;

		// подсчет площади
		double ans = TriangleArea(vx);
		cout << "Result: " << ans << endl;
		delete[] vx;

		cont = NeedContinue(cin);
	}
	return 0;
}