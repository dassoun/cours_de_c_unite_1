all : stats.exe test_array.exe
	echo "Compilation terminée"

stats.exe : stats.o intarray.o tools.o
	gcc stats.o intarray.o tools.o -o stats.exe

test_array.exe : test_array.o intarray.o tools.o jstr.o stringarray.o
	gcc test_array.o intarray.o tools.o jstr.o stringarray.o -o test_array.exe

intarray.o : intarray.c intarray.h tools.h
	gcc -c intarray.c

jstr.o : jstr.c jstr.h tools.h intarray.o
	gcc -c jstr.c

stringarray.o : stringarray.c stringarray.h jstr.h tools.h
	gcc -c stringarray.c

test_array.o : test_array.c intarray.h tools.h jstr.h stringarray.h
	gcc -c test_array.c

tools.o : tools.c tools.h
	gcc -c tools.c

stats.o : stats.c intarray.h tools.h
	gcc -c stats.c 