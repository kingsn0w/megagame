#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>


// C:\Users\thiag\Documents\Matéria\algoritmos 2\trampos
typedef struct {

	char comando[50];
} COMANDO;

typedef struct {

	char linha[300];
} LINHA;

typedef struct {
// tipo : 1 monstro, 2 magica, 3 armadilha;
	int tipo;

	int atk;

	int def;
// modo : 1 atk, 2: defesa;
	int modo;

	char nome[50];


	char desc[500];


	LINHA linhas[20];

	LINHA nome_menu[1];
} CARTA;

typedef struct {

	int deck[40];

	char nome[50];

	LINHA linhas[17];
} INIMIGO;

typedef struct {

	LINHA linhas[20];
} TELA;

typedef struct {
	LINHA linhas[40];
} HUD;

typedef struct {
	LINHA linhas[10];
} MENU;

TELA telas[20];

HUD hud[1];

MENU menus[10];

CARTA cartas[10];

INIMIGO inimigos[10];

COMANDO comandos[5];

int i, j, cmds_count, entrada;

int mesa_aliada[4];

int mesa_inimiga[4];

int mao_jogador[4];

int deck_jogador[40];

int count;

int comand;

int Comando(char cmd[50]) {

	int limit = 0;

	int found = 0;

	int i = 0;

	for (i = 0; i <= 50; i++) {



		if (cmd[i] == 0 && found == 0) {

			limit = i;
			found = 1;

		}


	}

	char new_cmd[limit];



	for (i = 0; i <= limit; i++) {

		new_cmd[i] = cmd[i];




	}


	int comando = atoi(new_cmd);

	return comando;
}

void DesenharMesa() {

	int count_hud;
	count_hud = 0;
	for (j = 0; j <= 17; j++) {
		for (i = 0; i <= 4; i++) {
			if (mesa_inimiga[i] != -1) {
				printf("%s", cartas[mesa_inimiga[i]].linhas[j].linha);
				printf(" ");
			}
			else {
				printf("%s", cartas[1].linhas[j].linha);
				printf(" ");
			}
		}
		printf("%s", hud[1].linhas[count_hud].linha);
		count_hud++;
		printf("\n");
	}
	printf("\n");
	for (j = 0; j <= 17; j++) {
		for (i = 0; i <= 4; i++) {
			if (mesa_aliada[i] != -1) {
				printf("%s", cartas[mesa_aliada[i]].linhas[j].linha);
				printf(" ");
			}
			else {
				printf("%s", cartas[1].linhas[j].linha);
				printf(" ");
			}
		}
		printf("%s", hud[1].linhas[count_hud].linha);
		count_hud++;
		printf("\n");
	}
	for (i = 0; i <= 3; i++) {

		printf("%s\n", hud[2].linhas[i].linha);
	}
	for (j = 0; j <= 17; j++) {
		for (i = 0; i <= 4; i++) {
			if (mao_jogador[i] != -1) {
				printf("%s", cartas[mao_jogador[i]].linhas[j].linha);
				printf(" ");
			}
			else {
				printf("%s", cartas[1].linhas[j].linha);
				printf(" ");
			}
		}

		printf("\n");
	}
	count_hud = 0 ;
}

void CriarHUD() {
	strcpy(hud[0].linhas[0].linha, "     +-------+");
	strcpy(hud[0].linhas[1].linha, "     | CAMPO |");
	strcpy(hud[0].linhas[2].linha, "+----+-------+-----+");
	strcpy(hud[0].linhas[3].linha, "|      NORMAL      |");
	strcpy(hud[0].linhas[4].linha, "+------------------+");
	strcpy(hud[0].linhas[5].linha, "     +-------+");
	strcpy(hud[0].linhas[6].linha, "     |  LOG  |");
	strcpy(hud[0].linhas[7].linha, "+----+-------+-----+");
	strcpy(hud[0].linhas[8].linha, "|                  |");
	strcpy(hud[0].linhas[9].linha, "|                  |");
	strcpy(hud[0].linhas[10].linha, "|                  |");
	strcpy(hud[0].linhas[11].linha, "|                  |");
	strcpy(hud[0].linhas[12].linha, "|                  |");
	strcpy(hud[0].linhas[13].linha, "|                  |");
	strcpy(hud[0].linhas[14].linha, "|                  |");
	strcpy(hud[0].linhas[15].linha, "|                  |");
	strcpy(hud[0].linhas[16].linha, "|                  |");
	strcpy(hud[0].linhas[17].linha, "|                  |");
	strcpy(hud[0].linhas[18].linha, "|                  |");
	strcpy(hud[0].linhas[19].linha, "|                  |");
	strcpy(hud[0].linhas[20].linha, "|                  |");
	strcpy(hud[0].linhas[21].linha, "|                  |");
	strcpy(hud[0].linhas[22].linha, "+------------------+");
	strcpy(hud[0].linhas[23].linha, "    +----------+");
	strcpy(hud[0].linhas[24].linha, "    |   MENU   |");
	strcpy(hud[0].linhas[25].linha, "+---+----------+---+");
	strcpy(hud[0].linhas[26].linha, "|                  |");
	strcpy(hud[0].linhas[27].linha, "|1 - Sumonar Carta |");
	strcpy(hud[0].linhas[28].linha, "|                  |");
	strcpy(hud[0].linhas[29].linha, "|2 - Trocar Modo   |");
	strcpy(hud[0].linhas[30].linha, "|                  |");
	strcpy(hud[0].linhas[31].linha, "|3 - Surrender     |");
	strcpy(hud[0].linhas[32].linha, "|                  |");
	strcpy(hud[0].linhas[33].linha, "|                  |");
	strcpy(hud[0].linhas[34].linha, "+------------------+");

	strcpy(hud[1].linhas[0].linha, "       +-------+");
	strcpy(hud[1].linhas[1].linha, "       | CAMPO |");
	strcpy(hud[1].linhas[2].linha, "+------+-------+-------+");
	strcpy(hud[1].linhas[3].linha, "|       NORMAL         |");
	strcpy(hud[1].linhas[4].linha, "+----------------------+");
	strcpy(hud[1].linhas[5].linha, "       +-------+");
	strcpy(hud[1].linhas[6].linha, "       |  LOG  |");
	strcpy(hud[1].linhas[7].linha, "+------+-------+-------+");
	strcpy(hud[1].linhas[8].linha, "|                      |");
	strcpy(hud[1].linhas[9].linha, "|                      |");
	strcpy(hud[1].linhas[10].linha, "|                      |");
	strcpy(hud[1].linhas[11].linha, "|                      |");
	strcpy(hud[1].linhas[12].linha, "|                      |");
	strcpy(hud[1].linhas[13].linha, "|                      |");
	strcpy(hud[1].linhas[14].linha, "|                      |");
	strcpy(hud[1].linhas[15].linha, "|                      |");
	strcpy(hud[1].linhas[16].linha, "|                      |");
	strcpy(hud[1].linhas[17].linha, "|                      |");
	strcpy(hud[1].linhas[18].linha, "|                      |");
	strcpy(hud[1].linhas[19].linha, "|                      |");
	strcpy(hud[1].linhas[20].linha, "|                      |");
	strcpy(hud[1].linhas[21].linha, "|                      |");
	strcpy(hud[1].linhas[22].linha, "+----------------------+");
	strcpy(hud[1].linhas[23].linha, "      +----------+");
	strcpy(hud[1].linhas[24].linha, "      |   MENU   |");
	strcpy(hud[1].linhas[25].linha, "+-----+----------+-----+");
	strcpy(hud[1].linhas[26].linha, "|                      |");
	strcpy(hud[1].linhas[27].linha, "|1 - Sumonar Carta     |");
	strcpy(hud[1].linhas[28].linha, "|                      |");
	strcpy(hud[1].linhas[29].linha, "|2 - Trocar Modo       |");
	strcpy(hud[1].linhas[30].linha, "|                      |");
	strcpy(hud[1].linhas[31].linha, "|3 - Surrender         |");
	strcpy(hud[1].linhas[32].linha, "|                      |");
	strcpy(hud[1].linhas[33].linha, "|                      |");
	strcpy(hud[1].linhas[34].linha, "|                      |");
	strcpy(hud[1].linhas[35].linha, "+----------------------+");

	strcpy(hud[2].linhas[0].linha, "                                                    +---------+                                                   ");
	strcpy(hud[2].linhas[1].linha, "+---------------------------------------------------+ SUA MÃO +--------------------------------------------------+");
	strcpy(hud[2].linhas[2].linha, "                                                    +---------+                                                   ");
}

void limpar_menu() {

	for (i = 26; i <= 34; i++) {

		strcpy(hud[1].linhas[i].linha, "|                      |");


	}
}

void DesenharMenu(int escolha) {

	switch (escolha) {


	case 0:
		strcpy(hud[1].linhas[26].linha, "|                      |");
		strcpy(hud[1].linhas[27].linha, "|1 - Sumonar Carta     |");
		strcpy(hud[1].linhas[28].linha, "|                      |");
		strcpy(hud[1].linhas[29].linha, "|2 - Trocar Modo       |");
		strcpy(hud[1].linhas[30].linha, "|                      |");
		strcpy(hud[1].linhas[31].linha, "|3 - Surrender         |");
		strcpy(hud[1].linhas[32].linha, "|                      |");
		strcpy(hud[1].linhas[33].linha, "|                      |");
		strcpy(hud[1].linhas[34].linha, "|                      |");
		break;


	}
}

void DesenharTela(int tel) {

	system("cls");

	for (i = 0; i <= 17; i++) {

		printf("%s\n", telas[tel].linhas[i].linha);
	}
}


void CriarCartas() {
// Criando cartas
	strcpy(cartas[1].linhas[0].linha, "+-------------------+");
	strcpy(cartas[1].linhas[1].linha, "|                   |");
	strcpy(cartas[1].linhas[2].linha, "|                   |");
	strcpy(cartas[1].linhas[3].linha, "|  XX          XX   |");
	strcpy(cartas[1].linhas[4].linha, "|   XX        XX    |");
	strcpy(cartas[1].linhas[5].linha, "|     X      XX     |");
	strcpy(cartas[1].linhas[6].linha, "|      XX   XX      |");
	strcpy(cartas[1].linhas[7].linha, "|       XX XX       |");
	strcpy(cartas[1].linhas[8].linha, "|        XXX        |");
	strcpy(cartas[1].linhas[9].linha, "|        X XX       |");
	strcpy(cartas[1].linhas[10].linha, "|       X    XX     |");
	strcpy(cartas[1].linhas[11].linha, "|     XX      XX    |");
	strcpy(cartas[1].linhas[12].linha, "|    XX        XX   |");
	strcpy(cartas[1].linhas[13].linha, "|  XX           XX  |");
	strcpy(cartas[1].linhas[14].linha, "|                   |");
	strcpy(cartas[1].linhas[15].linha, "|                   |");
	strcpy(cartas[1].linhas[16].linha, "|                   |");
	strcpy(cartas[1].linhas[17].linha, "+-------------------+");


	cartas[0].tipo = 1;
	cartas[0].atk = 3000;
	cartas[0].def = 1500;
	strcpy(cartas[0].nome, "Satella");
	strcpy(cartas[0].desc, "A grande bruxa");
	strcpy(cartas[0].linhas[0].linha, "+-------------------+");
	strcpy(cartas[0].linhas[1].linha, "|      SATELLA      |");
	strcpy(cartas[0].linhas[2].linha, "+-------------------+");
	strcpy(cartas[0].linhas[3].linha, "|                   |");
	strcpy(cartas[0].linhas[4].linha, "|       *    XXXXX  |");
	strcpy(cartas[0].linhas[5].linha, "|     *****  X   X  |");
	strcpy(cartas[0].linhas[6].linha, "|    ******* X   X  |");
	strcpy(cartas[0].linhas[7].linha, "|    *     *   XXX  |");
	strcpy(cartas[0].linhas[8].linha, "|    **   **   X    |");
	strcpy(cartas[0].linhas[9].linha, "|  ***** ****  X    |");
	strcpy(cartas[0].linhas[10].linha, "| ************ X    |");
	strcpy(cartas[0].linhas[11].linha, "|**************X    |");
	strcpy(cartas[0].linhas[12].linha, "|**************X    |");
	strcpy(cartas[0].linhas[13].linha, "|**************X    |");
	strcpy(cartas[0].linhas[14].linha, "|**************X    |");
	strcpy(cartas[0].linhas[15].linha, "+-------------------+");
	strcpy(cartas[0].linhas[16].linha, "|ATK:3000 |DEF:1500 |");
	strcpy(cartas[0].linhas[17].linha, "+-------------------+");

	strcpy(cartas[0].nome_menu[0].linha, "|# - Satella           |");


	cartas[2].tipo = 1;
	cartas[2].atk = 3200;
	cartas[2].def = 1300;
	strcpy(cartas[2].nome, "MINDSTEALER");
	strcpy(cartas[2].linhas[0].linha, "+-------------------+");
	strcpy(cartas[2].linhas[1].linha, "|    MINDSTEALER    |");
	strcpy(cartas[2].linhas[2].linha, "+-------------------+");
	strcpy(cartas[2].linhas[3].linha, "|    (XXXXXXXXX)    |");
	strcpy(cartas[2].linhas[4].linha, "|   (XXXXXXXXXXX)   |");
	strcpy(cartas[2].linhas[5].linha, "|  (XX(0)XXX(0)XX)  |");
	strcpy(cartas[2].linhas[6].linha, "|  (^^XXXXXXXXX^^)  |");
	strcpy(cartas[2].linhas[7].linha, "|   ((XXX^X^XXX))   |");
	strcpy(cartas[2].linhas[8].linha, "|    (^XX^ ^XX^)    |");
	strcpy(cartas[2].linhas[9].linha, "|      (X___X)      |");
	strcpy(cartas[2].linhas[10].linha, "|      (X(|)X)      |");
	strcpy(cartas[2].linhas[11].linha, "|    (( ((|)) ))    |");
	strcpy(cartas[2].linhas[12].linha, "| ((((((((|)))))))) |");
	strcpy(cartas[2].linhas[13].linha, "|((((( (((|))) )))))|");
	strcpy(cartas[2].linhas[14].linha, "|((((  (((|)))  ))))|");
	strcpy(cartas[2].linhas[15].linha, "+---------+---------+");
	strcpy(cartas[2].linhas[16].linha, "|ATK:3200 |DEF:1300 |");
	strcpy(cartas[2].linhas[17].linha, "+---------+---------+");

	strcpy(cartas[2].nome_menu[0].linha, "|# - MindStealer       |");

	cartas[3].tipo = 1;
	cartas[3].atk = 4100;
	cartas[3].def = 1900;
	strcpy(cartas[3].nome, "HAEGON");
	strcpy(cartas[3].linhas[0].linha, "+-------------------+");
	strcpy(cartas[3].linhas[1].linha, "|      HAEGON       |");
	strcpy(cartas[3].linhas[2].linha, "+-------------------+");
	strcpy(cartas[3].linhas[3].linha, "|  @@@@@       /\\   |");
	strcpy(cartas[3].linhas[4].linha, "| @@@@@@@      ||   |");
	strcpy(cartas[3].linhas[5].linha, "|@@@@@ V|      ||   |");
	strcpy(cartas[3].linhas[6].linha, "|@@@@@   \\    ||    |");
	strcpy(cartas[3].linhas[7].linha, "|@@@@@  _|     ||   |");
	strcpy(cartas[3].linhas[8].linha, "|@@@@/__/      ||   |");
	strcpy(cartas[3].linhas[9].linha, "|@@@XXXXXX     ||   |");
	strcpy(cartas[3].linhas[10].linha, "|@XXXXXXXXX  ====== |");
	strcpy(cartas[3].linhas[11].linha, "|XXXXXXXXXXX  XXXX  |");
	strcpy(cartas[3].linhas[12].linha, "|XXXXXXXXXXXXXXXX   |");
	strcpy(cartas[3].linhas[13].linha, "|XXXXXXXX XXXXX^^   |");
	strcpy(cartas[3].linhas[14].linha, "|XXXXXXXX XXXXX^^   |");
	strcpy(cartas[3].linhas[15].linha, "+---------+---------+");
	strcpy(cartas[3].linhas[16].linha, "|ATK:4100 | DEF:1900|");
	strcpy(cartas[3].linhas[17].linha, "+---------+---------+");

	strcpy(cartas[3].nome_menu[0].linha, "|# - Haegon            |");

	cartas[4].tipo = 1;
	cartas[4].atk = 3200;
	cartas[4].def = 1300;
	strcpy(cartas[4].nome, "KYRA");
	strcpy(cartas[4].linhas[0].linha, "+-------------------+");
	strcpy(cartas[4].linhas[1].linha, "|        KYRA       |");
	strcpy(cartas[4].linhas[2].linha, "+-------------------+");
	strcpy(cartas[4].linhas[3].linha, "|                   |");
	strcpy(cartas[4].linhas[4].linha, "|   (     @@@@@   ^ |");
	strcpy(cartas[4].linhas[5].linha, "|  ((    @@--@@@  | |");
	strcpy(cartas[4].linhas[6].linha, "| ((    @@@ 0@@@@ | |");
	strcpy(cartas[4].linhas[7].linha, "|((XX   @@XXX@@@@XX |");
	strcpy(cartas[4].linhas[8].linha, "|(((XXXXXXXXXXXXXX| |");
	strcpy(cartas[4].linhas[9].linha, "| ((    XXXXXX@@  | |");
	strcpy(cartas[4].linhas[10].linha, "|  ((    XXXX@@     |");
	strcpy(cartas[4].linhas[11].linha, "|   (   XXXXXXX     |");
	strcpy(cartas[4].linhas[12].linha, "|      XXX  XXX     |");
	strcpy(cartas[4].linhas[13].linha, "|    XXXX    XXXX   |");
	strcpy(cartas[4].linhas[14].linha, "|    XXXX    XXXX   |");
	strcpy(cartas[4].linhas[15].linha, "+---------+---------+");
	strcpy(cartas[4].linhas[16].linha, "|ATK:3200 | DEF:1300|");
	strcpy(cartas[4].linhas[17].linha, "+---------+---------+");

	strcpy(cartas[4].nome_menu[0].linha, "|# - Kyra              |");

	strcpy(cartas[5].linhas[0].linha, "+-------------------+");
	strcpy(cartas[5].linhas[1].linha, "|      GOLYAN       |");
	strcpy(cartas[5].linhas[2].linha, "+-------------------+");
	strcpy(cartas[5].linhas[3].linha, "|           @@@@    |");
	strcpy(cartas[5].linhas[4].linha, "|         @@@@@@@@  |");
	strcpy(cartas[5].linhas[5].linha, "|        @@(- -)@@  |");
	strcpy(cartas[5].linhas[6].linha, "|       @@@@@_@@@@  |");
	strcpy(cartas[5].linhas[7].linha, "|  HH   @@@@@@@@@@  |");
	strcpy(cartas[5].linhas[8].linha, "| HHHH  XX@@@@@XX   |");
	strcpy(cartas[5].linhas[9].linha, "| HHHH XXXX@@@@@XX  |");
	strcpy(cartas[5].linhas[10].linha, "| HHHHXXHHHHHHHHHHXH|");
	strcpy(cartas[5].linhas[11].linha, "| HHHH   XX@@@@@XX  |");
	strcpy(cartas[5].linhas[12].linha, "| HHHH   XXX@@@@XX  |");
	strcpy(cartas[5].linhas[13].linha, "|  HH  XXXXX @@XXXX |");
	strcpy(cartas[5].linhas[14].linha, "|  HH  XXXXX @@XXXX |");
	strcpy(cartas[5].linhas[15].linha, "+---------+---------+");
	strcpy(cartas[5].linhas[16].linha, "|ATK:3900 | DEF:1000|");
	strcpy(cartas[5].linhas[17].linha, "+---------+---------+");

	strcpy(cartas[5].nome_menu[0].linha, "|# - Golyan            |");
}

void CriarTelas() {


	strcpy(telas[0].linhas[0].linha, "+--------------------------------------------------------------------------------------------------------+");
	strcpy(telas[0].linhas[1].linha, "|                                                                                                        |");
	strcpy(telas[0].linhas[2].linha, "|                                                                                                        |");
	strcpy(telas[0].linhas[3].linha, "|                                                                                                        |");
	strcpy(telas[0].linhas[4].linha, "|                 _______  _______  _______  _______    _______  _______  _______  _______               |");
	strcpy(telas[0].linhas[5].linha, "|                (       )(  ____ \\(  ____ \\(  ___  )  (  ____ \\(  ___  )(       )(  ____ \\              |");
	strcpy(telas[0].linhas[6].linha, "|                + () () ++ (    \\/+ (    \\/+ (   ) +  + (    \\/+ (   ) ++ () () ++ (    \\/              |");
	strcpy(telas[0].linhas[7].linha, "|                | ++ ++ || (__    | +      | (___) |  | +      | (___) || ++ ++ || (__                  |");
	strcpy(telas[0].linhas[8].linha, "|                | |(_)| ||  __)   | | ____ |  ___  |  | | ____ |  ___  || |(_)| ||  __)                 |");
	strcpy(telas[0].linhas[9].linha, "|                | +   + || (      | + \\_  )| (   ) |  | + \\_  )| (   ) || +   + || (                    |");
	strcpy(telas[0].linhas[10].linha, "|                | )   ( ++ (____/\\+ (___) ++ )   ( |  + (___) ++ )   ( || )   ( ++ (____/\\              |");
	strcpy(telas[0].linhas[11].linha, "|                +/     \\+(_______/(_______)+/     \\+  (_______)+/     \\++/     \\+(_______/              |");
	strcpy(telas[0].linhas[12].linha, "|                                                                                                        |");
	strcpy(telas[0].linhas[13].linha, "|                                      +--------------------+                                            |");
	strcpy(telas[0].linhas[14].linha, "|                                      |   DIGITE INICIAR   |                                            |");
	strcpy(telas[0].linhas[15].linha, "|                                      +--------------------+                                            |");
	strcpy(telas[0].linhas[16].linha, "|                                                                                                        |");
	strcpy(telas[0].linhas[17].linha, "+--------------------------------------------------------------------------------------------------------+");

	strcpy(telas[1].linhas[0].linha, "+--------------------------------------------------------------------------------------------------------+");
	strcpy(telas[1].linhas[1].linha, "|                                                                                                        |");
	strcpy(telas[1].linhas[2].linha, "|                                          +-----------+                                                 |");
	strcpy(telas[1].linhas[3].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[4].linha, "|                                          |   DUELO   |                                                 |");
	strcpy(telas[1].linhas[5].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[6].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[7].linha, "|                                          |   DECK    |                                                 |");
	strcpy(telas[1].linhas[8].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[9].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[10].linha, "|                                          |   OPÇÕES  |                                                 |");
	strcpy(telas[1].linhas[11].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[12].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[13].linha, "|                                          |   AJUDA   |                                                 |");
	strcpy(telas[1].linhas[14].linha, "|                                          |           |                                                 |");
	strcpy(telas[1].linhas[15].linha, "|                                          +-----------+                                                 |");
	strcpy(telas[1].linhas[16].linha, "|                                                                                                        |");
	strcpy(telas[1].linhas[17].linha, "+--------------------------------------------------------------------------------------------------------+");

	strcpy(telas[2].linhas[0].linha, "+--------------------------------------------------------------------------------------------------------+");
	strcpy(telas[2].linhas[1].linha, "|                                                                                                        |");
	strcpy(telas[2].linhas[2].linha, "|     +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+    |");
	strcpy(telas[2].linhas[3].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[4].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[5].linha, "|     |  JOHN   | |  DRAKE  | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[6].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[7].linha, "|     +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+    |");
	strcpy(telas[2].linhas[8].linha, "|                                                                                                        |");
	strcpy(telas[2].linhas[9].linha, "|     +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+    |");
	strcpy(telas[2].linhas[10].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[11].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[12].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[13].linha, "|     |         | |         | |         | |         | |         | |         | |         | |         |    |");
	strcpy(telas[2].linhas[14].linha, "|     +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+ +---------+    |");
	strcpy(telas[2].linhas[15].linha, "|                                                                                                        |");
	strcpy(telas[2].linhas[16].linha, "|                                                                                                        |");
	strcpy(telas[2].linhas[17].linha, "+--------------------------------------------------------------------------------------------------------+");
}

void CriarInimigos() {

	strcpy(inimigos[0].nome, "John");
	strcpy(inimigos[0].linhas[0].linha, "+------------------------+");
	strcpy(inimigos[0].linhas[1].linha, "|                        |");
	strcpy(inimigos[0].linhas[2].linha, "|      XXXXXXXXXXXXXX    |");
	strcpy(inimigos[0].linhas[3].linha, "|   XXX XXXXXXXXXX  XX   |");
	strcpy(inimigos[0].linhas[4].linha, "|  X  XXXXX   XX XX  X   |");
	strcpy(inimigos[0].linhas[5].linha, "|  X  X    X X    X   X  |");
	strcpy(inimigos[0].linhas[6].linha, "|  XXXX  XX   XX  XXXXX  |");
	strcpy(inimigos[0].linhas[7].linha, "|     X  XX   XX  XX     |");
	strcpy(inimigos[0].linhas[8].linha, "|     X           X      |");
	strcpy(inimigos[0].linhas[9].linha, "|     XX  XXXXX   X      |");
	strcpy(inimigos[0].linhas[10].linha, "|   XXXXXXXXXXXXXXXXXX   |");
	strcpy(inimigos[0].linhas[11].linha, "|  XX                XX  |");
	strcpy(inimigos[0].linhas[12].linha, "|  X                  X  |");
	strcpy(inimigos[0].linhas[13].linha, "|  XX                 X  |");
	strcpy(inimigos[0].linhas[14].linha, "+------------------------+");
	strcpy(inimigos[0].linhas[15].linha, "| JOHN    |RANK:*****    |");
	strcpy(inimigos[0].linhas[16].linha, "+------------------------+");
}


int main() {


	setlocale(LC_ALL, "PORTUGUESE");

	char comando[250];

	cmds_count = 0;

	int tela_anterior = -1;

	int tela_num, tela_criar, atgame;

	atgame = 0;

	tela_num = 0;

	tela_criar = 0;

	entrada = 1;

	CriarCartas();

	CriarTelas();

	CriarHUD();

	

	while (entrada) {



		if (!tela_criar || tela_anterior != tela_num) {



			system("cls");

			DesenharTela(tela_num);

			tela_anterior = tela_num;

			tela_criar = 1;

		}

		char cmd[50];

		scanf( "%s", &cmd);

		comand = Comando(cmd);



		switch (tela_num) {

		case 0:

			switch (comand) {


			case 1:
				tela_num = 1;
				break;

			case 2:
				entrada = 0;
				break;


			default:
				printf("Comando inválido.\n");
				break;



			}

			break;

		case 1:

			switch (comand) {

			case 1:
				tela_num = 2;
				break;

			case 2:
				entrada = 0;
				break;


			default:
				printf("Comando inválido\n");
				break;



			}

			break;

		case 2:


			switch (comand) {

			case 1:

				mesa_aliada[4] = -1;
				mesa_aliada[0] = -1;
				mesa_aliada[1] = -1;
				mesa_aliada[2] = -1;
				mesa_aliada[3] = -1;


				mesa_inimiga[0] = 2;
				mesa_inimiga[1] = -1;
				mesa_inimiga[2] = -1;
				mesa_inimiga[3] = -1;
				mesa_inimiga[4] = -1;


				atgame = 1;
				entrada = 0;

				break;

			case 2:
				entrada = 0;
				break;


			default:
				printf("Comando inválido\n");
				break;



			}



			break;

		}

		cmds_count = 0;




	}

	while (atgame) {
		int game_ini;
		int menu;
		menu = 0;
		game_ini = 0;

		if (!game_ini) {
			mesa_aliada[4] = -1;
			mesa_aliada[0] = -1;
			mesa_aliada[1] = -1;
			mesa_aliada[2] = -1;
			mesa_aliada[3] = -1;


			mesa_inimiga[0] = 2;
			mesa_inimiga[1] = 3;
			mesa_inimiga[2] = -1;
			mesa_inimiga[3] = -1;
			mesa_inimiga[4] = -1;

			mao_jogador[0] = 0;
			mao_jogador[1] = 5;
			mao_jogador[2] = 2;
			mao_jogador[3] = 3;
			mao_jogador[4] = 4;



		}



		system("cls");
		DesenharMesa();


		scanf("%s", &comando);
		comand = Comando(comando);
		LINHA temp_nome[5];
		switch (menu) {

		case 0:
			switch (comand) {


			case 1:
				// Sumonar
				limpar_menu();


				for (i = 0; i <= 4; i++) {

					strcpy(temp_nome[i].linha, cartas[mao_jogador[i]].nome_menu[0].linha);

					temp_nome[i].linha[1] = 49 + i ;


					strcpy(hud[1].linhas[26 + i].linha, temp_nome[i].linha);



				}
				strcpy(hud[1].linhas[31].linha, "|                      |");
				strcpy(hud[1].linhas[32].linha, "|6 - Voltar            |");

				menu = 1;

				// trocar menu
				break;
			case 2:
				atgame = 0;
				entrada = 1;
				break;


			default:
				printf("Comando inválido\n");
				break;



			}

			break;

		case 1:
			switch (comand) {

			case 6:
				DesenharMenu(0);
				menu = 0;
				break;


			}


			break;


		}



	}



	return 0;
}

