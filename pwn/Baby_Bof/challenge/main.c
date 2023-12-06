#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Ignore this */
void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	alarm(0x3c);
}

/* Don't waste time deobfuscating */
void not_happening() {
	printf("\x59""e\141h\x2C"" \164h\x61""t\040w\x61""s\040p\x6F""i\156-""\x20");sleep((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A07));puts("\x57""a\151t\x2E"".");sleep((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));puts("\x57""h\141t\x20""i\163 \x67""o\151n\x67"" \157n\x3F""?");sleep((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));printf("\x57""H\101T\x20""D\111D\x20""Y\117U\x20""D\117?");sleep((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));puts("\x20""\x53""T\117P\x21""");sleep((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));puts("\x0a""\x57""e\154c\x6F""m\145 \x61""d\155i\x6E""!\040H\x65""r\145 \x69""s\040y\x6F""u\162 \x66""l\141g\x3A""");system("\x63""a\164 \x2E""/\146l\x61""g\056t\x78""t");puts("\x0A""N\117O\x4F""O\117!\x21""!");
}

int main() {

	int admin = 0;
	char buf[140] = {0};

	setup();

	puts("Welcome to TUCsec CTF! Unfortunately, it's impossible to get the flag..");
	printf("> ");

	gets(buf);

	if (admin) {
		not_happening(); // Prints the flag. Not happening though
	}
	else {
		puts("Yeah, that was pointless.");
	}

	return 0;
}
