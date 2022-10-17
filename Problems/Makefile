coverage:
	cd Bubble/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Insertion/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Merge/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Quick/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out
	cd Selection/ && make run && gcov prog.c && valgrind --leak-check=yes ./prog test.in test.out