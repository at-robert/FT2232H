all : sample_fifo.c
	gcc -c sample_fifo.c -o sample_fifo.o
	gcc -o sample_fifo.exe sample_fifo.o -L. -lftd2xx

write: sample_fifo_w.c
	gcc -c sample_fifo_w.c -o sample_fifo_w.o
	gcc -o sample_fifo_w.exe sample_fifo_w.o -L. -lftd2xx

clean :
	del sample_fifo.exe
	del sample_fifo.o
	del sample_fifo_w.exe
	del sample_fifo_w.o