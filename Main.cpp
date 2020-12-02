#include <iostream>
#include "DataMoverTM.h"

int main()
{
	using namespace std;
	DataMoverTM dm;

	dm.SetType(-1);
	dm.AddIntData(1);
	dm.AddFloatData(2.0f);
	dm.AddStringData(string("three").c_str());
	dm.AppendLine();

	dm.SetType(2);
	dm.AddIntData(-1);
	dm.AddFloatData(-2.0f);
	dm.AddStringData(string("negativeThree").c_str());
	dm.AppendLine();
	
	if (dm.WriteFile()) {
		cout << "file written" << endl;

		if (dm.ReadFile()) {
			cout << "file read" << endl;

			if (dm.ReadLines()) {
				cout << "lines read" << endl;

				cout << "--BEGIN FILE PRINT--" << endl;
				for (int i = 0; i < dm.GetNumLines(); i++) {
					cout << dm.GetLine(i) << endl;
				}
				cout << "--END FILE PRINT--" << endl;
			}
			else {
				cout << "error reading lines" << endl;
			}
		}
		else {
			cout << "error reading file" << endl;
		}
	}
	else {
		cout << "error writing file" << endl;
	}

	cout << "eop" << endl;
}