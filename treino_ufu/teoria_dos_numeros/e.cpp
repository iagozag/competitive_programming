#include <bits/stdc++.h>

using namespace std;

int main(){
    
    while(true){
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) break;
        cout << a << " + " << b << " mod " << c << " = " << ((a+b)%c) << endl;
        cout << a << " - " << b << " mod " << c << " = " << ((a-b)%c) << endl;
        cout << a << " * " << b << " mod " << c << " = " << ((a*b)%c) << endl;
    }

    return 0;
}
