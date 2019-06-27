#ifndef PLAYERS_H
#define PLAYERS_H

#include "deck.h"

class Players{
public:
    Players();
    ~Players();
    vector<Cards>hands; // Bai duoc chia
    void TakeCards(Cards cc); // Nhan bai tren tay
    bool AskPeek(); // hoi de xem bai
    int EvaluateCards(vector<Cards> TableCard);
    int mainPoint;
    int auxiliaryPoint1;
    int auxiliaryPoint2;

};

#endif // PLAYERS_H
