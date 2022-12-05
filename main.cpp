#include <iostream>
#include "menu.h"
#include "user.h"
#include "card.h"
#include "mechanics.h"
#include "game.h"
// Function: to print the home page of the game
// Input: No input
// Output: the outline of the home page
int main() { 
  while (1) {
    cout << "   \033[0;33m-------------------------------------\033[0m" << endl;
    cout << "   \033[1;33m **********Large Small Red Black**********\033[0m" << endl;
    cout << "   [1 - New Game]" << endl;
    cout << "   [2 - Continue]" << endl;
    cout << "   [3 - Leaderboard]" << endl;
    cout << "   [4 - Load Game]" << endl;
    cout << "   [5 - Save Game]" << endl;
    cout << "   [6 - Quit]" << endl;
    cout << "   \033[0;33m-------------------------------------\033[0m" << endl;
    cout << ">> ";

    int option;
    cin >> option;

    if (option == 1)
      newUser();
    else if (option == 2)
      selectUser();
    else if (option == 3)
      printLeaderboard();
    else if (option == 4)
      loadGame();
    else if (option == 5)
      saveGame();
    else if (option == 6)
      break;
  }
}
