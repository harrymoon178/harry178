Beat the Dealer
=====================
Text-based game for COMP2113 project

Team member:
-----------------------

Vu Duc Manh 3035806790

Game description:
----------------------
  - List Beat the Dealer is a classic drinking game by sheer luck implement in c++ 
  - Include some new game features such as items, level, money and score systems

Game rules:
---------------------
  - 52 poker cards 
  - the player guesses the card's:
  - for card 3 - K, the player has to guess whether the next card is larger or smaller than the previous one for card A and 2, the player has to guess
  whether the next card is red or black. 
  - If guessed right --> proceed to the next card --> ++money and ++score until the player guessed wrong OR the player guessed correct for 7 consecutive times. 
  - If the player guessed wrong --> then gameover (reset score) OR pay money to resurrect
  - If the player guessed correct for 7 consecutive times --> proceed to next level
  - If the size of the current card and the next card is the same, the player loses, and the amount needed to pay for resurrected is doubled
  the player can earn money to purchase items/resurrect


List of features: (with code requirements 1-5)
------------------------------------------------------
1. Generation of random game sets or events:
    - random poker cards generated by rand() seeded by srand(time(NULL))
2. Data structures for storing game status:
  - user defined type (struct) for User and Card
3. Dynamic memory management:
  - vectors to store users and cards
  - pointer to player's inventory

4. File input/output (e.g., for loading/saving game status):
  - load game / save game
5. Program codes in multiple files:
  - Makefile, header files, function files, the main file

- Account system:
  - (2,3,4): used struct to make a User type, store all the users in a vector, user information can be loaded/saved through file i/o
  - unique id name
  - supports multiple single players
  - leaderboard: rank by descending scores, lexicographically

- Money system:
  - before each level, the player can buy items in the store
     - card revealer: the next card can be revealed by the host
     - x2 money: money won in that round can be doubled
     - x2 score: score won in that round can be doubled
  - each winning rounds ++money
  - each resurrections --money

- Score system:
  - each winning rounds ++score
  - each gameovers -> reset to 0
  
- level system
  - Higher level gains more score and money
    - i.e. level 1 ++score ++money, level 2 x2 score x2 money, level 3 x3 score ...
  - each gameovers -> reset to 1

Compilation and execution instructions:
----------------------------------------------------
 - Steps:
   1. move the current directory to where the program files are located 
   2. make
   3. /beat_the_dealer
 - After entering the main menu, type 1 to create new player
 - type 2 to select a player to start the game
 - type 3 to show the leaderboard
 - type 4 to load game status from a file in the same directory as the program files
 - type 5 to save game status to a file in the same directory as the program files
 - type 6 to halt the program

