#include <bits/stdc++.h>
using namespace std;
 
int main(){
    char letter; cin >> letter;
    float n1, n2;  cin >> n1 >> n2;

    if(letter == 'M') cout << n1 * n2;
    else if(letter == 'D') cout << n1 / n2;
}