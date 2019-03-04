//
//  main.cpp
//  Lab 12
// random_walk_intel.cpp
//  Created by Courtney Jo Young
//  Copyright © 2018 Courtney Jo Young. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cmath>
#include <cstdlib>
#include<ctime>
#include<vector>
#include<string>
using namespace std;

class MazeSolver
{
public:
    MazeSolver(){
        maze = {
            "|||||||||||||||",
            "|nnnnnn|nnnnnn|",
            "|nnnnnn|nnnnnn|",
            "|nnnnnnnnnnnnn|",
            "|nnnnnnnnnnnnn|",
            "|nnnnnnnnnnnnn|",
            "|nnn|nnnnn|nnn|",
            "|nnn|nnnnn|nnn|",
            "|||||||||||ddd|"};
        placerobot();
    }
    void placerobot()
    {
        while(1)
        {
            robotrow = rand() % maze.size();
            robotcol = rand() % maze[0].length();
            
            if (maze[robotrow][robotcol] == 'n')
            {
                maze[robotrow][robotcol]= 'R';
                return;
            }
        }
    }
    
    void displaymaze()
        {
        for (int i = 0; i < maze.size(); i++)
            cout << maze[i] << endl;
        }
    int randmove()
    {
        while (1)
        {
            int vert = rand() % 3 -1;
            int horiz = rand() % 3 -1;
           
            if (maze[robotrow + vert][robotcol+ horiz] == 'n' || maze[robotrow + vert][robotcol+ horiz] == '.')
            {
                maze[robotrow][robotcol] = '.';
                robotrow += vert;
                robotcol += horiz;
                maze[robotrow][robotcol] = 'R';
                return 0;
            }
            else if (maze[robotrow + vert][robotcol+ horiz] == 'd')
            {
                maze[robotrow][robotcol] = '.';
                robotrow += vert;
                robotcol += horiz;
                maze[robotrow][robotcol] = 'R';
                return 1;
            }
        }
    
    }
    
    int move()
    {
        int counter = 0;
        while (1)
        {
            counter++;
            int vert = rand() % 3 -1;
            int horiz = rand() % 3 -1;
            if (counter== 1000)
                return randmove();
            
            if (maze[robotrow + vert][robotcol+ horiz] == 'n')
            {
                maze[robotrow][robotcol] = '.';
                robotrow += vert;
                robotcol += horiz;
                maze[robotrow][robotcol] = 'R';
                return 0;
            }
            else if (maze[robotrow + vert][robotcol+ horiz] == 'd')
            {
                maze[robotrow][robotcol] = '.';
                robotrow += vert;
                robotcol += horiz;
                maze[robotrow][robotcol] = 'R';
                return 1;
            }
        }
        
    }
    
    
    
    
    void solve()
    {
        while (!move())
        {
            displaymaze();
        }
        displaymaze();
       
    }
            private:
            vector <string> maze;
            int robotrow;
            int robotcol;
    
            };


int main() {
    
    srand(time(0));
    MazeSolver herewego = MazeSolver();
    herewego.solve();
    return 0;
}
