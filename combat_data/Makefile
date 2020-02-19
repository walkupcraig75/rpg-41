a.out: fighter.o heroes.o monsters.o combat_test.o list.o
	g++ fighter.o combat_test.o heroes.o monsters.o list.o

combat_test.o: fighter.h heroes.h combat_test.cc
	g++ -c combat_test.cc

monsters.o: monsters.cc monsters.h
	g++ -c monsters.cc

fighter.o: fighter.cc fighter.h
	g++ -c fighter.cc

list.o: list.cc list.h
	g++ -c list.cc

heroes.o: heroes.cc heroes.h
	g++ -c heroes.cc

clean:
	rm *.o a.out
