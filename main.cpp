#include <iostream>
#include "deck.h"
#include "players.h"
#include "winner.h"
#include "commonFunction.h"

using namespace std;
using namespace winner;
using namespace Cf;

int main(int argc, char* argv[])
{
    srand(time(0));
    Deck decks;
    vector<int> rand_card = decks.Shuffle_Cards();

    int n;
    cout << " Number of players " << endl;
    cin >> n;
    vector<Players> player(n);
    vector<Cards>board;
    int current_cards_pos = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            player[i].hands.push_back(decks.NewDeck[rand_card[current_cards_pos]]);
            current_cards_pos++;
        }
    }

    dealer = 0;
    SetAll(dealer, n);

    for (int i = 0; i < 5; i++){
        board.push_back(decks.NewDeck[rand_card[current_cards_pos]]);
        current_cards_pos++;
    }

   /* for(int i = 0; i < player.size(); i++)
    {
        cout << i << ":   " ;
        if(player[i].bet == true) cout <<" true " << endl;
        else cout << "false" << endl;
    }*/
    for (int bet_turn = 1; bet_turn <= 4; bet_turn++){

        if (CountPlayer(player) == 1) break;
        clearScreen();
        PrintCard(player, board);
        for (int i = 0; i < n; i++){
            if (player[i].AskPeek(i) == true ){
                player[i].hands[0].Show = true;
                player[i].hands[1].Show = true;
                clearScreen();
                PrintCard(player, board);
                player[i].hands[0].Show = false;
                player[i].hands[1].Show = false;
                string checkDone;
                cout << "Press st when you done !" << endl;
                cin >> checkDone;
            }
            else {
                clearScreen();
                PrintCard(player, board);
            }

        }

        switch (bet_turn){

            case 1:
            {
                player[small_blind].SetBet(SmallBlindMoney, MoneyInPot);
                player[big_blind].SetBet(2*SmallBlindMoney, MoneyInPot);
                mBet = 2*SmallBlindMoney;
                cout << mBet << endl;
                while( MoneyBettingHandler(player, mBet) != true)
                {

                    int recPos = big_blind + 1;   // recPos = recent position
                    for(int i = 1; i <= n; i++)
                    {

                        if(recPos > n) recPos -= n;
                        cout << "PLAYER " << recPos << endl;
                        player[recPos-1].BettingProcess(mBet, MoneyInPot);
                        recPos += 1;
                    }
                }

                for (int i = 0; i < 3; i++){
                    board[i].Show = true;
                }
                for(int i = 0; i < player.size(); i++)
                {
                    player[i].ResetBetMoney();
                }
                    break;
            }
            case 2:{
              /*  for (int i = 0; i < 3; i++){
                    board[i].Show = true;
                } */
                cout << "stage 2" << endl;
                int mBet2 = 0;
               do {
                int recPos = small_blind; // recPos = recent position
                for(int i = 1; i <= n; i++)
                    {
                        if(recPos > n) recPos -= n;
                        cout << "PLAYER " << recPos << endl;
                        player[recPos-1].BettingProcess(mBet2, MoneyInPot);
                        recPos += 1;
                    }
                }
                while ( MoneyBettingHandler(player, mBet2) != true);
                board[3].Show = true;
                for(int i = 0; i < player.size(); i++)
                {
                    player[i].ResetBetMoney();
                }
                break;
            }
            case 3:{
                // board[3].Show = true;
                cout << "stage 3" << endl;
                   int mBet3 = 0;

               do {
                int recPos = small_blind; // recPos = recent position
                for(int i = 1; i <= n; i++)
                    {
                        if(recPos > n) recPos -= n;
                        cout << "PLAYER " << recPos << endl;
                        player[recPos-1].BettingProcess(mBet3, MoneyInPot);
                        recPos += 1;
                    }
                }
                while ( MoneyBettingHandler(player, mBet3) != true);
                board[4].Show = true;
                for(int i = 0; i < player.size(); i++)
                {
                    player[i].ResetBetMoney();
                }
                break;
            }
            case 4:{
                cout << "stage 4" << endl;

                //board[4].Show = true;
                int mBet4 = 0;
              do {
                int recPos = small_blind; // recPos = recent position
                for(int i = 1; i <= n; i++)
                    {
                        if(recPos > n) recPos -= n;
                        cout << "PLAYER " << recPos << endl;
                        player[recPos-1].BettingProcess(mBet4, MoneyInPot);
                        recPos += 1;
                    }
                }
                while ( MoneyBettingHandler(player, mBet4) != true);
                break;
            }
        }
    }


    clearScreen();
    for (int num = 0; num < n; num++){
        player[num].hands[0].Show = true;
        player[num].hands[1].Show = true;
        player[num].EvaluateCards(board);
    }
     for (int i = 0; i < 5; i++) { board[i].Show = true; }


    cout << "SHOW DOWN" << endl;
    PrintCard(player, board);

    for (int num = 0; num < n; num++){

        cout << "PLAYER " << num+1 << endl;
        AnouncePrize(player[num].mainPoint);
    }

    DetermineWinner(player, MoneyInPot);
    cout << endl;
    for(int i = 0; i < player.size(); i++)
    {
        cout << "Player" << i+1 <<" 's money: " << player[i].TotalPlayerMoney << endl;
    }


    /*_______________________________________________
    for (int i = 0; i < n; i++){
        cout << "PLAYER " << i + 1 << "'S CARDS "  << endl;
        for (int j = 0 ; j < 2; j++){
            player[i].hands[j].ShowCards();
            player[i].EvaluateCards(board);
        }
         AnouncePrize(player[i].mainPoint);
        cout << "______________________" << endl;
    }
    cout << "BOARD CARDS" << endl;
    for (int i = 0 ; i < 5; i++){
        board[i].ShowCards();
    }
    cout << "___________________" <<endl;

    cout << endl << endl ;
    DetermineWinner(player);
    ___________________________*/

    return 0;
}


