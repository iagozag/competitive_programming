#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string entrada;
    string aux;
    cin >> t;
    cin.ignore();
    for(int i=0; i<t; i++){
        getline(cin, entrada);
        aux = "";
        for(int j=0; j<entrada.size(); j++){
            if(entrada[j] == 'a') aux+=64;
            else if(entrada[j] == 'e') aux+= 38;
            else if(entrada[j] == 'i') aux+= 33;
            else if(entrada[j] == 'o') aux+= 42;
            else if(entrada[j] == 'u') aux+= 37;
            else aux+= entrada[j];
        }
        cout << aux << endl;

    }
}
