CXX = g++ -Wall

all: compile checkstyle

compile: TetrisMain

test: TetrominoTest StructureTest
	./TetrominoTest
	./StructureTest

checkstyle:
	python ./cpplint.py *.h *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
	rm -f core

%Main: %Main.o Tetris.o Tetromino.o Structure.o
	$(CXX) -o $@ $^ -lncurses

%Test: %Test.o Tetromino.o Structure.o
	$(CXX) -o $@ $^ -lncurses -lgtest -lgtest_main -lpthread

%.o: %.cpp %.h
	$(CXX) -c $<
