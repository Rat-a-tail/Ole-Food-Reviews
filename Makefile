User.o:	User.cpp	User.h
	g++ -g -Wall -c User.cpp

UserDriver.o:	UserDriver.cpp	User.h
	g++ -g -Wall -c UserDriver.cpp

UserDriver:     User.o  UserDriver.o
	g++ -g -Wall -o UserDriver User.o UserDriver.o

