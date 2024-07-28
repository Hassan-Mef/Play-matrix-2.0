

#include <iostream>
#include "HangMan/HangMan.h"
#include "Snake Game/Snake_Game.h"
#include "Space_Shooter/Space_Shooter.h"
#include <raylib.h>


using namespace std;

void playMatrix()
{
	cout << " ************************************************************************************************************************" << endl;
	cout << " ************************************************************************************************************************" << endl;
	cout << " **   * *   *         * * * *   *         *      *        *   * * * *   * * * * *  *  *      * * * * *   *          *   **" << endl;
	cout << " **   *  *  *         *     *     *     *        *  *   * *   *     *       *      *    *        *         *       *    **" << endl;
	cout << " **   *  *  *         *     *       * *          *    *   *   *     *       *      *   *         *           *   *      **" << endl;
	cout << " **   * *   *         * * * *        *      ===  *        *   * * * *       *      *  *          *             *        **" << endl;
	cout << " **   *     *         *     *        *           *        *   *     *       *      * *           *           *   *      **" << endl;
	cout << " **   *     *         *     *        *           *        *   *     *       *      *   *         *         *       *    **" << endl;
	cout << " **   *     * * * *   *     *        *           *        *   *     *       *      *     *   * * * * *   *           *  **" << endl;
	cout << " ************************************************************************************************************************" << endl;
	cout << " ************************************************************************************************************************" << endl;

}

int main()
{
	//playMatrix();
	
	int op;

	do {
		cout << "\n====== GAME MENU ======\n";
		cout << "1. HangMan" << endl;
		cout << "2. Snake Game" << endl;
		cout << "3. Space Shooter" << endl;
		cout << "0. Exit" << endl;
		cin >> op;

		if (op == 1)
		{
			HangMan();
			system("CLS");
		}
		else if (op == 2)
		{
			if (Snake_Game() == 1) {  // check if the game window was 
				break;
			}
			system("CLS");
		}
		else if (op == 3)
		{

			Space_Shooter();
			system("CLS");
			system("EXIT");
		}
		else if (op == 0)
		{
			break;
		}
		else
		{

			cout << "Invalid Input" << endl;

		}
	} while (op != 0);

	return 0;
}


