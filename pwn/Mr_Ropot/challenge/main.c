#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	alarm(0x3c);
}

void ignore_me() {
	int x = 0xc35f;
	return;
}

void banner() {
	puts("⣿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣛⣛⣛⣛⣛⣛⣛⣛⡛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣿");
	puts("⣿⠀⠀⠀⠀⢀⣠⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣀⠀⠀⠀⠀⣿");
	puts("⣿⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⡀⠀⣿");
	puts("⣿⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣿");
	puts("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿");
	puts("⣿⠀⠈⢻⣿⠿⠛⠛⠛⠛⠛⢿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠛⠛⠛⠻⣿⣿⠋⠀⣿");
	puts("⣿⠛⠁⢸⣥⣴⣾⣿⣷⣦⡀⠀⠈⠛⣿⣿⠛⠋⠀⢀⣠⣾⣿⣷⣦⣤⡿⠈⢉⣿");
	puts("⣿⢋⣩⣼⡿⣿⣿⣿⡿⠿⢿⣷⣤⣤⣿⣿⣦⣤⣴⣿⠿⠿⣿⣿⣿⢿⣷⣬⣉⣿");
	puts("⣿⣿⣿⣿⣷⣿⡟⠁⠀⠀⠀⠈⢿⣿⣿⣿⢿⣿⠋⠀⠀⠀⠈⢻⣿⣧⣿⣿⣿⣿");
	puts("⣿⣿⣿⣿⣿⣿⣥⣶⣶⣶⣤⣴⣿⡿⣼⣿⡿⣿⣇⣤⣴⣶⣶⣾⣿⣿⣿⣿⣿⣿");
	puts("⣿⣿⣿⡿⢛⣿⣿⣿⣿⣿⣿⡿⣯⣾⣿⣿⣿⣮⣿⣿⣿⣿⣿⣿⣿⡟⠿⣿⣿⣿");
	puts("⣿⣿⡏⠀⠸⣿⣿⣿⣿⣿⠿⠓⠛⢿⣿⣿⡿⠛⠛⠻⢿⣿⣿⣿⣿⡇⠀⠹⣿⣿");
	puts("⣿⣿⡁⠀⠀⠈⠙⠛⠉⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠈⠙⠛⠉⠀⠀⠀⣿⣿");
	puts("⣿⠛⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠛⣿");
	puts("⣿⠀⠈⢳⣶⣤⣤⣤⣤⡄⠀⠀⠠⠤⠤⠤⠤⠤⠀⠀⢀⣤⣤⣤⣤⣴⣾⠃⠀⣿");
	puts("⣿⠀⠀⠈⣿⣿⣿⣿⣿⣿⣦⣀⡀⠀⠀⠀⠀⠀⣀⣤⣾⣿⣿⣿⣿⣿⠇⠀⠀⣿");
	puts("⣿⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⣿");
	puts("⣿⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⣿");
	puts("⣿⠀⠀⠀⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠁⠀⠀⠀⠀⣿");
	puts("⣿⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⣿");
	puts("⠛⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠛⠛⠉⠉⠛⠛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠛");
}

int main(void) {

	char cmd[32];
	memset(cmd, '\0', sizeof(cmd));
	
	setup();

	banner();

	while (1) {

		printf("d0lorezh4ze@fsociety: ");
		scanf("%s", cmd);

		if (!strcmp(cmd, "help")) {
			puts("Available commands: help, banner, exit");
		}
		else if (!strcmp(cmd, "banner")) {
			banner();
		}
		else if (!strcmp(cmd, "\x13\x37\xfa\xce")) {
			printf("%p\n", &puts);
		}
		else if (!strcmp(cmd, "exit")) {
			break;
		}
		else {
			continue;
		}
	}

	return 0;
}
