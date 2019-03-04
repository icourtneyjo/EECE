//
//  main.cpp
//  Lab 8
//
//  Created by Courtney Jo Young on 11/1/18.
//  Copyright © 2018 Courtney Jo Young. All rights reserved.
//

#include <ctime>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int randoNum (int maxi)
{
    return rand() % (maxi +1);
}

vector <int> randoCount(int maxi, int numb)

{
    vector <int> counter(maxi+1,0);
    for (int i =0; i<= numb; i++)
    {
        counter.at(randoNum(maxi))++;
    }
    return counter;
}


float mean(const vector <int> values)
{
    if (values.size() == 0)
        return 0;
    float sum = 0;
    for (int i=0; i <values.size(); i++)
        sum += values.at(i);
    return(sum / values.size());
}

float stddev(const vector <int> values) {
    if (values.size() ==0)
        return 0;
    float avg = mean(values);
    vector<int> squdev = values;
    for (int i =0; i < values.size(); i++)
    {
        squdev.at(i) = pow(values.at(i) - avg, 2);
    }
    return sqrt(mean(squdev));
}



unsigned int minValue(const vector<int> &countme)
{
    int place = 0;
    for (int i = 1; i < countme.size(); i++)
    {
        if (countme.at(i) < countme.at(place))
            place = i;
    }
    return countme.at(place);
    
}

unsigned int maxValue(const vector<int> &countme)
{
    int place = 0;
    for (int i = 1; i < countme.size(); i++)
    {
        if (countme.at(i) > countme.at(place))
            place = i;
    }
    return countme.at(place);
    
}

void vectordisplay(const vector <int> &vect)
{
    cout << "Here is what your cool vector looks like" << endl;
    
    for (int i=0; i < vect.size(); i++)
    {
        cout << "The Position of # is: " << setw(8) << left << i << ":" << setw(8) << vect.at(i) << endl;
    }
    
}


void dispStatistics(vector<int> &stats)
{
    cout << "Mean is: " << mean(stats) << endl;
    cout << "Standard deviation is: " << stddev(stats) << endl;
    cout << "Minimum is: " << minValue(stats) << endl;
    cout << "Maximum is: " << maxValue(stats) << endl;
}


void displayBarChart(vector<int> &vect)
    {
        
        cout << setw(8) << "Value" << "-" << "Count" << endl;
        for (int r = 0; r < vect.size(); r++)
        {
            cout << setw(8) << r << "-" << "-";
            
            for (int ast = 0; ast < vect.at(r); ast++)
            {
                cout << "*" ;
            }
            cout << endl;
        }
    }


int main()
{
    srand(time(0));
    int maxi, num;
    cout << "What is the Maximum Value? ";
    cin >> maxi;
    cout << "How many Numbers? ";
    cin >> num;
    
    vector <int> vect = randoCount(maxi, num);
    vectordisplay(vect);
    displayBarChart(vect);
    dispStatistics(vect);
}
