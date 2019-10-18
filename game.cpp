#include <iostream>
#include <string>

using namespace std;

//Display game board
const int MAXPEGS = 15;
const int MAXRULE = 38;
void displayBoard();
void displayLine5();
void displayLine4();
void displayLine3();
void displayLine2();
void displayLine1();
char pegs[MAXPEGS];

//Input and validate coordinate
string validCoord(string prompt);

//convert coordinate to index
int coord2Index(string coord);

//Remove a peg
void removePeg(string coord);

//Validate a jump
bool validJump(int oIndex, int dIndex);

bool validJump2(int oIndex, int dIndex);

//2D array to store list of possible moves
int rule[MAXRULE][3] = {
{	0	,	2	,	1	},
{	0	,	9	,	5	},
{	1	,	3	,	2	},
{	1	,	10	,	6	},
{	2	,	0	,	1	},
{	2	,	4	,	3	},
{	2	,	9	,	6	},
{	2	,	11	,	7	},
{	3	,	1	,	2	},
{	3	,	10	,	7	},
{	4	,	2	,	3	},
{	4	,	9	,	7	},
{	4	,	11	,	8	},
{	5	,	7	,	6	},
{	5	,	12	,	9	},
{	6	,	8	,	7	},
{	6	,	13	,	10	},
{	7	,	5	,	6	},
{	7	,	12	,	10	},
{	8	,	6	,	7	},
{	8	,	13	,	11	},
{	9	,	0	,	5	},
{	9	,	2	,	6	},
{	9	,	4	,	7	},
{	9	,	11	,	10	},
{	9	,	14	,	12	},
{	10	,	1	,	6	},
{	10	,	3	,	7	},
{	11	,	2	,	7	},
{	11	,	4	,	8	},
{	11	,	9	,	10	},
{	11	,	14	,	13	},
{	12	,	5	,	9	},
{	12	,	7	,	10	},
{	13	,	6	,	10	},
{	13	,	8	,	11	},
{	14	,	9	,	12	},
{	14	,	11	,	13	},

};

int main() {
	string oCoord, dCoord;
	bool game = true;

	//Filling board with pegs
	for (int i = 0; i < MAXPEGS; i++)
		pegs[i] = 'x';

	//Display initial board
	displayBoard();

	//Remove peg and update board

	oCoord = validCoord("Enter the coordinate of the peg you want to remove (ex. a1): ");
	if (oCoord == "exit") {
		game = false;
	}
	else {
		removePeg(oCoord);
		displayBoard();
	}

	//Game Loop
	while (game) {

		oCoord = validCoord("Enter the coordinate of the peg you want to move (ex.a1): ");
		if (oCoord == "exit") 
			break;

		dCoord = validCoord("Enter the coordinate of destination: ");
		if (dCoord == "exit")
			break;
		

		if (validJump2(coord2Index(oCoord), coord2Index(dCoord)))
			displayBoard();
		else
			cout << "You made an invalid jump.\n";


	}




	return 0;
}

//Function to display current state of board
void displayBoard() {
	system("CLS");
	cout << "\n###########################################################################" << endl;
	cout << "#                                   / \\                                   #" << endl;
	cout << "#                                  /   \\                                  #" << endl;
	//cout << "#                           5  -  |  x  |                                 #" << endl;
	displayLine5();
	cout << "#                                / \\   / \\                                #" << endl;
	cout << "#                               /   \\ /   \\                               #" << endl;
	//cout << "#                       4  -   |  x  |  x  |                              #" << endl;
	displayLine4();
	cout << "#                             / \\   / \\   / \\                             #" << endl;
	cout << "#                            /   \\ /   \\ /   \\                            #" << endl;
	//cout << "#                     3  -  |  x  |  x  |  x  |                           #" << endl;
	displayLine3();
	cout << "#                          / \\   / \\   / \\   / \\                          #" << endl;
	cout << "#                         /   \\ /   \\ /   \\ /   \\                         #" << endl;
	//cout << "#                  2  -  |  x  |  x  |  x  |  x  |                        #" << endl;
	displayLine2();
	cout << "#                       / \\   / \\   / \\   / \\   / \\                       #" << endl;
	cout << "#                      /   \\ /   \\ /   \\ /   \\ /   \\                      #" << endl;
	//cout << "#               1  -  |  x  |  x  |  x  |  x  |  x  |                     #" << endl;
	displayLine1();
	cout << "#                      \\   / \\   / \\   / \\   / \\   /                      #" << endl;
	cout << "#                       \\ /   \\ /   \\ /   \\ /   \\ /                       #" << endl;
	cout << "#                    /     /     /     /     /                            #" << endl;
	cout << "#                   A     B     C     D     E                             #" << endl;
	cout << "###########################################################################\n" << endl;
}

//Function to display current state of line5
void displayLine5() {
	cout << "#                           5  -  |  " << pegs[4] << "  |                                 #" << endl;

}

//Function to display current state of line4
void displayLine4() {
	cout << "#                       4  -   |  " << pegs[3] << "  |  " << pegs[8] << "  |                              #" << endl;
}

//Function to display current state of line3
void displayLine3() {
	cout << "#                     3  -  |  " << pegs[2] << "  |  " << pegs[7] << "  |  " << pegs[11] << "  |                           #" << endl;
}

//Function to display current state of line2
void displayLine2() {
	cout << "#                  2  -  |  " << pegs[1] << "  |  " << pegs[6] << "  |  " << pegs[10] << "  |  " << pegs[13] << "  |                        #" << endl;
}

//Function to display current state of line1
void displayLine1() {
	cout << "#               1  -  |  " << pegs[0] << "  |  " << pegs[5] << "  |  " << pegs[9] << "  |  " << pegs[12] << "  |  " << pegs[14] << "  |                     #" << endl;
}

//removePeg
void removePeg(string coord) {
	int index = coord2Index(coord);
	pegs[index] = ' ';
}

//Asking user to input coordinate and validating the coordinate
string validCoord(string prompt) {
	string coordinate;
	while (true) {
		cout << prompt;
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
		if (coordinate == "exit")
			break;
		else
			cout << "Invalid coordinate.\n";
	}
	return coordinate;
}

//convert validated coordinate to index
int coord2Index(string coord) {
	int index = 999;

	//Assumed valid coordinate
	if (coord[0] == 'a')
		index = (coord[1] - '0') - 1; //coord[x] - '0' is used to convert char 'number' to int. See ascii table.

	if (coord[0] == 'b')
		index = (coord[1] - '0') + 4;

	if (coord[0] == 'c')
		index = (coord[1] - '0') + 8;

	if (coord[0] == 'd')
		index = (coord[1] - '0') + 11;

	if (coord[0] == 'e')
		index = (coord[1] - '0') + 13;

	return index;
}

//Validate a jump and modify board
bool validJump(int oIndex, int dIndex) {
	int adjacent;
	bool isValidMove = true;
	bool isValidJump = true;

	if (oIndex == 0) {
		switch (dIndex) {
		case 2:
			adjacent = 1;
			break;
		case 9:
			adjacent = 5;
			break;
		default: 
			isValidMove = false;
		}
	}

	if (oIndex == 1) {
		switch (dIndex) {
		case 3:
			adjacent = 2;
			break;
		case 10:
			adjacent = 6;
			break;
		default:
			isValidMove = false;

		}
	}

	if (isValidMove) {
		if ((pegs[oIndex] == 'x') && (pegs[dIndex] == ' ') && (pegs[adjacent] == 'x')) {
			pegs[oIndex] = ' ';
			pegs[dIndex] = 'x';
			pegs[adjacent] = ' ';

		}
		else isValidJump = false;
	}
	else isValidJump = false;

	return isValidJump;
}

bool validJump2(int oIndex, int dIndex) {
	int adjacent = 999;
	for (int i = 0; i < MAXRULE; i++) {
		if ((rule[i][0] == oIndex) && (rule[i][1] == dIndex)) {
			adjacent = rule[i][2];
			if ((pegs[oIndex] == 'x') && (pegs[dIndex] == ' ') && (pegs[adjacent] == 'x')) {
				pegs[oIndex] = ' ';
				pegs[dIndex] = 'x';
				pegs[adjacent] = ' ';
				return true;
			}
			else
				break;
		}

	}

	return false;
}