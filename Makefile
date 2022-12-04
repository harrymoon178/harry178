FLAGS = -pedantic-errors -std=c++11


user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

card.o: poker_card.cpp poker_card.h
	g++ $(FLAGS) -c $<

mechanics.o: mechanics.cpp mechanics.h user.h card.h
	g++ $(FLAGS) -c $<
