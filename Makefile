last: problem_13.exe

run: problem_13.exe number_utils.o
	$<

%.exe: %.cpp number_utils.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^

clean:
	rm *.exe *.o
