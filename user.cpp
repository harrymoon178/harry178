#include <iostream>
#include "user.h"

// Function: to construct an account
// Input: name, score, level and money
// Output: No output
User::User(string name, int score, int level, int money) { 
  this->name = name;
  this->score = score;
  this->level = level;
  this->money = money;
}

// Function: to reset the score and level of the user
// Input: No input
// Output: score is reset to 0 and level is backed to 1
void User::reset() { 
  score = 0;
  level = 1;
}

// Function: to print the information of the user
// Input: No input
// Output: the information (name, score, level and money) of the user
void User::print_info() {
  cout << name << ": " << score << ", lv." << level << ", $" << money << endl;
}

// Function: to facilitate sorting
// Input: 2 users
// Output: the sequence of the users
bool operator<(const User & a, const User & b) {
  if (a.score == b.score)
    return (a.name < b.name);
  return (a.score > b.score);
}
