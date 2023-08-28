#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ //_
    set<int> cards1;
    set<int> cards2;
    int n, m, card, k = 0; cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> card;
        cards1.insert(card);
    }

    for(int i = 0; i < m; i++){
        cin >> card; 
        cards2.insert(card);
    }

    if(cards2.size() < cards1.size()) swap(cards1, cards2);
    for(int elem: cards1){
        if(find(cards2.begin(), cards2.end(), elem) == cards2.end()){
            k++;
        }
    } 

    cout << k << endl;
    exit(0);
}
