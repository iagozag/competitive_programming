#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    long double a1, b1, c1;
    long double a2, b2, c2;
    long double multiplicador;
    long double x, y;
    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;

    if(a1*b2 - b1*a2 == 0){
        cout<<"sistema indeterminado"<<endl;
        return 0;
    }

    else if(a1!=0 && a2!=0 ){
        multiplicador = a2/a1;
        b1 = multiplicador * b1;
        c1 = multiplicador * c1;
        a1 = multiplicador * a1;
        y = (c2 - c1)/(b2-b1);
        x = (c2 - b2*y)/a2;
        cout<< fixed <<setprecision(2);
        cout<<x<<" "<<y<<endl;
        return 0;
    }

    else if(a1!=0 && b2!=0){
        y = c2/b2;
        x = (c1 - b1*y)/a1;
        cout<< fixed <<setprecision(2);
        cout<<x<<" "<<y<<endl;
    }
    else if(a2!=0 && b1!=0){
        y = c1/b1;
        x = (c2 - b2*y)/a2;
        cout<< fixed <<setprecision(2);
        cout<<x<<" "<<y<<endl;
        return 0;
    }

    return 0;
}
