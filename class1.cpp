// COURTNEY JO YOUNG
// class1.cpp


#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


class cube
{
public:
    double length;
    double SurfaceArea;
    double Volume;
    
    
    cube(int size)
    {
        length = size;
        SurfaceArea = getSurfaceArea();
        Volume = getSurfaceArea();
    }
   double getSurfaceArea()
    {
        return length*length*6;
    }
    double getVolume()
    {
        return pow(length,3);
        
    }
};


int main()
{
    int size;
    cout << "Length of each EDGE?: " << endl;
    cin >> size;
    cube shapea(size);
  
    
    cout << "The Area = " << shapea.getSurfaceArea() << endl;

    cout << "The Volume is = " << shapea.getVolume() << endl;

    return 0;
}
