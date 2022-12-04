#ifndef MECHANICS_H
#define MECHANICS_H

#include "user.h"
#include "card.h"

using namespace std;

void correct(User &usr, int *p_inv);

bool levelUp(User &usr, int *p_inv);

bool gameOver(User &usr, int result);

int GuessSize(Card currentcard, Card nextcard);

int GuessColour(Card nextcard);

void printStore(string items[], int prices[], int inv[]);

int * store(User &usr);

bool cardRevealer(int *p_inv);

#endif
