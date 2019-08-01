#ifndef PLAYERS_H
#define PLAYERS_H

#include "deck.h"
#include "winner.h"

class Players{
public:
    Players();
    ~Players();

    vector<Cards>hands; // Bai duoc chia
    void TakeCards(Cards cc); // Nhan bai tren tay
    bool AskPeek(int pos); // hoi de xem bai
    void BettingProcess(int &minBet, int &MIP);
    void SetBet(int Bet_Val, int &MIP);
    void ResetBetMoney() { betMoney = 0; };
    void ResetTotalBettedMoney() { TotalBettedMoney = 0;};

    int EvaluateCards(vector<Cards> TableCard);
    int mainPoint;
    int auxiliaryPoint1;
    int auxiliaryPoint2;

    bool bet;
    int TotalPlayerMoney, betMoney, TotalBettedMoney;


};

namespace winner
{
    void DetermineWinner(vector<Players> &TheP, int MIP);
    int CountPlayer(vector<Players> p);

}
#endif // PLAYERS_H
