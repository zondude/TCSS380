pr1: driver.o logic.o
	gcc -o pr1 driver.o logic.o

driver.o: driver.c logic.h
	gcc -c driver.c

logic.o: logic.c logic.h
	gcc -c logic.c