#ifndef USER_H
#define USER_H

using namespace std;

struct User {
  string name;
  int score;
  int level;
  int money;

  User(string name, int score = 0, int level = 1, int money = 0);

  void reset();
  void print_info();
};

bool operator<(const User & a, const User & b);

#endif
