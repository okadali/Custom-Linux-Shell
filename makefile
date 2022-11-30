all: myshell writef execx run
myshell: myshell.c
		 gcc myshell.c -lreadline;
writef: writef.c
		  gcc writef.c -o writef
execx: execx.c
		 gcc execx.c -o execx
run:
	./a.out