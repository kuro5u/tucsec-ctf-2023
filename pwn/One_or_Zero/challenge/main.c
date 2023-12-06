#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	alarm(0x3c);
}

void zero() {
	puts("You are not needed here.");
}

void one() {
	char flag[64] = {0};

	FILE* file = fopen("./flag.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Error opening file.");
		return;
	}
	fread(&flag, 1, sizeof(flag), file);
	fclose(file);

	printf("%s\n", flag);

	return;
}

int main() {

	char buf[64] = {0};
	char c = 0;

	setup();

	puts("Tell me one thing Elliot. Are you a 1 or a 0?");
	printf("> ");

	scanf("%c", &c);
	getchar();

	if (c == 1) {
		puts("Show me.");
		printf("> ");
		fgets(buf, 0x64, stdin);
	}
	else {
		zero();
	}

	return 0;
}
