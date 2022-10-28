#include "life.h"
#include "utility.h"

void Life::initialize() {
	/*
	Pre:	None
	Post:	The life object will be initialized with the first configuration by the user
	*/

	int row, col;
	for (row = 0; row <= maxrow + 1; row++)
		for (col = 0; col <= maxcol + 1; col++)
			grid[row][col] = 0;
	
	cout << "Initialize the Life object with Coordinates" << endl;
	cout << "Terminate the Loop with special pair -1 -1" << endl;

	cin >> row >> col;
	while (row != -1 || col != -1) {
		if (row >= 1 && row <= maxrow)
			if (col >= 1 && col <= maxcol)
				grid[row][col] = 1;
			else
				cout << "Column " << col << " out of range" << endl;
		else
			cout << "Row" << row << " out of range" << endl;

		cin >> row >> col;
	}
};

void Life::print() {
	/*
	Pre: List must have had a configuration
	Post: The life configuration will be printed in the console
	*/

	int row, col;
	cout << "\nThe Current life Configuration is:" << endl;;
	for (row = 1; row <= maxrow; row++) {
		for (col = 1; col <= maxcol; col++) {
			if (grid[row][col])
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}
	cout << endl;
		

};


void Life::update() {
	/*
	Pre: The life object contains a configuration
	Post: The life object will contain the next generation of the configuration
	*/

	int new_grid[maxrow + 2][maxcol + 2];

	for (int row=1; row<=maxrow; row++)
		for (int col=1; col<=maxcol; col++)
			switch (neighbor_count(row, col)) {
			case 2:
				new_grid[row][col] = grid[row][col];
				break;
			case 3:
				new_grid[row][col] = 1;
				break;
			default:
				new_grid[row][col] = 0;
				break;
			}
	for (int row = 1; row <= maxrow; row++)
		for (int col = 1; col <= maxcol; col++)
			grid[row][col] = new_grid[row][col];
};

int Life::neighbor_count(int row, int col) {
	/*
	Pre: The life object must contain a configuration
	Post: the number of living neighbors around a living cell
	*/

	int count = 0;
	for (int i = row - 1; i <= row + 1; i++)
		for (int j = col - 1; j <= col + 1; j++)
			count += grid[i][j];
	count -= grid[row][col];

	return(count);
}


void instructions() {
	cout << "Welcome to Conway's game of life" << endl;
	cout << "This game uses a grid size of " << maxrow << " and " << maxcol << " in which" << endl;
	cout << "The occupied cells change from generation to generation according to the number of neighboring cells" << endl;
}