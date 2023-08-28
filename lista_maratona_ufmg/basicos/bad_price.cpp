#include<bits/stdc++.h>
using namespace std;
   
int farthest_min(deque<int> prices, int size){
    int suffix_min[size];
    suffix_min[size - 1] = prices[size - 1];
    for (int i = size - 2; i >= 0; i--)
        suffix_min[i] = min(suffix_min[i + 1], prices[i]);
    
    int answer = 0;
    for(int i = 0; i < size; i++){
        if(prices[i] > suffix_min[i])
            answer++;
    }

    for(auto i: suffix_min) cout << i << " ";

    return answer;
}

int main () {
    int n, size, price, answer; cin >> n;
    deque<int> prices;

    for(int i = 0; i < n; i++){
        cin >> size;

        for(int j = 0; j < size; j++){
            cin >> price;
            prices.push_back(price);
        }

        answer = farthest_min(prices, size);

        cout << answer << "\n";
        answer = 0;
        prices.clear();
    }
}
