
user1:
	gcc  rsocket.h 
	gcc  -c rsocket.c 
	ar rcs librsocket.a rsocket.o
	gcc  user1.c -o user1 -L . -lrsocket -pthread -lrt


user2:
	gcc  rsocket.h
	gcc  -c rsocket.c 
	ar rcs librsocket.a rsocket.o
	gcc  user2.c -o user2 -L . -lrsocket -pthread -lrt	

librsocket.a:
	gcc rsocket.h
	gcc -c rsocket.c
	ar rcs librsocket.a rsocket.o

clean:
	rm rsocket.o user1 user2 librsocket.a
	
cleanlib:
	rm librsocket.a rsocket.o



