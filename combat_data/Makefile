a.out: fighter.o combat_test.o slime.o
	g++ fighter.o combat_test.o slime.o

combat_test.o: fighter.h combat_test.cc
	g++ -c combat_test.cc

slime.o: fighter.h slime.h slime.cc
	g++ -c slime.cc

fighter.o: fighter.cc fighter.h
	g++ -c fighter.cc

