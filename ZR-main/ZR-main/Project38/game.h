#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct player {
	char name[21];
	char desc[51];
	int achiements[3];

}PLAYER;

void quit_game();
void help_menu();
void move_prompt();
void game_over(int);
void monster_turn(int);
void journal();
void character_creation(char a[21], PLAYER);
void player_select();
void sleep();