FLAGS = -pedantic-errors -std=c++11

beat_the_dealer: main.o menu.o user.o card.o mechanics.o game.o
	g++ $(FLAGS) $^ -o $@

main.o: main.cpp menu.h user.h card.h mechanics.h game.h
	g++ $(FLAGS) -c $<

menu.o: menu.cpp menu.h user.h card.h mechanics.h game.h
	g++ $(FLAGS) -c $<

user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

card.o: card.cpp card.h
	g++ $(FLAGS) -c $<

mechanics.o: mechanics.cpp mechanics.h user.h card.h
	g++ $(FLAGS) -c $<

game.o: game.cpp game.h user.h card.h mechanics.h
	g++ $(FLAGS) -c $<

clean:
	rm *.o beat_the_dealer

.PHONY: clean
