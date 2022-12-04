FLAGS = -pedantic-errors -std=c++11


user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

card.o: card.cpp card.h
	g++ $(FLAGS) -c $<

mechanics.o: mechanics.cpp mechanics.h user.h card.h
	g++ $(FLAGS) -c $<
