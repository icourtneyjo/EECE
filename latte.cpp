
//
//  main.cpp
//  latte.cpp
// :-)
//
//  Created by Courtney Jo Young while drinking a latte (Pumpkin Spice Tea Actually lol)
//  Copyright © 2018 Courtney Jo Young. All rights reserved.
//


#include<stdio.h>
#include<iostream>
#include<cmath>
#include <cstdlib>
#include<ctime>
#define FALSE 0
#define TRUE 1

using namespace std;


class Maze {
    public:
    char M[20][20];
    int playerx;
    int playery;
    int lattex;
    int lattey;
    int lattefinds;
    int turns;
    

    Maze()
    {
        fillmaze();
        playerstart();
        lattefinds = 0;
        turns = 0;
    }
    void fillmaze()
    {
        for (int row = 0; row < 20; row++)
        {
            for (int col = 0; col < 20; col++)
            {
                M[row][col]='*';
            }
        }
        
        
        int row = rand() % 20;
        int col = rand() % 20;
        M[row][col] = '$';
        lattex= col;
        lattey= row;
        
        
        for (int i= 0; i<8; i++)
        {
             row = rand() % 20;
             col = rand() % 20;
            if (M[row][col]== '*')
            {
                (M[row][col]) = '~';
            }
            else
                i--;
        }
        while(1)
        {
            row = rand() % 20;
            col = rand() % 20;
            if (M[row][col]== '*')
            {
                (M[row][col]) = '+';
                break;
            }
    
        }
    }
    void playerstart()
    {
        while(1)
        {
        int row = rand() % 20;
        int col = rand() % 20;
        if (M[row][col]== '*')
        {
            playerx = col;
            playery = row;
            
            break;
        }
        }
    }
    int playerMove(char direction)
    {
        switch (direction) {
            case 'n':
                if (playery > 0)
                    playery--;
                else
                    cout << "YOURE ALREADY ON THE BORDER OF THE MAZE" << endl;
                break;
                
            case 's':
                if (playery < 19)
                    playery++;
                else
                    cout << "YOURE ALREADY ON THE BORDER OF THE MAZE" << endl;
                break;
                
            case 'e':
                if (playerx < 19)
                    playerx++;
                else
                    cout << "YOURE ALREADY ON THE BORDER OF THE MAZE" << endl;
                break;
                
            case 'w':
                if (playerx > 0)
                    playerx--;
                else
                    cout << "YOURE ALREADY ON THE BORDER OF THE MAZE" << endl;
                break;
                
                
            case 'q':
            
                break;
                
            
            default:
                cout << "Enter a VALID key" << endl;
                break;
        }
        
        if (M[playery][playerx] == '~')
        {
            cout << "YOU FOUND A BAD SPEEDWAY COFFEE" << endl;
            return 1;
        }
        else if (M[playery][playerx] == '$')
        {
            cout << "YOU FOUND PUMPKIN SPICE LATTE!!!!! yay!" << endl;
            lattefinds++;
            fillmaze();
            playerstart();
            return 1;
        }
        
        else if (M[playery][playerx] == '+')
        {
            cout << "YOU FOUND THE MONSTER AHHH!!!" << endl;
            playerstart();
        }
        
        int distance = (sqrt(pow(playerx-lattex,2))+ pow(playery-lattey,2));
        if (distance < 2)
        {
            cout << "You are getting HOTTTT!" << endl;
        }
        else if (distance < 4)
        {
            cout << "You are getting warmer!" << endl;
        }
        else
        {
            cout << "You are getting cold!" << endl;
        }
        return 0;
    }
    
    int menu()
    {
        cout << "Enter /'n'/ to go up" <<endl;
        cout << "Enter /'s'/ to go down" <<endl;
        cout << "Enter /'e'/ to go right" <<endl;
        cout << "Enter /'w'/ to go left" <<endl;
        cout << "Enter /'q'/ to QUIT" <<endl;
        char direction;
        cin >>direction;
        if (direction != 'q')
        playerMove(direction);
        else
        return 0;
        return 1;
    }
    
    void start()
    {
        int goon = 1;
        while (goon)
        {
            goon = menu();
            turns++;
        }
        
        cout << "You PLAYED the game " << turns << " turns and";
        cout << "You Found The Latte " << lattefinds << " times! " << endl;
        cout << "Thanks For Playing!! COME BACK SOON!!" << endl;
    }
};
    
    
int main()
{
    
    srand(time(0));
    Maze findlatte = Maze();
    findlatte.start();
    cout << "All Done!" << endl;
};


