#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void character_creation(char file[21], PLAYER player)
{
	FILE* pl = NULL;
	FILE* pf = NULL;
	pf = fopen(file, "w");
	if (pf == NULL)
	{
		perror("creating player");
		exit(-10);
	}
	pl = fopen("players.txt", "a+");
	if (pl == NULL)
	{
		perror("saving player into players.txt");
		exit(-11);
	}
	printf("Enter name: ");
	scanf("%s", &player.name);
	printf("Enter description: ");
	scanf("%s", &player.desc);
	fprintf(pf, "%s\n%s\n%d", player.name, player.desc, player.achiements);
	fprintf(pl, "%s\n", file);
	fclose(pf);
}