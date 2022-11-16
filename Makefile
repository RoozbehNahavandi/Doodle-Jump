CC := g++
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

all: doodleJump.out

doodleJump.out: main.o rsdl.o game.o Entity.o Screen.o Platform.o Doodle.o Enemy_Spring.o
	$(CC) main.o game.o rsdl.o Entity.o Screen.o Platform.o Doodle.o Enemy_Spring.o $(CCFLAGS) -o doodleJump.out

main.o: src/rsdl.hpp main.cpp game.hpp Doodle.hpp define.hpp
	$(CC) -c main.cpp -o main.o

game.o: game.hpp game.cpp Platform.hpp Screen.hpp Doodle.hpp define.hpp Enemy_Spring.hpp
	$(CC) -c game.cpp $(CCFLAGS) -o game.o

Platform.o: Entity.hpp Platform.hpp Platform.cpp define.hpp
	$(CC) -c Platform.cpp $(CCFLAGS) -o Platform.o

Doodle.o: define.hpp Doodle.hpp Doodle.cpp Entity.hpp Enemy_Spring.hpp Platform.hpp
	$(CC) -c Doodle.cpp $(CCFLAGS) -o Doodle.o

Screen.o: Screen.cpp Screen.hpp Doodle.hpp Entity.hpp define.hpp Entity.hpp Enemy_Spring.hpp Platform.hpp
	$(CC) -c Screen.cpp $(CCFLAGS) -o Screen.o

Entity.o: Entity.hpp Entity.cpp src/rsdl.hpp define.hpp 
	$(CC) -c Entity.cpp $(CCFLAGS) -o Entity.o

Enemy_Spring.o: Enemy_Spring.hpp Enemy_Spring.cpp Entity.hpp
	$(CC) -c Enemy_Spring.cpp $(CCFLAGS) -o Enemy_Spring.o

rsdl.o: src/rsdl.cpp src/rsdl.hpp
	$(CC) -c src/rsdl.cpp -o rsdl.o

.Phony: clean
clean:
	rm *.o
	rm doodleJump.out