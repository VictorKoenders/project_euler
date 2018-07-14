last: problem_14.exe

run: problem_14.exe
	$<

%.exe: %.cpp number_utils.o time_utils.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^

clean:
	rm *.exe *.o
