#include <bits/stdc++.h>
using namespace std;

bool eh_ord(string str){
    int c = str[0];
	if (c < 97)
		c += 32;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] < 97)
			str[i] += 32;
		if (c >= str[i])
			return false;
		c = str[i];
    }
    return true;
}

int main(){
    int n; cin >> n;
    string word;

    for(int i = 0; i < n; i++){
        cin >> word;
        if(eh_ord(word)) cout << word << ": " << "O" << "\n";
        else cout << word << ": " << "N" << "\n";
    }
}
