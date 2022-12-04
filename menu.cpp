#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "menu.h"
#include "mechanics.h"
#include "game.h"

vector<User> users;
// Function: to check whether the name is used
// Input: username
// Output: if the name is used: return 1 
bool sameName(string name) { 
  for (int i = 0; i < users.size(); i++)
    if (name == users[i].name)
      return 1;
  return 0;
}

// Function: to create a new user
// Input: username
// Output: No output
void newUser() { 
  string name;
  cout << "New Player: ";
  cin >> name;

  while (sameName(name)) {
    cout << "\033[1;31mName taken, try another: \033[0m ";
    cin >> name;
  }
  User u(name);
  users.push_back(u);
}

// Function: to continue the last game
// Input: choose a user
// Output: 
// - if no such user: 'no player record'
// - if invalid input: 'error' 
// - choose the user and start the game
void selectUser() { 
  if (users.size() == 0)
    cout << "\033[1;31m--Error: No player record \033[0m" << endl;
  else {
    cout << "Select a user: " << endl;
    for (int i = 0; i < users.size(); i++) {
      cout << "   " << i+1 << ". ";
      users[i].print_info();
    }

    int u;
    while (1) {
      cout << ">> ";
      cin >> u;
      if (u <= users.size())
        break;
      cout << "\033[1;31m--Error: Please input a valid number \033[0m" << endl;
    }
    single(users[u-1]);
  }
}

// Function: to print the outline of the leaderboard
// Input: No input
// Output: the outline of the leaderboard
void printLeaderboard() {
  if (users.size() == 0)
    cout << "\033[1;31m--Error: No player record \033[0m" << endl;
  else {
    cout << "\033[1;36m === Leaderboard: === \033[0m" << endl;
    vector<User> ranking = users;
    sort(ranking.begin(), ranking.end());

    for (int i = 0; i < users.size(); i++)
      cout << "     " << "No." << i+1 << " " << ranking[i].name << " " << ranking[i].score << endl;
    cout << "\033[1;36m ==================== \033[0m" << endl;
  }
}
