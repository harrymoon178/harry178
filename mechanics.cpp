#include <iostream>
#include "mechanics.h"

// Function: add scores and money to the user if he/she guesses correctly
// Input: the address of the user and a pointer to inventory 
// Output: scores and money added if the user guesses correctly
void correct(User &usr, int *p_inv) {
  int inc_money = usr.level * 50;
  int inc_score = usr.level * 100;

  if (p_inv[0]) {
    cout << "Money--> " << usr.money << " + " << inc_money << "\033[0;36m x 2\033[0m" << endl;
    inc_money *= 2;
  }
  if (!p_inv[0])
    cout << "Money--> " << usr.money << " + " << inc_money << endl;

  if (p_inv[1]) {
    cout << "Score--> " << usr.score << " + " << inc_score << "\033[0;36m x 2\033[0m" << endl;
    inc_score *= 2;
  }
  if (!p_inv[1])
    cout << "Score--> " << usr.score << " + " << inc_score << endl;

  usr.money += inc_money;
  usr.score += inc_score;
  usr.print_info();
}
// Function: 
// - the user will level up if he/she passes seven times consecutively 
// - the user can choose to continue or not
// Input: the address of the user and a pointer to inventory 
// Output: 
// - level up if the user passes seven times consecutively 
// - if the user chooses to continue: play is true and the game continues
// - if the user does not choose to continue: play is false and the game ends
bool levelUp(User &usr, int *p_inv) {
  cout << "\033[0;33mYou Win!\033[0m" << endl;

  cout << "Level--> " << usr.level << " + 1" << endl;
  usr.level++;
  usr.print_info();

  char choice;
  bool play;
  while (1) {
    cout << "Continue to play? [y/n]" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 'y') {
      play = true;
      break;
    }
    else if (choice == 'n')
      play = false;
      break;
  }
  return play;
}
// Function: the game ends when the user guesses wrong unless he/she chooses to resurrect
// Input: the address of the user and result
// Output: 
// - if the user guesses wrong and choose to ressurect: resurrect is true and the game continues
// - if the user guesses wrong and do not choose to ressurect: resurrect is false and the game ends	
bool gameOver(User &usr, int result) {
  int amount = usr.level * 100 * result;
  bool resurrect;

  cout << "\033[0;31mGAME OVER.\033[0m" << endl;
  usr.print_info();
  while (1) {
    char option;
    cout << "Pay $ " << amount << " to resurrect? [y/n]" << endl; //player has to pay to resurrect
    cout << ">> ";
    cin >> option;

    if (option == 'y')
      if (usr.money < amount)
        cout << "\033[0;31m--Error: You don't have enough money.\033[0m" << endl; //player can't resurrect if he/she does not have enough money
      else {
        cout << "Money--> " << usr.money << " - " << amount << endl;
        usr.money -= amount;
        resurrect = true;
	usr.print_info();
        break;
      }
    else if (option == 'n') {
      usr.reset();
      cout << "Level--> 1" << endl;
      cout << "Score--> 0" << endl;
      resurrect = false;
      usr.print_info();
      break;
    }
  }

  return resurrect;
}

// Function: to guess the size of the next card
// Input: the size of the next card
// Output: 
// - if the size of the next card is same as the current card: result = 2 and the user has to pay double to resurrect 
// - if the size of the next card is guessed correctly: result is true and the game continues
// - if the size of the next card is not guessed correctly: result is false and the game ends
// - if the input is not correct: result = -1 and the user has to type again
int GuessSize(Card currentcard, Card nextcard) { 
  char choice;
  cout << "Press 'L' if you think the next card will be larger" << endl;
  cout << "Press 'S' if you think the next card will be smaller" << endl;
  cout << ">> ";
  cin >> choice;

  int result = 1;
  if (nextcard.rank_idx == currentcard.rank_idx)
      result = 2;
  else if (choice == 'S' && (nextcard.rank_idx < currentcard.rank_idx))
      result = 0;
  else if (choice == 'L' && (nextcard.rank_idx > currentcard.rank_idx))
      result = 0;
  else if (choice != 'S' && choice != 'L')
      result = -1;

  return result;
}

// Function: to guess the colour of the next card
// Input: the colour of the next card
// Output: 
// - if the colour of the next card is guessed correctly: result is true and the game continues
// - if the colour of the next card is not guessed correctly: result is false and the game ends
// - if the input is not correct: result = -1 and the user has to type again
int GuessColour(Card nextcard) { // guess the colour of the card
  char choice;
  cout << "Press 'R' if you think the next card will be red" << endl;
  cout << "Press 'B' if you think the next card will be black" << endl;
  cout << ">> ";
  cin >> choice;

  int result = 1;
  if (choice == 'R' && (nextcard.suit == HEART || nextcard.suit == DIAMOND))
      result = 0;
  else if (choice == 'B' && (nextcard.suit == SPADE || nextcard.suit == CLUB))
      result = 0;
  else if (choice != 'R' && choice != 'B')
      result = -1;

	return result;
}

// Function: to show the users what can buy items in store 
// Input: No input
// Output: the type, price and quantity of the items
void printStore(string items[], int prices[], int inv[]) { 
  for (int i = 0; i < 3; i++)
    if (i == 0 || i == 1)
      if (inv[i] != 1)
        cout << "   " << i+1 << ". " << items[i] << " $ " << prices[i] << endl;
      else
        cout << "   " << i+1 << ". " << items[i] << " is sold out." << endl;
    else
      cout << "   " << i+1 << ". " << items[i] << " $ " << prices[i] << endl;
}

// Function: to allow users to buy items in store 
// Input: what to buy
// Output: what has the user bought / the item has been sold out / the user does not have enough money
int * store(User &usr) {
  string items[] = {"\033[0;36mx2 money\033[0m", "\033[0;36mx2 score\033[0m", "\033[0;36mcard revealer\033[0m"};
  int prices[] = {usr.level*100, usr.level*100, usr.level*100};
  int *inventory = new int[3];

  for (int i = 0; i < 3; i++)
    inventory[i] = 0;

  cout << "Welcome to the store!" << endl;
  cout << "You may choose to purchase items for the next level: " << endl;

  while (1) {
    usr.print_info();
    printStore(items, prices, inventory);
    cout << "Input item no. or input '0' to leave the store: " << endl;
    cout << ">> ";

    int option;
    cin >> option;

    if (option == 1 || option == 2)
      if (inventory[option-1] == 1)
        cout << "\033[0;31m--Error: Item is sold\033[0m" << endl;
      else {
        if (usr.money < prices[option-1])
          cout << "\033[0;31m--Error: You don't have enough money.\033[0m" << endl;
        else {
          inventory[option-1]++;
          cout << "You bought a " << items[option-1] << " for $ " << prices[option-1] << endl;
          cout << "Money--> " << usr.money << " - " << prices[option-1] << endl;
          usr.money -= prices[option-1];
        }
      }
    else if (option == 3) {
      if (usr.money < prices[option-1])
        cout << "\033[0;31m--Error: You don't have enough money.\033[0m" << endl;
      else {
        inventory[option-1]++;
        cout << "You bought a " << items[option-1] << " for $ " << prices[option-1] << endl;
        cout << "Money--> " << usr.money << " - " << prices[option-1] << endl;
        usr.money -= prices[option-1];
      }
    }
    else if (option == 0)
      break;
  }

  return inventory;
}

// Function: item to facilitate the user - to reveal the next card
// Input: use the card revealer or not
// Output: 
// - if used: return is true
// - if not used: return is false
bool cardRevealer(int *p_inv) {
  if (p_inv[2] > 0) {
    while (1) {
      cout << "You have " << p_inv[2] << "\033[0;36m Card Revealer(s)\033[0m" << endl;
      cout << "Use Card Revealer? [y/n]" << endl;
      cout << ">> ";
      char choice;
      cin >> choice;
      if (choice == 'y') {
        p_inv[2]--;
        return true;
      }
      else if (choice == 'n')
        return false;
    }
  }
  return false;
}
