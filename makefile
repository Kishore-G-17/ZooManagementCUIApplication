output:zooApplicationRunner.o ArrayOperations.o
	g++ zooApplicationRunner.o ArrayOperations.o -o output
zooApplicationRunner.o:zooApplicationRunner.cpp
	g++ -c zooApplicationRunner.cpp
ArrayOperations.o:ArrayOperations.cpp
	g++ -c ArrayOperations.cpp