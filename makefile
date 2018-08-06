# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
LFLAGS  = -L/usr/lib

# All Targets
all: reviiot

# Tool invocations
# Executable "reviot" depends on the files Card.o and run.o.
reviiot: bin/Hand.o bin/Deck.o bin/Card.o bin/NumericCard.o bin/FigureCard.o bin/Player.o bin/Game.o bin/reviiyot.o 
	@echo 'Building target: reviiot'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/reviiot bin/Hand.o bin/Deck.o bin/NumericCard.o bin/FigureCard.o bin/Card.o bin/Player.o bin/Game.o bin/reviiyot.o $(LFLAGS)
	@echo 'Finished building target: reviiot'
	@echo ' '

# Depends on the source and header files
bin/Card.o: src/Card.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Card.o src/Card.cpp 
# Depends on the source and header files 
bin/NumericCard.o: src/NumericCard.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/NumericCard.o src/NumericCard.cpp
# Depends on the source and header files 
bin/FigureCard.o: src/FigureCard.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/FigureCard.o src/FigureCard.cpp

	
# Depends on the source and header files 
bin/Deck.o: src/Deck.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Deck.o src/Deck.cpp
# Depends on the source and header files 
bin/Hand.o: src/Hand.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Hand.o src/Hand.cpp

# Depends on the source and header files 
bin/Player.o: src/Player.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Player.o src/Player.cpp
# Depends on the source and header files 

bin/Game.o: src/Game.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/Game.o src/Game.cpp

# Depends on the source and header files 
bin/reviiyot.o: src/reviiyot.cpp
	$(CC) $(CFLAGS) -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp
#Clean the build directory
clean: 
	rm -f bin/*
