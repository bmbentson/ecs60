gradebook.out: gradebook.o GradebookRunner.o
	g++ -Wall -ansi -g -o gradebook.out gradebook.o GradebookRunner.o 

gradebook.o: gradebook.cpp gradebook.h course.h QuadraticProbing.h BinarySearchTree.h Student.h assignment.h
	g++ -Wall -ansi -g -c gradebook.cpp



GradebookRunner.o: GradebookRunner.cpp CPUTimer.h GradebookRunner.h gradebook.h 
	g++ -Wall -ansi -g -c GradebookRunner.cpp

clean:
	rm -f gradebook.out gradebook.o GradebookRunner.o course.o assignment.o Student.o
