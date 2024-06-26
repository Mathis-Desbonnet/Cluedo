//
// Created by Mathi on 6/18/2024.
//

#ifndef CLUEDO_CHARACTERS_H
#define CLUEDO_CHARACTERS_H

typedef enum {
    MOUTARDE, OLIVE, VIOLET, PERVENCHE, ROSE, LEBLANC
} CharactersName;

typedef enum {
    HALL, BAR, SALLE_A_MANGER, CUISINE, SALLE_DE_BALLE, CONSERVATOIRE, BILLIARD, BIBLIOTHEQUE, BUREAU
} RoomsName;

typedef enum {
    POIGNARD, CHANDELIER, REVOLVER, CORDE, BARRE_DE_FER, CLE_A_MOLETTE
} Weapons;

typedef struct {
    int posXOut;
    int posYOut;
    int posXIn;
    int posYIn;
} Doors;

typedef struct {
    int posX;
    int posY;
} Position;

typedef struct {
    RoomsName room1;
    RoomsName room2;
} SecretWay;

typedef struct {
    RoomsName name;
    Doors* allDoors;
    SecretWay* secretWay;
    Position* roomPosition;
    int roomPosLogSize;
    int numberOfDoors;
} Room;

typedef struct {
    CharactersName name;
    RoomsName room;
    Weapons weapons;
} Killer;

typedef struct {
    int* playerCards;
    int numberOfCard;
} Card;

typedef struct {
    CharactersName name;
    Position playerPos;
    int roomIndexIn;
    Card* Card;
} Player;

#endif //CLUEDO_CHARACTERS_H
