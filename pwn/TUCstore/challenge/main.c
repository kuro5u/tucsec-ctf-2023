#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED			"\x1b[31m\x1b[1m"
#define GREEN		"\x1b[32m\x1b[1m"
#define YELLOW		"\x1b[33m\x1b[1m"
#define BLUE		"\x1b[34m\x1b[1m"
#define MAGENTA		"\x1b[35m\x1b[1m"
#define CYAN		"\x1b[36m\x1b[1m"
#define NUM_COLORS	6

unsigned int tucoins = 10000;

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	alarm(0x3c);
}

void random_color() {
	const char* colors[NUM_COLORS] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};
	srand(time(NULL));
	puts(colors[rand() % NUM_COLORS]);
}

void banner() {
	random_color();
	puts("                                         ");
	puts("          .                              ");
	puts("        ('                               ");
	puts("        '|                               ");
	puts("        |'                               ");
	puts("       [::]                              ");
	puts("       [::]   _......_                   ");
	puts("       [::].-'      _.-`.                ");
	puts("       [:.'    .-. '-._.-`.              ");
	puts("       [/ /\\   |  \\        `-..        ");
	puts("       / / |   `-.'      .-.   `-.       ");
	puts("      /  `-'            (   `.    `.     ");
	puts("     |           /\\      `-._/      \\\\");
	puts("     '    .'\\   /  `.           _.-'|   ");
	puts("    /    /  /   \\_.-'        _.':;:/    ");
	puts("  .'     \\_/             _.-':;_.-'     ");
	puts(" /   .-.             _.-' \\;.-'         ");
	puts("/   (   \\       _..-'     |             ");
	puts("\\    `._/  _..-'    .--.  |             ");
	puts(" `-.....-'/  _ _  .'    '.|              ");
	puts("          | |_|_| | TUC  | \\  (o)       ");
	puts("     (o)  | |_|_| |      | | (\\'/)      ");
	puts("    (\\'/)/  ''''' |     o|  \\;:;       ");
	puts("     :;  |        |      |  |/)          ");
	puts("      ;: `-.._    /__..--'\\.' ;:        ");
	puts("          :;  `--' :;   :;               ");
	puts("                                         ");
	// puts("\x1b[0m");
}

void menu() {
	puts("");
	printf("[ Balance: %u TC ]\n\n", tucoins);
	puts("1. Coffee (10 TC)");
	puts("2. ECE Degree (1.200 TC)");
	puts("3. Beauty secret (3.330 TC)");
	puts("4. Deadliest self-defense move (5.800 TC)");
	puts("5. Vsam's root password (6.500 TC)");
	puts("6. HEYYEYAAEYAAAEYAEYAA (7.770 TC)");
	puts("7. King Terry the Terrible (8.840 TC)");
	puts("8. Universal backdoor (9.960 TC)");
	puts("9. Flag (4.000.000.000 TC)");
	puts("0. Leave");
	printf("> ");
}

void purchase(unsigned int cost, const char* message) {
	if (tucoins >= cost) {
		tucoins -= cost;
		puts(message);

		printf("\nWould you like to leave a tip? [Y/n] ");

		unsigned char c;
		scanf("%c", &c);
		getchar();

		if (c == 121 || c == 89) {
			tucoins--;
			puts("Oh, you're so kind! ❤️");
		}
	}
	else {
		puts("Not enough TUCoins.");
	}
}

int main() {

	setup();

	banner();
	puts("Welcome to the TUCstore!");
	puts("Anything piques your interest?");

	while (1) {
		menu();

		int choice;
		scanf("%d", &choice);
		getchar();
		puts("");

		switch (choice) {
			case 1:
				purchase(10, "Here's your coffee! ☕");
				break;

			case 2:
				purchase(1200, "Buy some for your friends too! 📜");
				break;

			case 3:
				purchase(3330, "Here you go: https://www.youtube.com/watch?v=w8pBpesjse4 😘");
				break;

			case 4:
				purchase(5800, "Use this wisely: https://www.youtube.com/watch?v=xHEgHjJvR94 🤜");
				break;

			case 5:
				purchase(6500, "vsam:k1s5%RtfM! 🔑");
				break;

			case 6:
				purchase(7700, "And I say: https://www.youtube.com/watch?v=ZZ5LpwO-An4 🎶");
				break;

			case 7:
				purchase(8840, "Most sane Linux user: https://www.youtube.com/watch?v=WLwldp2KzMI 🐧");
				break;

			case 8:
				purchase(9960, "RMS and tea: https://www.youtube.com/watch?v=v9B8y-AAdmA 🌐🔙🚪");
				break;

			case 9:
				if (tucoins >= 4000000000) {
					tucoins -= 4000000000;
					puts("Here is your flag! 🚩\n");
					system("cat ./flag.txt");
				}
				break;

			case 0:
				puts("Glad doing business with ya!");
				return 1;

			default:
				puts("Invalid choice.");
				break;
		}
	}

	return 0;
}
