#include <iostream>
#include <windows.h>
#include <stdlib.h>



using namespace std;


const int MAXPEGS = 15; //Maximum number of pegs
const int MAXRULE = 38; //Maximum number of 
char pegs[MAXPEGS]; 
int countJump = 0; // Number of possible jumps 
int countMove = 0; //How many moves the player has made

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

//Display game board
void displayBoard();
void displayLine5();
void displayLine4();
void displayLine3();
void displayLine2();
void displayLine1();
void displayCounter();
void displayStart();

//Input and validate coordinate
string validCoord(string prompt);

//convert coordinate to index
int coord2Index(string coord);

//Remove a peg
void removePeg(string coord);

//Validate a jump
bool validJump(int oIndex, int dIndex);

//Counter for possible jumps
int countPosJump();

//Counter for number of pegs on the board
int countPeg();

//Initialize new baord
bool initBoard();

//Start a new game
bool playAgain(string prompt);


int main() {
	string oCoord, dCoord;
	bool game = true;

	//Start screen
	displayStart();
	cout << "\n\nPress enter to continue.";
	cin.ignore();
	
	//Initialize game
	game = initBoard();

	//Game Loop
	while (game) {
		countJump = countPosJump();

		if (countJump == 0) {

			cout << "No possible moves";
			cout << "\nYou finished board with " << countPeg() << " peg(s) left and in " << countMove << " moves." << endl;
			cout << '\a';
			
			if (playAgain("\nDo you want to play another game? (y/n): ")) {
				if (initBoard())
					continue;
				
			}
			break;
		}
		cout << "There are " << countJump << " possible moves.\n";

		oCoord = validCoord("Enter the coordinate of the peg you want to move (ex.a1): ");
		if (oCoord == "exit") 
			break;

		dCoord = validCoord("Enter the coordinate of destination: ");
		if (dCoord == "exit")
			break;
		

		if (validJump(coord2Index(oCoord), coord2Index(dCoord))) {
			countMove++;
			displayBoard();
		}
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
	//cout << "#                                  /   \\                                  #" << endl;
	displayCounter();
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

//Display current state of line5
void displayLine5() {
	cout << "#                           5  -  |  " << pegs[4] << "  |                                 #" << endl;

}

//Display current state of line4
void displayLine4() {
	cout << "#                       4  -   |  " << pegs[3] << "  |  " << pegs[8] << "  |                              #" << endl;
}

//Display current state of line3
void displayLine3() {
	cout << "#                     3  -  |  " << pegs[2] << "  |  " << pegs[7] << "  |  " << pegs[11] << "  |                           #" << endl;
}

//Display current state of line2
void displayLine2() {
	cout << "#                  2  -  |  " << pegs[1] << "  |  " << pegs[6] << "  |  " << pegs[10] << "  |  " << pegs[13] << "  |                        #" << endl;
}

//Display current state of line1
void displayLine1() {
	cout << "#               1  -  |  " << pegs[0] << "  |  " << pegs[5] << "  |  " << pegs[9] << "  |  " << pegs[12] << "  |  " << pegs[14] << "  |                     #" << endl;
}

//Display number of moves
void displayCounter() {
	if (countMove < 10)
		cout << "#                                  /   \\          " << "Moves: " << countMove << "                #" << endl;
	else 
		cout << "#                                  /   \\          " << "Moves: " << countMove << "               #" << endl;
}

//Display start menu
void displayStart() {
	cout << "          	                      _______  _______  _______                                                " << endl;
	Sleep(100);
	cout << "                                     (  ____ )(  ____ \\(  ____ \\                                        " << endl;
	Sleep(100);
	cout << "                                     | (    )|| (    \\/| (    \\/                                        " << endl;
	Sleep(100);
	cout << "                                     | (____)|| (__    | |                                                " << endl;
	Sleep(100);
	cout << "                                     |  _____)|  __)   | | ____                                           " << endl;
	Sleep(100);
	cout << "                                     | (      | (      | | \\_  )                                         " << endl;
	Sleep(100);
	cout << "                                     | )      | (____/\\| (___) |                                         " << endl;
	Sleep(100);
	cout << "                                     |/       (_______/(_______)                                          " << endl;
	Sleep(100);
	cout << "                                                                                                          " << endl;
	Sleep(100);
	cout << "                _______  _______  _       __________________ _______ _________ _______  _______           " << endl;
	Sleep(100);
	cout << "               (  ____ \\(  ___  )( \\      \\__   __/\\__   __/(  ___  )\\__   __/(  ____ )(  ____ \\    " << endl;
	Sleep(100);
	cout << "               | (    \\/| (   ) || (         ) (      ) (   | (   ) |   ) (   | (    )|| (    \\/        " << endl;
	Sleep(100);
	cout << "               | (_____ | |   | || |         | |      | |   | (___) |   | |   | (____)|| (__              " << endl;
	Sleep(100);
	cout << "               (_____  )| |   | || |         | |      | |   |  ___  |   | |   |     __)|  __)             " << endl;
	Sleep(100);
	cout << "                     ) || |   | || |         | |      | |   | (   ) |   | |   | (\\\ (   | (              " << endl;
	Sleep(100);
	cout << "               /\\____) || (___) || (____/\\___) (___   | |   | )   ( |___) (___| ) \\ \\__| (____/\\     " << endl;
	Sleep(100);
	cout << "               \\_______)(_______)(_______/\\_______/   )_(   |/     \\|\\_______/|/   \\__/(_______/     " << endl;
	Sleep(100);
	cout << '\a'; //Windows sound
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

//Counter for possible moves
int countPosJump() {
	int counter = 0;

	for (int i = 0; i < MAXRULE; i++) {
		if ((pegs[rule[i][0]] == 'x') && (pegs[rule[i][1]] == ' ') && (pegs[rule[i][2]] == 'x'))
			counter++;
	}
	return counter;
}

//Counting number of pegs on board
int countPeg() {
	int counter = 0;
	for (int i = 0; i < MAXPEGS; i++) {
		if (pegs[i] == 'x')
			counter++;
	}
	return counter;
}

//Initialize new game board and asking user to remove peg
bool initBoard() {
	//Filling board with pegs
	for (int i = 0; i < MAXPEGS; i++)
		pegs[i] = 'x';

	countMove = 0;

	//Display initial board
	displayBoard();

	//Display condition to exit program
	cout << "At any time, type 'exit' to quit the game.\n";

	//Remove peg and update board
	string coord = validCoord("Enter the coordinate of the peg you want to remove (ex. a1): ");
	if (coord == "exit") {
		return false;
	}
	else {
		removePeg(coord);
		displayBoard();
		return true;
	}
}


//Asking if user wants to start a new game
bool playAgain(string prompt) {
	string yesNo;

	while (true) {
		cout << prompt;
		cin >> yesNo;

		if (yesNo == "y")
			return true;
		if (yesNo == "n")
			return false;
	}

}
