#include "utility.h"
#include "life.h"

int main() {
	/*
		PreConditions:	The user supplies an initial configuration of living cells
		PostConditions:	The program prints a sequence of pictures based on the rules of the game-of-life rules and also the user
						decision of either saying yes or no
	*/

	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();

	
	while (user_says_yes()) {
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations ?" << endl;
	}
}