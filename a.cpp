#include <iostream>
#include <string>
using namespace std;

string PalindromicSubstring(string str) {
  int n = str.size();
  string ans = "a";
  for(int i = 0; i < n; i++){
    // odd
    int l = i, r = i;
    while(l >= 0 and r < n and str[l] == str[r]) l--, r++;
    l++, r--;
    if(r-l+1 > 2 and (int)ans.size() < r-l+1) 
      ans = str.substr(l, r-l+1);

    // even
    l = i, r = i+1;
    while(l >= 0 and r < n and str[l] == str[r]) l--, r++;
    l++, r--;
    if(r-l+1 > 2 and (int)ans.size() < r-l+1) 
      ans = str.substr(l, r-l+1);
  }

  if(ans == "a") ans = "none";

  string token = "vbh8xj9c";
  n = ans.size();
  int m = token.size();

  string final_ans = "";
  int i = 0, j = 0;
  while(i < n and j < m){
    final_ans += ans[i++];
    final_ans += token[j++];
  }
  while(i < n) final_ans += ans[i++];
  while(j < m) final_ans += token[j++];

  return final_ans;
}

// keep this function call here
int main(void) { 
   
  cout << PalindromicSubstring("hellosannasmith");
  return 0;
    
}
