HEADERS = $(wildcard *.h)
HEADERS_O = ${HEADERS:.h=.o}

last: problem_18.exe

run: problem_18.exe ${HEADERS_O}
	$<

%.exe: %.cpp ${HEADERS_O}
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^

clean:
	rm *.exe *.o
