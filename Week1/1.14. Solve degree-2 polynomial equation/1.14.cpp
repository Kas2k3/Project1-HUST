//CPP 
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() 
{ 
    int a,b,c;
    float x,y,z;
    cin >> a >> b >> c;
    float delta = b*b-4*a*c;
    if(delta < 0) {
        cout << "NO SOLUTION ";
    }
    else if(delta == 0) {
        x = -b/(2*a);
        cout << fixed << setprecision(2) << x << endl;
    }
    else {
        y = (-b - sqrt(delta))/(2*a);
        z = (-b + sqrt(delta))/(2*a);
        cout << fixed << setprecision(2) << y << " ";
        cout << fixed << setprecision(2) << z ;
    }
}
