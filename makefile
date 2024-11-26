run: main
	@./main

compile main: main.c
	@gcc -o main main.c

clean:
	@rm main
