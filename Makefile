a.out: main.cc map.h load_rooms.h
	\g++ main.cc -lcurl -lncurses -O3 

clean:
	rm a.out core *.o
