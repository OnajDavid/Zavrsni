#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void quit_game() {
	char answer = '0';
	printf("Are you Sure you wish to EXIT the game?\n\nY - Exit\nN - Don't Exit\n");
		scanf("%c", &answer);
		if (answer == 'Y')
		{
			printf("Quitting...");
			exit(420);
		}
		else if (answer == 'N')
		{
			printf("Understood. Returning to game\n");
			return;
		}
		quit_game();

}

void help_menu() {
	printf("===================HOW TO PLAY THE GAME====================\n");
	printf("Your GOAL is to Lock yourself into your own home.\nYou do this by Interracting with Your Enviroment.\n");
	printf("In order to win you need to:\n1. Lock The Front Door\n2. Put the living room Drawer in front of the Front Door\n3. Barricade the window\n4. Lock the Bedroom Door\n5. Put the closet in front of the Bedroom Door\n");
	printf("Admin priveledge, main menu 0 instant play game.\n");
	printf("Good Luck!\n");
	printf("===================NOW GO PLAY THE GAME====================\n");
	return;
}

void move_prompt() {
	printf("Moving...\n");
	return;
}
void game_over(int i) {
	printf("TIME- %d A.M.\n", i);
	if (i < 5)
	{
		sleep();
		printf("You ravage the village.\n");
		sleep();
		printf("GAME OVER\n");
		return;
	}
	else if (i == 5)
	{
		sleep();
		printf("You escape into the forest where you spend the rest of your days.\n");
		sleep();
		printf("GAME OVER\n");
		return;
	}
	else if (i == 6)
	{
		sleep();
		printf("As the Sun Rises once more it Bathes you in it's light. You have managed to NOT ESCAPE.\n");
		sleep();
		printf("YOU WIN\n");
		return;
	}

}

void monster_turn(int i) {
	sleep();
	char eater;
	printf("The time is now %d:00.\n", i);
}

void sleep() {
	int milli_seconds = 1000 * 2;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}