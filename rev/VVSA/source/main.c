#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>

#define BUF_SIZE 32
#define DIGEST_LENGTH 16

unsigned char username[] = {0xcb, 0x31, 0x48, 0x93, 0xc0, 0xd6, 0x74, 0x1d, 0x7b, 0x99, 0x15, 0x24, 0x75, 0x04, 0x05, 0xcc};
unsigned char enc_password[] = {0x3d, 0x7b, 0x52, 0x26, 0xb0, 0x9e, 0xea, 0x8f, 0xc, 0x70, 0x52, 0x48, 0xad, 0xff, 0x89, 0x8a, 0x5, 0x53, 0x13};
unsigned char key[] = {0x69, 0x13, 0x37, 0x69, 0xde, 0xad, 0xba, 0xbe};

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	alarm(0x3c);
}

void banner() {
	puts("__   ___   _____  __ _ ");
	puts("\\ \\ / \\ \\ / / __|/ _` |");
	puts(" \\ V / \\ V /\\__ | (_| |");
	puts("  \\_/   \\_/ |___/\\__,_|");
	puts("");
}

void loading() {
	int i;
	printf("\nChecking credentials.. Please wait");
	for (i = 0; i < 9; ++i) {
		printf(".");
		usleep(500000);
		if ((i + 1) % 3 == 0) {
			printf("\b\b\b   \b\b\b");
		}
	}
	puts("");
}

void md5(char* input, unsigned char* hash) {
	unsigned int digestLength = DIGEST_LENGTH;

	EVP_MD_CTX* context = EVP_MD_CTX_new();
	EVP_DigestInit_ex(context, EVP_md5(), NULL);
	EVP_DigestUpdate(context, input, strlen(input));
	EVP_DigestFinal_ex(context, hash, &digestLength);
	EVP_MD_CTX_free(context);
}

void remove_newline(char* buf) {
	char* p = strchr(buf, 10);
	if (p) {
		*p = '\0';
	}
}

int md5cmp(unsigned char* hash1, unsigned char* hash2) {
	int i;
	for (i = 0; i < DIGEST_LENGTH; i++) {
		if (hash1[i] != hash2[i]) {
			return 1;
		}
	}
	return 0;
}

int main() {

	unsigned char hash[DIGEST_LENGTH + 1] = {0};
	unsigned char password[BUF_SIZE] = {0};
	char password_guess[BUF_SIZE] = {0};
	char username_guess[BUF_SIZE] = {0};

	setup();

	banner();

	puts("Welcome to my Very Very Secure App!\n");

	printf("Username: ");
	fgets(username_guess, BUF_SIZE, stdin);
	remove_newline(username_guess);
	md5(username_guess, hash);

	printf("Password: ");
	fgets(password_guess, BUF_SIZE, stdin);
	remove_newline(password_guess);

	loading();

	int i;
	for (i = 0; i < sizeof(enc_password); i++) {
		password[i] = key[i % sizeof(key)] ^ enc_password[i];
	}

	if (md5cmp(hash, username) == 0 && strcmp(password_guess, (char *) password) == 0) {
		puts("\nCan we get much higher?");
		system("/bin/sh");
	}
	else {
		puts("\nYou can't hack me.");
	}

	return 0;
}
