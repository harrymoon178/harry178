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

// Function: to load the game from the file
// Input: file name
// Output: the file if the file exists
void loadGame() { 
  string load_file;
  cout << "\033[1;32mLoad from (file name): \033[0m";
  cin >> load_file;

  ifstream fin(load_file.c_str());

  if (fin.fail())
    cout << "\033[1;31m--File access error \033[0m" << endl;
  else {
    users.clear();
    string name;
    while (fin >> name) {
      int score, level, money;
      fin >> score >> level >> money;
      User u(name, score, level, money);
      users.push_back(u);
    }
    fin.close();
  }
}

// Function: to save the game to the file
// Input: file name
// Output: No output
void saveGame() { 
  string save_file;
  cout << "\033[1;32mSave as (file name): \033[0m";
  cin >> save_file;

  ofstream fout(save_file.c_str());

  if (fout.fail())
    cout << "\033[1;31m--File access error \033[0m" << endl;
  else {
    for (int i = 0; i < users.size(); i++)
      fout << users[i].name << ' ' << users[i].score << ' ' << users[i].level << ' ' << users[i].money << endl;
    fout.close();
  }
}
