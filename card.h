#ifndef CARD_H
#define CARD_H

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

struct Card {
  int idx;
  int rank_idx;
  int suit_idx;
  string rank;
  string suit;

  Card(int card_idx);

  void print_card();
};

#endif
