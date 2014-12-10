#================================================================================================
# Project                   : Stack_Queue
# Description           : Edit the build script for this project.
# Creator                  : XU ZAN
# Creation date        : Thur.	April 24, 2014
# Copyright(C)          2014	All rights reserved.
#
#================================================================================================


Objects = Stack_Queue_Main.o Stack.o

Stack_Queue : $(Objects)
	gcc $(Objects) -o Stack_Queue

Stack_Queue_Main.o : Stack_Queue_Main.c
	gcc -c Stack_Queue_Main.c

Stack.o : Stack.c Stack.h
	gcc -c Stack.c


clean :
	rm -f $(Objects) Stack_Queue
