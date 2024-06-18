#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void clear_Input_Buffer();
void player_select() {
	FILE* fp = NULL;
	PLAYER player;
	char s;
	int a = 0;
	do
	{
		printf("What do you wish to do?\n1. Browse Saves\n2. Open Save\n3. Alter Save\n4. Delete Save\n5. Back\n");
		do
		{
			scanf("%c", &s);
		} while (s != '1' && s != '2' && s != '3' && s != '4' && s != '5');
		clear_Input_Buffer();
//BROWSING SAVES
//===================================================================================
		if (s == '1')
		{
			//1000 is max save count
			char saves[1000][21];
			int count = 0;
			FILE* players = NULL;
			players = fopen("players.txt", "r");
			if (players == NULL)
			{
				perror("grabbing all saves");
			}
			else
			{
				int i = 0;
				while (fgets(saves[count],1000,players))
				{
					//finding new line
					saves[count][strcspn(saves[count], "\n")] = '\0';
					count++;
					if (count >= 1000)
					{
						printf("Maximum save capacity reached (1000)\n");
						break;
					}
				}
			}
			//===================================================================================
			qsort(saves, count, 21, strcmp);
			//===================================================================================
			for (int i = 0; i < count; i++)
			{
				printf("%s\n", saves[i]);
			}
			fclose(players);
		}
//OPENING SAVE
//===================================================================================
		else if (s == '2')
		{
			char sav[201];
			printf("Type in Save Name: ");
			char* f_name = NULL;
			f_name = (char*)calloc(21, sizeof(char));
			if (f_name == NULL)
			{
				perror("allocating file name");
				exit(-10);
			}
			char exten[] = ".txt";
			int check = 0;
			do
			{
				printf("Enter file name with the extention .txt: ");
				scanf("%20s", f_name);
				check = strcmp(f_name + strlen(f_name) - strlen(exten), exten);
				if (check != 0)
				{
					printf("Don't forget the .txt at the end...\n");
				}
			} while (check != 0);
			fp = fopen(f_name, "r");
			if (fp == NULL)
			{
				perror("Opening Save File");
				return;
			}
			while (fscanf(fp, "%s", &sav) != EOF)
			{
				printf("%s\n", sav);
			}
			fclose(fp);
		}
//ALTERING SAVE
//===================================================================================
		else if (s == '3')
		{
			char sav[51];
			printf("Type in Save Name: ");
			char* f_name = NULL;
			f_name = (char*)calloc(21, sizeof(char));
			if (f_name == NULL)
			{
				perror("allocating file name");
				exit(-10);
			}
			char exten[] = ".txt";
			int check = 0;
			do
			{
				printf("Enter file name with the extention .txt: ");
				scanf("%20s", f_name);
				check = strcmp(f_name + strlen(f_name) - strlen(exten), exten);
				if (check != 0)
				{
					printf("Don't forget the .txt at the end...\n");
				}
			} while (check != 0);
			fp = fopen(f_name, "r");
			if (fp == NULL)
			{
				perror("Opening Save File");
				return;
			}
			fseek(fp, 0, SEEK_SET);
			fscanf(fp, "%s", player.name);
			fscanf(fp, "%s", player.desc);
			fclose(fp);
			fp = fopen(f_name, "w");
			printf("Enter name: ");
			scanf("%s", &player.name);
			printf("Enter description: ");
			scanf("%s", &player.desc);
			fprintf(fp, "%s\n%s\n%d\n%d\n%d\n", player.name, player.desc, player.achiements[0], player.achiements[1], player.achiements[2]);
			fclose(fp);

		}
//DELETING SAVE
//===================================================================================
		else if (s == '4')
		{
//grabbing save
			//1000 is max save count
			char saves[1000][21];
			int count = 0;
			FILE* players = NULL;
			players = fopen("players.txt", "r");
			if (players == NULL)
			{
				perror("grabbing all saves");
			}
			else
			{
				int i = 0;
				while (fgets(saves[count], 1000, players))
				{
					//finding new line
					saves[count][strcspn(saves[count], "\n")] = '\0';
					count++;
					if (count >= 1000)
					{
						printf("Maximum save capacity reached (1000)\n");
						break;
					}
				}
			}
			fclose(players);
//deleting the save
			printf("Type in Save Name: ");
			char* f_name = NULL;
			f_name = (char*)calloc(21, sizeof(char));
			if (f_name == NULL)
			{
				perror("allocating file name");
				exit(-10);
			}
			char exten[] = ".txt";
			char checking[] = "players.txt";
			int check = 1;
			do
			{
				printf("Enter file name with the extention .txt: ");
				scanf("%20s", f_name);
				check = strcmp(f_name + strlen(f_name) - strlen(exten), exten);
				if (check != 0)
				{
					printf("Wrong!\n");
				}
			} while (check != 0);

			players = fopen("players.txt", "w");
			if (players == NULL)
			{
				perror("grabbing all saves");
				exit(-10);
			}
			for (int i = 0; i < count; i++) {
				if (strcmp(saves[i], f_name) != 0) {
					fprintf(players, "%s\n", saves[i]);
				}
			}
			fclose(players);
		}
//BACK TO MAIN MENU
//===================================================================================
		else if (s == '5')
		{
			printf("Returning to Main Menu...\n");
			return;
		}
	} while (a == 0);
}

void clear_Input_Buffer() {
	int s;
	while ((s = getchar()) != '\n' && s != EOF);
}