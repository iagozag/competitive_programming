#include <bits/stdc++.h>
using namespace std;

string title(string F){
	if(F[0] >= 97) F[0] -= 32;
    for(int i = 1; i < F.size(); i++){
        if(F[i] == ' '){
            if(F[i+1] >= 97) F[i+1] -= 32;
            i++;
        } else if(F[i] <= 90) F[i] += 32;
    }
    return F;
}

int main(){ 
	string F; getline(cin, F);
    
	cout << title(F) << "\n";
}