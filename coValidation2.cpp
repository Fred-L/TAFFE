#include <iostream>
#include <string>

using namespace std;

string coordinate;

string validCoord();

int main() {
	cout << validCoord();

	return 0;
}

string validCoord() {
	while (true) {
		cout << "Enter coordinate of the peg you want to be moved: ";
		cin >> coordinate;
		if (coordinate.size() == 2) {

			if (coordinate[0] == 'a')
				if (coordinate[1] == '1' || coordinate[1] == '2' || coordinate[1] == '3' || coordinate[1] == '4' || coordinate[1] == '5')
					break;

			if (coordinate[0] == 'b')
				if (coordinate[1] == '1' || coordinate[1] == '2' || coordinate[1] == '3' || coordinate[1] == '4')
					break;

			if (coordinate[0] == 'c')
				if (coordinate[1] == '1' || coordinate[1] == '2' || coordinate[1] == '3')
					break;

			if (coordinate[0] == 'd')
				if (coordinate[1] == '1' || coordinate[1] == '2')
					break;

			if (coordinate[0] == 'e')
				if (coordinate[1] == '1')
					break;
		}
		cout << "Invalid coordinate, please enter a column from a - e and row from 1 - 5. (example: a1)\n\n";
	}
	return coordinate;
}



