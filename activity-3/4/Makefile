all: sender reciver

sender: sender.c 
	gcc sender.c -lrt -o sender.out
	
reciver: reciver.c 
	gcc reciver.c -lrt -o reciver.out
	
runclient:
	./reciver.out

runsender:
	./sender.out

clean:
	rm -rf *.out *.o