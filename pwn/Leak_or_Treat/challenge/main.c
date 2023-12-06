#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	alarm(0x3c);
}

int main() {

	char buf[128] = {0};
	char flag[64] = {0};
	
	setup();

	FILE* file = fopen("./flag.txt", "r");
	fread(flag, 1, sizeof(flag), file);
	fclose(file);

	puts("I can echo back whatever you say! Isn't that great?");
	
	while(1) {
		printf("\nFus Ro Dah: ");
		
		fgets(buf, sizeof(buf), stdin);

		printf("\n*echoes back* ");
		
		printf(buf);
	}
}
