#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void character_creation(char file[21], PLAYER player)
{
	int is_copy = 0;
	char save[21];
	FILE* pl = NULL;
	FILE* pf = NULL;
	pf = fopen(file, "w");
	if (pf == NULL)
	{
		perror("creating player");
		exit(-10);
	}
	pl = fopen("players.txt", "r");
	if (pl == NULL)
	{
		perror("saving player into players.txt");
		exit(-11);
	}
	printf("Enter name: ");
	scanf("%s", &player.name);
	printf("Enter description: ");
	scanf("%s", &player.desc);
	fprintf(pf, "%s\n%s\n%d\n%d\n%d\n", player.name, player.desc, player.achiements[0], player.achiements[1], player.achiements[2]);
	int check = 0;
	while (fscanf(pl,"%s", &save) != EOF)
	{
		check = strcmp(file, save);
	}
	printf("%d\n", check);
	if (check == 0)
	{
		printf("A File with that name Already Exists!\n");
		return;
	}
	else
	{
		fclose(pl);
		pl = fopen("players.txt", "a+");
		if (pl == NULL)
		{
			perror("saving player into players.txt");
			exit(-11);
		}
		fseek(pl, 0, SEEK_END);
		fprintf(pl, "%s\n", file);
	}
	fclose(pf);
	fclose(pl);
	printf("Player size = %d\n", sizeof(player));
}