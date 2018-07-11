last: problem_10.exe

run: problem_10.exe
	./$^

%.exe: %.cpp number_utils.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^

clean:
	rm *.exe *.o
