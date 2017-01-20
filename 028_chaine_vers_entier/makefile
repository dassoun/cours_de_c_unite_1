test_array.exe : test_array.o intarray.o tools.o
	gcc test_array.o intarray.o tools.o -o test_array.exe

intarray.o : intarray.c intarray.h
	gcc -c intarray.c

tes_array.o : test_array.c intarray.h
	gcc -c test_array.c

tools.o : tools.c tools.h
	gcc -c tools.c