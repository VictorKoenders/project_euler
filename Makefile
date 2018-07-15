HEADERS = $(wildcard *.h)
HEADERS_O = ${HEADERS:.h=.o}

last: problem_23.exe

run: problem_23.exe ${HEADERS_O}
	$<

%.exe: %.cpp ${HEADERS_O}
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^

clean:
	rm *.exe *.o
