#include<bits/stdc++.h>
using namespace std;
    
#define endl '\n'
#define f first
#define s second
#define pb push_back
    
typedef long long ll;
    
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
    
int main(){
    int n, index; cin >> n;
    string person;
    vector<string> people;
    map<string, int> unique_people;

    for(int i = 0; i < n; i++){
        cin >> person;
        people.push_back(person);
    }

    for(int i = n-1; i >= 0; i--){
        if(!unique_people[people[i]])
            cout << people[i] << endl;
        unique_people[people[i]] = 1;
    }
    
    exit(0);
}
