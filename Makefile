FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: SquareEqualation

SquareEqualation : main.o input.o output.o test.o solving.o mathematics.o isflag.o
	g++ main.o input.o output.o test.o solving.o mathematics.o isflag.o -o SquareEqualation $(FLAGS)

main.o : main.cpp test.h input.h output.h solving.h isflag.h
	g++ main.cpp -c $(FLAGS)

input.o : input.cpp solving.h
	g++ -c input.cpp $(FLAGS)

output.o : output.cpp solving.h
	g++ -c output.cpp $(FLAGS)

test.o : test.cpp mathematics.h solving.h test.h
	g++ -c test.cpp $(FLAGS)

solving.o : solving.cpp mathematics.h solving.h
	g++ -c solving.cpp $(FLAGS)
 
mathematics.o : mathematics.cpp mathematics.h solving.h
	g++ -c mathematics.cpp $(FLAGS)

isflag.o : isflag.cpp isflag.h
	g++ -c isflag.cpp $(FLAGS) 

.PHONY: clean

clean:
	rm -f *.o