a.exe: 6amain.o 6aimp1.o 
	gcc -o a.exe 6amain.o 6aimp1.o 
6amain.o : 6amain.c 6a.h
	gcc -c 6amain.c
6aimp1.o : 6aimp1.c 6a.h
	gcc -c 6aimp1.c