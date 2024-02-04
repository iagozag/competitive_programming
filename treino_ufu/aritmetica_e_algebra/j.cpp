#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    long double i, l, n;
    cin>>i>>l>>n;
    cout << fixed << setprecision(1);
    cout<<i + l*(n-1) << endl;
    return 0;
}
