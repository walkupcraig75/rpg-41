a.out: fighter.o combat_test.o dragon.o goblin.o heroes.o warlock.o sorcerer.o
	g++ fighter.o combat_test.o dragon.o goblin.o heroes.o warlock.o sorcerer.o

combat_test.o: fighter.h heroes.h combat_test.cc
	g++ -c combat_test.cc

dragon.o: fighter.h dragon.h dragon.cc
	g++ -c dragon.cc

goblin.o: fighter.h goblin.h goblin.cc
	g++ -c goblin.cc

fighter.o: fighter.cc fighter.h
	g++ -c fighter.cc

warlock.o: heroes.h warlock.h warlock.cc
	g++ -c warlock.cc

sorcerer.o: heroes.h sorcerer.h sorcerer.cc
	g++ -c sorcerer.cc

heroes.o: heroes.cc heroes.h
	g++ -c heroes.cc

