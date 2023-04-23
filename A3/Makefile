all: PQdemo #Dtest Htest Exp1 Exp2

PQdemo: PQdemo.o  # test program for Pq.h Avltree2.h and heap2.h implementation.
	g++ -Wall -o PQdemo PQdemo.o  

#Dtest: Dtest.o  # test program for depth(x) implementation.
#	g++ -Wall -o Dtest Dtest.o  

#Htest: Htest.o  # test program for height() implementation.
#	g++ -Wall -o Htest Htest.o  

#Exp1: Exp1.o  # test program for experiment of Part 1
#	g++ -Wall -o Exp1 Exp1.o  

#Exp2: Exp2.o  # test program for experiment of Part 2
#	g++ -Wall -o Exp2 Exp2.o  


PQdemo.o: PQdemo.cpp AvlTree.h heap.h PQ.h dsexceptions.h
	g++ -Wall -o PQdemo.o -c PQdemo.cpp 

#Dtest.o: Dtest.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Dtest.o -c Dtest.cpp 

#Htest.o: Htest.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Htest.o -c Htest.cpp 

#Exp1.o: Exp1.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Exp1.o -c Exp1.cpp 

#Exp2.o: Exp2.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
#	g++ -Wall -o Exp2.o -c Exp2.cpp 


clean:
	rm -f PQdemo *.o
