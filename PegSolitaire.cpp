#include <iostream> 

using namespace std;
const int MAXPEGS = 15;
void displayBoard(char pegs[]);
void displayLine5(char pegs[]);
void displayLine4(char pegs[]);
void displayLine3(char pegs[]);
void displayLine2(char pegs[]);
void displayLine1(char pegs[]);



char pegs[MAXPEGS];



int main()
{
	for (int i = 0; i < MAXPEGS; i++)
		pegs[i] = 'x';





	displayBoard(pegs);
	return 0;
}

//Function to display current state of board
void displayBoard(char pegs[]) {

	cout << "###########################################################################" << endl;
	cout << "#                                   / \\                                   #" << endl;
	cout << "#                                  /   \\                                  #" << endl;
	//cout << "#                           5  -  |  x  |                                 #" << endl;
	displayLine5(pegs);
	cout << "#                                / \\   / \\                                #" << endl;
	cout << "#                               /   \\ /   \\                               #" << endl;
	//cout << "#                       4  -   |  x  |  x  |                              #" << endl;
	displayLine4(pegs);
	cout << "#                             / \\   / \\   / \\                             #" << endl;
	cout << "#                            /   \\ /   \\ /   \\                            #" << endl;
	//cout << "#                     3  -  |  x  |  x  |  x  |                           #" << endl;
	displayLine3(pegs);
	cout << "#                          / \\   / \\   / \\   / \\                          #" << endl;
	cout << "#                         /   \\ /   \\ /   \\ /   \\                         #" << endl;
	//cout << "#                  2  -  |  x  |  x  |  x  |  x  |                        #" << endl;
	displayLine2(pegs);
	cout << "#                       / \\   / \\   / \\   / \\   / \\                       #" << endl;
	cout << "#                      /   \\ /   \\ /   \\ /   \\ /   \\                      #" << endl;
	//cout << "#               1  -  |  x  |  x  |  x  |  x  |  x  |                     #" << endl;
	displayLine1(pegs);
	cout << "#                      \\   / \\   / \\   / \\   / \\   /                      #" << endl;
	cout << "#                       \\ /   \\ /   \\ /   \\ /   \\ /                       #" << endl;
	cout << "#                    /     /     /     /     /                            #" << endl;
	cout << "#                   A     B     C     D     E                             #" << endl;
	cout << "###########################################################################" << endl;
}

//Function to display current state of line5
void displayLine5(char pegs[]) {
	cout << "#                           5  -  |  " << pegs[0] << "  |                                 #" << endl;

}

//Function to display current state of line4
void displayLine4(char pegs[]) {
	cout << "#                       4  -   |  " << pegs[1] << "  |  " << pegs[2] << "  |                              #" << endl;
}

//Function to display current state of line3
void displayLine3(char pegs[]) {
	cout << "#                     3  -  |  " << pegs[3] << "  |  " << pegs[4] << "  |  " << pegs[5] << "  |                           #" << endl;
}

//Function to display current state of line2
void displayLine2(char pegs[]) {
	cout << "#                  2  -  |  " << pegs[6] << "  |  " << pegs[7] << "  |  " << pegs[8] << "  |  " << pegs[9] << "  |                        #" << endl;
}

//Function to display current state of line1
void displayLine1(char pegs[]) {
	cout << "#               1  -  |  " << pegs[10] << "  |  " << pegs[11] << "  |  " << pegs[12] << "  |  " << pegs[13] << "  |  " << pegs[14] << "  |                     #" << endl;
}








string inputCo()