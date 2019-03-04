// COURTNEY JO YOUNG
// This demostrates both classes, operator overloading,
// and multiple file linking

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;


class sphere
{
public:
    double r;
    double SurfaceArea;
    double Volume;
    double pi = 3.141596;

    
    sphere(int size)
    {
        r = size;
        SurfaceArea = getSurfaceArea();
        Volume = getSurfaceArea();
    }
    double getSurfaceArea()
    {
        return  4.0 * pi * pow(r, 2);
        
        
    }
    double getVolume()
    {
        return (4.0/3.0) * pi * pow(r,3);
    
        
    };
};


int main()
{
    int size;
    cout << "What is the Radius?: " << endl;
    cin >> size;
    sphere shapea((size));
    
    
    cout << "The Area = " << shapea.getSurfaceArea() << endl;
    
    cout << "The Volume is = " << shapea.getVolume() << endl;
    
    return 0;
}
