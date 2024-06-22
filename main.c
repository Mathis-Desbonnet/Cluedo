#include <stdio.h>
#include <windows.h>
#include "game.h"

int main(void) {
    srand(time(NULL));
    int choice;
    int maxFirstDiceRoll;
    int temp;
    int indexOfNextPlayer;
    Player firstPlayerw;
    Game newGame;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    int map[25][24] = {
            {
                    2, 2,  2, 2,  2, 2,  1,  0,  0, 0,  0, 2,  2,  0, 0,  0,  1,  0,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 2,  1,  1,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 2,  1,  1,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 11, 1,  1,  1, 2,  2, 2,  2,  2, 2,  1,  1,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    0, 1,  1, 1,  1, 21, 1,  1,  1, 2,  2, 2,  2,  2, 2,  1,  1,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    1, 1,  1, 1,  1, 1,  1,  1,  1, 2,  2, 2,  2,  2, 2,  1,  1,  14, 2, 2,  2, 2, 2, 2
            },
            {
                    0, 2,  2, 2,  2, 2,  1,  1,  1, 2,  2, 3,  3,  2, 2,  1,  1,  4,  1, 1,  1, 1, 1, 0
            },
            {
                    2, 2,  2, 2,  2, 2,  2,  1,  1, 1,  1, 13, 13, 1, 1,  1,  1,  1,  1, 1,  1, 1, 1, 1
            },
            {
                    2, 2,  2, 2,  2, 2,  10, 20, 1, 2,  2, 2,  2,  2, 1,  1,  1,  15, 1, 1,  1, 1, 1, 0
            },
            {
                    2, 2,  2, 2,  2, 2,  2,  1,  1, 2,  2, 2,  2,  2, 1,  1,  2,  5,  2, 2,  2, 2, 2, 2
            },
            {
                    0, 2,  2, 10, 2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 1,  1,  2,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    0, 19, 1, 20, 1, 1,  1,  1,  1, 2,  2, 2,  2,  2, 1,  1,  2,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 9,  2, 2,  2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 1,  15, 5,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 1,  1,  2,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  1, 2,  2, 2,  2,  2, 1,  1,  2,  2,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 9,  19, 1,  1, 1,  1, 1,  1,  1, 1,  1,  1,  1,  1, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  1, 17, 1, 1,  1,  1, 17, 1,  1,  1,  1, 1,  1, 1, 1, 0
            },
            {
                    0, 1,  1, 1,  1, 1,  1,  1,  2, 7,  2, 2,  2,  2, 7,  2,  1,  1,  1, 16, 1, 1, 1, 1
            },
            {
                    1, 1,  1, 1,  1, 1,  1,  1,  2, 2,  2, 2,  2,  2, 2,  2,  1,  1,  2, 6,  2, 2, 2, 0
            },
            {
                    0, 2,  2, 2,  8, 18, 1,  17, 7, 2,  2, 2,  2,  2, 2,  7,  17, 1,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  2, 2,  2, 2,  2,  2, 2,  2,  1,  1,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  2, 2,  2, 2,  2,  2, 2,  2,  1,  1,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  1,  1,  2, 2,  2, 2,  2,  2, 2,  2,  1,  1,  2, 2,  2, 2, 2, 2
            },
            {
                    2, 2,  2, 2,  2, 2,  0,  1,  1, 1,  2, 2,  2,  2, 1,  1,  1,  0,  2, 2,  2, 2, 2, 2
            },
            {
                    0, 0,  0, 0,  0, 0,  0,  0,  0, 1,  2, 2,  2,  2, 1,  0,  0,  0,  0, 0,  0, 0, 0, 0
            },
    };
    printf("--------------------||WELCOME TO CLUEDO||--------------------\n");
    Position startersPos[6] = {{0, 6}, {0, 16}, {7, 23}, {18, 0}, {24, 9}, {24, 14}};
    createANewGame(startersPos, &newGame);
    maxFirstDiceRoll = 0;
    indexOfNextPlayer = 0;
    for (int i = 0; i<newGame.numberOfPlayer; i++) {
        temp = rollTheDice();
        printf("Player %d : %d\n", i+1, temp);
        if (temp > maxFirstDiceRoll) {
            maxFirstDiceRoll = temp;
            indexOfNextPlayer = i;
        }
    }
    do {
        printf("It's time for player %d\n", indexOfNextPlayer+1);
        playerMovement(newGame.allThePlayers[indexOfNextPlayer], map, newGame);
        printf("Next choice : ");
        scanf("%d", &choice);
        indexOfNextPlayer++;
        indexOfNextPlayer = indexOfNextPlayer%newGame.numberOfPlayer;
    } while (choice != -1);
    free(newGame.allTheRooms);
    free(newGame.allThePlayers);
    printf("GOOD BYE!");
    return 0;
}
