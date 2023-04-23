all: exp1 exp3 #exp2 exp4 #Htest

exp1: exp1.o  # test program for Pq.h Avltree2.h and heap2.h implementation.
	g++ -Wall -o exp1 exp1.o  

# exp2: exp2.o  # test program for Pq.h Avltree2.h and heap2.h implementation.
# 	g++ -Wall -o exp2 exp2.o  

exp3: exp3.o  # test program for Pq.h Avltree2.h and heap2.h implementation.
	g++ -Wall -o exp3 exp3.o  

# exp4: exp4.o  # test program for Pq.h Avltree2.h and heap2.h implementation.
# 	g++ -Wall -o exp4 exp4.o  

#Dtest: Dtest.o  # test program for depth(x) implementation.
#	g++ -Wall -o Dtest Dtest.o  

#Htest: Htest.o  # test program for height() implementation.
#	g++ -Wall -o Htest Htest.o  

#Exp1: Exp1.o  # test program for experiment of Part 1
#	g++ -Wall -o Exp1 Exp1.o  

#Exp2: Exp2.o  # test program for experiment of Part 2
#	g++ -Wall -o Exp2 Exp2.o  


exp1.o: exp1.cpp
	g++ -Wall -o exp1.o -c exp1.cpp 

# exp2.o: exp2.cpp
# 	g++ -Wall -o exp2.o -c exp2.cpp 

exp3.o: exp3.cpp
	g++ -Wall -o exp3.o -c exp3.cpp 

# exp4.o: exp4.cpp
# 	g++ -Wall -o exp4.o -c exp4.cpp 

#Dtest.o: Dtest.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Dtest.o -c Dtest.cpp 

#Htest.o: Htest.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Htest.o -c Htest.cpp 

#Exp1.o: Exp1.cpp BinarySearchTree.h dsexceptions.h
#	g++ -Wall -o Exp1.o -c Exp1.cpp 

#Exp2.o: Exp2.cpp BinarySearchTree.h AvlTree.h dsexceptions.h
#	g++ -Wall -o Exp2.o -c Exp2.cpp 

# rm -f exp1 exp2 exp3 exp4*.o

clean:
	rm -f exp1 exp3*.o
	