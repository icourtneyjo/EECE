//  Created by Courtney Jo Young on 9/19/18.
//  Copyright © 2018 Courtney Jo Young. All rights reserved.



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Dice{
public:
    Dice();
private:
    int diceroll[2];
};
int diceroll()
{   
    return rand () % 6 + 1;
}
bool playOneGame()
{
    int PlayNumber, roll;
    cout << "Enter a # 1-6: " << endl;
    cin >> PlayNumber;
    while (PlayNumber < 1 || PlayNumber > 6)
    {
        cout << "Your number should be between 1- " << endl;
        cout << "Enter a # 1-6: " << endl;
        cin >> PlayNumber;
    }
    
    for (int i=1; i<=3; i++)
    {
        roll= diceroll();
        cout << "Your roll # " << i << " is: " << roll << endl;
        
        if (roll== PlayNumber)
        {
            cout <<"You won!! WOOOOO HOOOOOOOO" << endl;
            return true;
        }
    }
    
    cout << "YOU LOSTTTT :-(" << endl;
    return false;
    
}


int main()

{
     
    srand(time(0));
    int totalwins=0, bets,tallyofgames=0, mbank=100;
    bool worl;
    while (1)
    {
        if (mbank <= 0)
        {
            cout << "No $$$ Left :-(" << endl
            << "you have won " << totalwins << " of " << tallyofgames << " your rate is currently at "
            << ((1.0*totalwins/tallyofgames)*100)<< "%" << endl;
            break;
        }
        cout << "Balance is: $" << mbank << endl;
        cout << "What do you want to wager? (click 0 to QUIT!): ";
        cin >> bets;
        while (bets > mbank || bets < 0)
        {
            cout << "Your wager has to be GREATER than 0 or equal to the $$$ in your bank account";
            cout << "Balance is: $ " << mbank << endl;
            cout << "What do you want to wager? (click 0 to QUIT!): ";
            cin >> bets;
        }
        if (bets ==0)
        {
            cout << "Your bank account is: $" << mbank << endl
            << "you have won " << totalwins << " of " << tallyofgames << " your rate is currently at "
            << (1.0*totalwins/tallyofgames*100)<< "%" << endl;
            break;
        }
        worl = playOneGame();
        if (worl)
        {
            mbank += bets;
            totalwins++;
            
        }
        
        else
            mbank -= bets;
        tallyofgames++;
        
        
        
        
    }
}
