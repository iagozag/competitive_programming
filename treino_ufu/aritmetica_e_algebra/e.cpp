#include <bits/stdc++.h>

using namespace std;

int main(){
    float m, s; cin >> m >> s;
    m += s/60;

    float a = m/10.0, b = a*21.0;
    cout << fixed << setprecision(1) << round(a * 10) / 10 << endl; 
    cout << fixed << setprecision(1) << round(b * 10) / 10 << endl;

    return 0;
}
