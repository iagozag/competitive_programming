#include <bits/stdc++.h>
using namespace std;

int hanoi(int n, int orig, int dest, int temp){
    return(pow(2, n) - 1);
}

int main(){
	int n; cin >> n;
    cout << hanoi(n, 1, 3, 2) << endl;
}