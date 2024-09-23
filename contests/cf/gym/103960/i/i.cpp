#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int entrada;

    for(int i=0; i<8; i++){
        cin >> entrada;
        if(entrada !=1 && entrada!=0){
            cout << "F" << endl;
            return 0;
        }
    }

    cout << "S" << endl;
}
