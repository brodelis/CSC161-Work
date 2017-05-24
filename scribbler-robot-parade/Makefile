parade: parade.c parade_functions.c parade.h
	gcc -std=c11 -I/home/walker/MyroC/include -L/home/walker/MyroC/lib -lm -lMyroC -lbluetooth -ljpeg -leSpeakPackage -Wall -Wextra -g parade.c parade_functions.c -o parade
.PHONY: clean
clean:
	rm -rf parade *.o *.core
