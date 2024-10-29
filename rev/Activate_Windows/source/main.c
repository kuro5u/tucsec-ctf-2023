#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN		29

#define RED			"\x1b[31m\x1b[1m"
#define GREEN		"\x1b[32m\x1b[1m"
#define YELLOW		"\x1b[33m\x1b[1m"
#define BLUE		"\x1b[34m\x1b[1m"
#define NC			"\x1b[0m"

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
}

void banner() {
	printf("                                           \n");
	printf("        %s,.=:!!t3Z3z.,%s                  \n", RED, NC);
	printf("       %s:tt:::tt333EE3%s                  \n", RED, NC);
	printf("       %sEt:::ztt33EEEL %s@Ee.,      ..,%s \n", RED, GREEN, NC);
	printf("      %s;tt:::tt333EE7 %s;EEEEEEttttt33#%s \n", RED, GREEN, NC);
	printf("     %s:Et:::zt333EEQ. %s$EEEEEttttt33QL%s \n", RED, GREEN, NC);
	printf("     %sit::::tt333EEF %s@EEEEEEttttt33F%s  \n", RED, GREEN, NC);
	printf("    %s;3=*^```\"*4EEV %s:EEEEEEttttt33@.%s \n", RED, GREEN, NC);
	printf("    %s,.=::::!t=., %s` %s@EEEEEEtttz33QF%s \n", BLUE, RED, GREEN, NC);
	printf("   %s;::::::::zt33)   %s\"4EEEtttji3P*%s   \n", BLUE, GREEN, NC);
	printf("  %s:t::::::::tt33.%s:Z3z..  %s``%s ,..g.%s\n", BLUE, YELLOW, GREEN, YELLOW, NC);
	printf("  %si::::::::zt33F %sAEEEtttt::::ztF%s     \n", BLUE, YELLOW, NC);
	printf(" %s;:::::::::t33V %s;EEEttttt::::t3%s      \n", BLUE, YELLOW, NC);
	printf(" %sE::::::::zt33L %s@EEEtttt::::z3F%s      \n", BLUE, YELLOW, NC);
	printf("%s{3=*^```\"*4E3) %s;EEEtttt:::::tZ`%s     \n", BLUE, YELLOW, NC);
	printf("             `%s :EEEEtttt::::z7%s         \n", YELLOW, NC);
	printf("                 %s\"VEzjt:;;z>*`%s        \n", YELLOW, NC);
	printf("                                           \n");
}

void error(char* msg) {
	puts(msg);
	exit(EXIT_FAILURE);
}

int main() {

	char product_key[32] = {0};

	setup();

	puts("\nWindows XP Professional - Activation");
	banner();

	puts("For activation you will need the product key that was provided to you at purchase. Your \
product key should be in an email from whoever sold or distributed Windows to you, or on the \
box the Windows DVD or USB came in.\n");

	// puts("The product key looks similar to this:");
	// puts("PRODUCT KEY: XXXXX-XXXXX-XXXXX-XXXXX-XXXXX\n");

	printf("Please enter your product key: ");
	fread(&product_key, 1, KEY_LEN, stdin);

	// check format
	int i;
	for (i = 0; i < KEY_LEN; i++) {
		if (i % 6 == 5) {
			if (product_key[i] != '-') {
				error("Invalid key format!");
			}
		}
		else {
			if (product_key[i] < '0' || (product_key[i] > '9' && product_key[i] < 'A') || product_key[i] > 'Z') {
				error("Invalid key character!");
			}
		}
	}
	
	// check validity
	unsigned int sum = 0;
	for (i = 0; i < KEY_LEN; i++) {
		sum += product_key[i];
	}

	if (sum != 1905) {
		error("Invalid key!");
	}
	else {
		puts("\nWindows was successfully activated. Press ENTER to exit.");
		getchar();
		getchar();
		printf("Activation ID: ");
		system("cat ./flag.txt");
		exit(EXIT_SUCCESS);
	}
}
