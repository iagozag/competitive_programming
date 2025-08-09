#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
#define int ll

bool count(int qtd, int s) {
    if(qtd==0) return false;
    int n=1,sz=0;
    while(s--) {
        n*=26;
        sz+=n;
        
        sz++;
        if(sz>qtd) return false;
    }
    cout << "size : " << n << endl;
    return true;
}

int32_t main(){ _
    int n,k;
    cin >> n >> k;

    vector<string> v(n);
    for(string &i:v) cin >> i;

    sort(v.begin(),v.end());
    v.push_back(string('z',k));
    int l=0,r=n-1;
    // cout << count(2,1) << endl;
    for(int i=0;i<k;i++) {
        //if(v[l].size()==i) l++;
        if(v[l].size()>i+1) {
            while(v[l].size()>=i+1) v[l].pop_back();
            
            cout << v[l] << 'a' << endl;
            return 0;
        }
        if(v[l].size()==i) l++;

        for(char c='a';c<='z';c++) {
            // cout << "l: " << l << ' ' << i<< endl;
            if(v[l][i]!=c) {
                for(int j=0;j<i;j++) cout << v[l][j];
                //cout << "teste";
                cout << c << endl;
                // cout << i << ' ' << l << endl;
                return 0;
            }

            int l1 = l, r1=r,x=0;
            while(l1<=r1) {
                int m = (l1+r1)/2;

                if(v[m][i]>c) {
                    x=m;
                    r1 = m-1;
                } else l1 = m+1;
            }
            if(v[x][i] == c) x++;
            
            if(not count(x-l,k-i-1)) {
                r = x-1;
                // cout << i << c  << " saiu do for" << endl;
                // cout << "l e r " << l << ' ' << r << endl;
                break;
            } else l = x;
            // cout << "l e r " << l << ' ' << r << endl;
        }
    }
}