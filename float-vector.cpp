/*
 Name: COURTNEY Jo YOUNG
 Date: OCTOBER 2018
 Assignment: LAB 7 part b
 Description: <fill me in>
 *me: <fill me in>
 Date: <fill me in>
 Assignment: <fill me in>
 Description: <fill me in>
 */


#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


void fillspace(vector <float> &space, float mini, float maxi)
{
    srand(time(0));
    
    for (int i = 0; i < space.size(); i++)
        
    {
     float r1 = mini + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxi-mini)));
        space.at(i) = r1;
       
    }
    
}

void vectordisplay(const vector <float> &vect)
{
    cout << "Here is what your cool vector looks like" << endl;
    
for (int i=0; i < vect.size(); i++)
{
    cout << "The Position of # is: " << setw(8) << left << i << ":" << setw(8) << vect.at(i) << endl;
}
    
}

double sum(const vector <float> &values)
{
    double sum = 0;
    for (int i=0; i <values.size(); i++)
        sum += values.at(i);
    return(sum);
}



int main()
{
    int mini = 3 , maxi = 15;
    vector <float> test(20);
    fillspace(test, mini, maxi);
    vectordisplay(test);
    cout << "Sum of the value is: " << sum(test) << endl;
    
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!


