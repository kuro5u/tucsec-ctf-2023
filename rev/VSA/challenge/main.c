#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 32

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
}

void banner() {
	puts("__   _____  __ _   ");
	puts("\\ \\ / / __|/ _` |");
	puts(" \\ V /\\__ | (_| |");
	puts("  \\_/ |___/\\__,_|");
	puts("");
}

int main() {

	char username[BUF_SIZE] = {0};
	char password[BUF_SIZE] = {0};

	setup();

	banner();

	puts("Welcome to my Very Secure App!");

	printf("Username: ");
	scanf("%31s", username);
	getchar();

	if (strcmp(username, "d10br4nd0")) {
		puts("Ho? You dare try hacking me?");
		return -1;
	}

	printf("Password: ");
	scanf("%31s", password);
	getchar();
	
	if (!strcmp(password, "Z4@WARUDO0!!")) {
		puts("NANI?!");
		system("cat ./flag.txt");
	}
	else {
		puts("MUDA MUDA MUDA!");
		return -1;
	}
	
	return 0;
}
