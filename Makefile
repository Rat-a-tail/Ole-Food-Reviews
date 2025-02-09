UserDriver:	User.o	UserDriver.o
	g++ -g -Wall -o UserDriver User.o UserDriver.o

User.o:	User.cpp	User.h
	g++ -g -Wall -c User.cpp

UserDriver.o:	UserDriver.cpp	User.h
	g++ -g -Wall -c UserDriver.cpp

UserArrayDriver:	UserArray.o	UserArrayDriver.o User.o
	g++ -g -Wall -o UserArrayDriver UserArray.o UserArrayDriver.o User.o ../react.o -lcurl

UserArray.o:	UserArray.cpp	UserArray.h
	g++ -g -Wall -c UserArray.cpp

UserArrayDriver.o:	UserArrayDriver.cpp	UserArray.h
	g++ -g -Wall -c UserArrayDriver.cpp

ReviewDriver:	ReviewArray.o	ReviewDriver.o  Review.o
	g++ -g -Wall -o ReviewDriver ReviewDriver.o ReviewArray.o Review.o ../react.o -lcurl

ReviewArray.o:	ReviewArray.cpp	ReviewArray.h
	g++ -g -Wall -c ReviewArray.cpp

ReviewDriver.o:	Review.h	ReviewArray.h   ReviewDriver.cpp
	g++ -g -Wall -c ReviewDriver.cpp

Review.o:	Review.cpp	Review.h 
	g++ -g -Wall -c Review.cpp

Station_Array_Driver:  Station_Array.o Station_Array_Driver.o  Meal_Array.o ReviewArray.o Review.o
	g++ -g -Wall -o Station_Array_Driver Station_Array.o Meal_Array.o ReviewArray.o  Review.o Station_Array_Driver.o ../react.o -lcurl

Station_Array.o:  Station_Array.cpp Station_Array.h 
	g++ -g -Wall -c Station_Array.cpp

Station_Array_Driver.o:  Station_Array_Driver.cpp Station_Array.h 
	g++ -g -Wall -c Station_Array_Driver.cpp

Meal_Array.o:	Meal_Array.cpp Meal_Array.h
	g++ -g -Wall -c Meal_Array.cpp

a.out:	Login.o	User.o UserArray.o Meal_Array.o Station_Array.o
	g++ -g -Wall -o a.out Login.o User.o UserArray.o ../react.o -lcurl

Login.o: Login.cpp UserArray.h User.h Meal_Array.h Station_Array.h
	g++ -g -Wall -c Login.cpp






