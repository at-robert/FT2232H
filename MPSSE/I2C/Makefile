all : sample-static.c
	gcc -c sample-static.c -o sample-static.o
	gcc -o sample-static.exe sample-static.o -L. -lMPSSE	

clean :
	del sample-static.exe
	del sample-static.o