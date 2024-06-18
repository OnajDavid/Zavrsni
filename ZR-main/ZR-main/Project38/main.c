#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
 PLAYER player;
 extern int help = 0;
int main(void) {
	void clearInputBuffer();
	srand(time(NULL));
	static int has_lost = 0;
	int game_state[7] = { 0,0,0,0,0,0,0};
	int time = 12;
	char selector = ' ';
	char mm_selector = ' ';
	int bed_ach = 0;
	FILE* dynamic_file_acc = NULL;
	char sentence[101];
	char c;
	dynamic_file_acc = fopen("intro.txt", "r");
	if (dynamic_file_acc == NULL)
	{
		perror("opening intro file");
		printf("welcome to don't escape!\n");
	}
	else
	{
		c = fgetc(dynamic_file_acc);
		while (c != EOF)
		{
			printf("%c",c);
			c = fgetc(dynamic_file_acc);
		}
	}
	if (dynamic_file_acc != NULL)
	{
		fclose(dynamic_file_acc);
	}
	

/*Game state values
0  - Position (0,4 - 0 Bedroom, 1 Living_Room, 2 Basement, 3 Outside, 4 Outside_[back] )
1  - Has Moved Closet
2  - Has Bedroom Key/Locked Door (1,2)
3  - Has Moved Drawer
4  - Has LRoomKey/Locked Door (1,2)
5  - Has Axe/Has Planks (1,2)
6  - Has Boarded Window
*/
	main_menu:
	printf("======================== MAIN MENU ========================\n");
	do
	{
		printf("1. Play\n2. Players\n3. HELP\n4. EXIT\n");
		scanf("%c", &mm_selector);
		if (mm_selector == '1')
		{
			mm_selector = '0';
		}
		else if (mm_selector == '2')
		{
			player_select();
		}
		else if (mm_selector == '3')
		{
			help_menu();
		}
		else if (mm_selector == '4')
		{
			quit_game();
		}
		else
		{
			printf("Kriva Vrijednost...\n");
		}
		clearInputBuffer();
	} while (mm_selector != '0');
	mm_selector = '0';


	//1st for loop is players turn to decide what to do.
	for (int p_time = 0; p_time < 12; )
	{
		if (game_state[0] == 0)
		{
			printf("===========================================================\nYou are currently in the Bedroom. What do you do?\n1. Go to the Living Room.\n2. Go to Bed. \n3. Look in The Mirror. \n4. Move The Closet. \n5. Use The Bedroom Key \n6. HELP\n7. QUIT\n===========================================================\n");
		}
		else if (game_state[0] == 1)
		{
			printf("===========================================================\nYou are currently in the Living Room. What do you do?\n1. Enter the Bedroom.\n2. Enter the Basement. \n3. Go Outside. \n4. Move the Kitchen Drawer. \n5. Use The Living Room Key \n6. HELP\n7. QUIT\n===========================================================\n");
		}
		else if (game_state[0] == 2)
		{
			printf("===========================================================\nYou are currently in the Basement. What do you do?\n1. Go to the Living Room.\n2. Inspect the Workbench. \n3. Look in your Journal. \n4. Look at the Floor \n5. Look at the Ceiling. \n6. HELP\n7. QUIT\n===========================================================\n");
		}
		else if (game_state[0] == 3)
		{
			printf("===========================================================\nYou are currently in Front of The House. What do you do?\n1. Go to the Living Room.\n2. Go to the back. \n3. Inspect the stones. \n4. Look at the Village. \n5. Look at your Home. \n6. HELP\n7. QUIT\n===========================================================\n");
		}
		else if (game_state[0] == 4)
		{
			printf("===========================================================\nYou are currently Behind the House. What do you do?\n1. Go to the front.\n2. Look at the Forest. \n3. Inspect the shed. \n4. Inspect the window. \n5. Look at the sky. \n6. HELP\n7. QUIT\n===========================================================\n");
		}
		//printf("TEST\nPosition - %d\nHas Moved Closet - %d\nHas Bed Key/Locked - %d\nHas Moved Drawer - %d\nHas LRoomKey/Locked Door - %d\nHas Axe/Has Planks - %d\nTEST\n", game_state[0], game_state[1], game_state[2], game_state[3], game_state[4], game_state[5]);
		//TESTER: Checking to see what player chooses to do.
		do
		{
			scanf("%c", &selector);
			if (selector != '1' && selector != '2' && selector != '3' && selector != '4' && selector != '5' && selector != '6' && selector != '7')
			{
				printf("Kriva Vrijednost..\n");
				clearInputBuffer();
			}
		} while (selector != '1' && selector != '2' && selector != '3' && selector != '4' && selector != '5' && selector != '6' && selector != '7');
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
//Checking for Bedroom
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (game_state[0] == 0 && selector == '1')
		{
			if (game_state[1] == 0 && game_state[2] != 2)
			{
				move_prompt();
				game_state[0] = 2;

			}
			else if (game_state[1] == 1)
			{
				printf("You cannot leave. You Trapped Yourself in Here.\n");
			}
			else if (game_state[2] == 2)
			{
				printf("The door is locked...\n");
			}
		}

		else if (game_state[0] == 0 && selector == '2')
		{
			p_time++;
			printf("As you look to your bed, a sudden tiredness strikes you. You lie down and sleep for an Hour....\nThe time is now %d:00.\n", p_time + time);
			bed_ach++;
		}

		else if (game_state[0] == 0 && selector == '3')
		{
			p_time++;
			printf("You Look like you don't smell too good. You haven't showered in a while....\nThe time is now %d:00.\n", p_time + time);
		}

		else if (game_state[0] == 0 && selector == '4')
		{
			if (game_state[1] == 0)
			{
				p_time++;
				printf("Pushing the Closet is harder than it looked. Now it's in front of the door...\nThe time is Now: %d:00.\n", p_time + time);
				game_state[1] = 1;
			}
			else
			{
				p_time++;
				printf("Seeing as you are stuck in your room, you push the Closet back to where it was, Wasting time as you do...\nThe time is Now: %d:00.\n", p_time + time);
				game_state[1] = 0;
			}
		}

		else if (game_state[0] == 0 && selector == '5')
		{
			if (game_state[2] == 0)
			{
				printf("What Key? You don't Have the Key.\n");
			}
			else if (game_state[2] == 1)
			{
				printf("You lock the Bedroom Door!\n");
				game_state[2] = 2;
			}
			else if (game_state[2] == 2)
			{
				printf("You unlock the Bedroom Door!\n");
				game_state[2] = 1;
			}
		}

//---------------------------------------------------------------------------------------------------------------------------------------------------------	
//Checking for Living Room
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (game_state[0] == 1 && selector == '1')
		{
			move_prompt();
			game_state[0] = 0;
		}
		else if (game_state[0] == 1 && selector == '2')
		{
			move_prompt();
			game_state[0] = 2;
			selector = -1;
		}
		else if (game_state[0] == 1 && selector == '3')
		{
			if (game_state[3] == 0 && game_state[4] != 2)
			{
				move_prompt();
				game_state[0] = 3;
				selector = -1;
			}
			else if (game_state[3] == 1)
			{
				printf("You cannot leave the house because the Drawer is in the way...\n");
			}
			else if (game_state[4] == 2)
			{
				printf("The Front Door is locked...\n");
			}
		}
		else if (game_state[0] == 1 && selector == '4')
		{
			p_time++;
			if (game_state[3] == 0)
			{
				game_state[3] = 1;
				printf("You notice the Kitchen Drawer and move it in front of the Front Door. You have now blocked the Front Door. ");
				printf("The time is now %d:00.\n", p_time + time);
			}
			else if (game_state[3] == 1)
			{
				game_state[3] = 0;
				printf("You move the Kitchen Drawer out of the way of the front door. ");
				printf("The time is now %d:00.\n", p_time + time);
			}

		}
		else if (game_state[0] == 1 && selector == '5')
		{
			if (game_state[4] == 0)
			{
				printf("What Key? You don't Have the Key.\n");
			}
			else if (game_state[4] == 1)
			{
				printf("You lock the Front Door!\n");
				game_state[4] = 2;
			}
			else if (game_state[4] == 2)
			{
				printf("You unlock the Front Door!\n");
				game_state[4] = 1;
			}
		}

//---------------------------------------------------------------------------------------------------------------------------------------------------------	
//Checking for Basement
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (game_state[0] == 2 && selector == '1')
		{
			game_state[0] = 1;
		}
		else if (game_state[0] == 2 && selector == '2')
		{
			p_time++;
			if (game_state[2] == 0)
			{
				game_state[2] = 1;
				printf("You approach your workbench and notice a shiny key sitting next to your tools. You pick it up\n");
				printf("You have gained The Bedroom Key.\n");
				printf("The time is now %d:00.\n", p_time + time);
			}
			else if (game_state[2] == 1)
			{
				printf("You already have the Bedroom Key!\n");
			}
		}
		else if (game_state[0] == 2 && selector == '3')
		{
			p_time++;
			printf("You spend some time looking at your journal, flipping trough the pages. Eventually you land on one and read it:\n");
			journal();
		}
		else if (game_state[0] == 2 && selector == '4')
		{
			p_time++;
			printf("The floor seems to be made out of floor.\n");
			printf("The time is now %d:00.\n", p_time + time);
		}
		else if (game_state[0] == 2 && selector == '5')
		{
			p_time++;
			printf("The ceiling is very nice.\n");
			printf("The time is now %d:00.\n", p_time + time);
		}

//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		//Checking for Outisde F
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (game_state[0] == 3 && selector == '1')
		{
			game_state[0] = 1;
		}
		else if (game_state[0] == 3 && selector == '2')
		{
			game_state[0] = 4;
		}
		else if (game_state[0] == 3 && selector == '3')
		{
			printf("%d\n", game_state[4]);
			if (game_state[4] == 0)
			{
				game_state[4] = 1;
				p_time++;
				printf("Taking the time to REALLY get up close and personal with your own front porch stones, You turn one over and find a key.\n");
				printf("You have gained The Front Door Key!\n");
				printf("The time is now %d:00.\n", p_time + time);
			}
			else if (game_state[4] == 1)
			{
				printf("You already have the Front Door Key.\n");
			}
			
		}
		else if (game_state[0] == 3 && selector == '4')
		{
			p_time++;
			printf("The village looks tiny from this distance. Looking up, you realise you don't have much time.\n");
			printf("The time is now %d:00.\n", p_time + time);
		}
		else if (game_state[0] == 3 && selector == '5')
		{
			p_time++;
			dynamic_file_acc = fopen("house-desc.txt", "r");
			if (dynamic_file_acc == NULL)
			{
				perror("Opening House Description");
				printf("House\n");
			}
			else
			{
				while (fgets(sentence, 100, dynamic_file_acc) != NULL)
				{
					printf("%s\n", sentence);
				}
				free(dynamic_file_acc);
				dynamic_file_acc = NULL;
			}
		}
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
// Checking for Outside B
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (game_state[0] == 4 && selector == '1')
		{
			game_state[0] = 3;
		}
		else if (game_state[0] == 4 && selector == '2')
		{
			if (game_state[5] == 0)
			{
				p_time++;
				printf("You wander into the forest and get lost. Eventually you find your way back.\n");
				printf("The time is now %d:00.\n", p_time + time);
			}
			else if (game_state[5] == 1)
			{
				game_state[5] = 2;
				p_time++;
				printf("You go into the forest and, using your axe chop up some planks. Unfortunately you also break your axe in the process.\n");
				printf("The time is now %d:00.\n", p_time + time);
			}
		}
		else if (game_state[0] == 4 && selector == '3')
		{
			if (game_state[5]== 0)
			{
				game_state[5] = 1;
				p_time++;
				printf("You approach the shed and find your trusty AXE.\n");
				printf("You have gained Your Axe!\n");
			}
			else if (game_state[5] == 1)
			{
				printf("You already have your Axe.\n");
			}
			else if(game_state[5] == 2)
			{
				printf("You broke your Axe.\n");
			}

		}
		else if (game_state[0] == 4 && selector == '4')
		{
			if (game_state[5] != 2)
			{
				p_time++;
				printf("You stare at your window for a while. If only you could board it up somehow...\n");
			}
			else if (game_state[5] == 2)
			{
				p_time++;
				game_state[6] = 1;
				printf("You dilligently board up your window...\n");
				printf("The time is now %d:00.\n", p_time + time);
			}
		}
		else if (game_state[0] == 4 && selector == '5')
		{
			p_time++;
			printf("Tiredly you gaze at the sky, almost forgetting yourself in its beauty...\n");
			printf("The time is now %d:00.\n", p_time + time);
		}
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
//Selector = 6 and Selector = 7 are same for every room.
//---------------------------------------------------------------------------------------------------------------------------------------------------------	
		if (selector == '6')
		{
			help_menu();
		}
		else if (selector == '7')
		{
			quit_game();
		}
		//Clearing Selector
		clearInputBuffer();

	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------------	
	//second loop. Now being the monster you.
	//---------------------------------------------------------------------------------------------------------------------------------------------------------	
	

	int i = 0;
	if (bed_ach == 12)
	{
		player.achiements[0] = 1;
	}
	printf("The transformation has begun. in a mighty howl, you turn from an ordinary human into a mighty WEREWOLF...\n");
	sleep();
	printf("Your mind, lost in your frenzied state, wishes only to devour...\n");
	sleep();
	printf("You smell flesh. It is near. A whole Village of Flesh.\n");
	sleep();
	printf("As rage overtakes you, the innocent villagers can only hope that you DON'T ESCAPE\n");
	sleep();
		if (game_state[0] == 0)
		{
			if (game_state[1] == 1)
			{
				sleep();
				i++;
				printf("You spend some time striking at the closet. Eventually you destroy it.\n");
				monster_turn(i);
			}
			if (game_state[1] == 0)
			{
				sleep();
				printf("You Easily see the unbarricated door.\n");
				monster_turn(i);
			}
			if (game_state[2] == 2)
			{
				sleep();
				i++;
				printf("You savagely throw yourself at the door. Eventually it caves in.\n");
				monster_turn(i);
				game_state[0] = 1;
			}
			if (game_state[2] != 2)
			{
				sleep();
				printf("You easily bash the door open since it Wasn't Locked...\n");
				monster_turn(i);
				game_state[0] = 1;
			}
		}
		if (game_state[0] == 2)
		{
			sleep();
			i++;
			printf("You rush to the Living Room.\n");
			monster_turn(i);
			game_state[0] = 1;
		}
		if(game_state[0] == 1)
		{
			if (game_state[6] == 1 && has_lost == 0)
			{
				sleep();
				i++;
				printf("You do not notice the window. You have boarded it up well.\n");
				monster_turn(i);
			}
			if (game_state[6] == 0 && has_lost == 0)
			{
				sleep();
				printf("Seeing the moonlight trough the window, You dash towards it. You smash trough the brittle glass and ESCAPE.\n");
				monster_turn(i);
				game_over(i);
				has_lost = 1;
			}
			sleep();
			if (has_lost == 0)
			{
				i++;
				printf("You search the basement in a frenzy, not finding anything.\n");
				monster_turn(i);
			}		
			if (game_state[3] == 1 && has_lost == 0)
			{
				sleep();
				i++;
				printf("You spend some time Breaking open the drawer.\n");
				monster_turn(i);
			}
			if (game_state[3] == 0 && has_lost == 0)
			{
				sleep();
				printf("You have easy access to the Front Door.\n");
				monster_turn(i);
			}
			if (game_state[4] == 2 && has_lost == 0)
			{
				sleep();
				i++;
				printf("You spend some time breaking open the front door, however you are successfull in your act.\n");
				monster_turn(i);
			}
			if(game_state[4] != 2 && has_lost == 0)
			{
				sleep();
				printf("The front door opens itself from the sheer force of your stare. You are outside now.\n");
				monster_turn(i);
				game_over(i);
				has_lost = 1;
			}
			game_over(i);
			
		}
		if (game_state[0] > 2 && has_lost == 0)
		{
			printf("You are ALREADY OUTSIDE.\n");
			game_over(i);
			has_lost = 1;
		}

		//------------------------------------------------------------------------------------------------
		//SAVING PLAYER PROGRESS
		//------------------------------------------------------------------------------------------------
		char answer = 'a';
		printf("\nDo you wish to save this RUN? - Y - N\n");
		do
		{
			scanf("%c", &answer);
			clearInputBuffer();
			if (answer != 'Y' && answer != 'N')
			{
				printf("Wrong Value!\n");
			}
		} while (answer != 'Y' && answer != 'N');
		if (answer == 'N')
		{
			goto main_menu;
		}
		if (answer == 'Y')
		{
			char* f_name = NULL;
			f_name = (char*)calloc(21, sizeof(char));
			if (f_name == NULL)
			{
				perror("allocating file name");
				exit(-10);
			}
			const char* invalid_chars = "\\/:*?\"<>|";
			char exten[] = ".txt";
			int check = 0;
			do
			{
				printf("Enter file name with the extention .txt: ");
				scanf("%20s", f_name);
				check = strcmp(f_name + strlen(f_name) - strlen(exten), exten);
				for (int i = 0; i < strlen(f_name); i++)
				{
					if (strchr(invalid_chars,f_name[i]))
					{
						check = 1;
					}
				}
				if (check != 0)
				{
					printf("Stick to proper file-naming Etiquette.\nNo special characters.\nYou must include '.txt' at the end.\n");
				}
			} while (check != 0);
			character_creation(f_name, player);
			free(f_name);
		}

		printf("\nExiting...");
}



void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	//call repeatedly until buffer is clear
}