#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
   int n,q;
   cin>>n;
   vector<int>prices(n);
   for(int i=0;i<n;i++) cin>>prices[i];
   sort(prices.begin(),prices.end());
   cin>>q;
   for(int i=0;i<q;i++){
    int x,cnt=0;
    cin>>x;
    cout << upper_bound(prices.begin(), prices.end(), x) - prices.begin() << '\n';
   }
}

signed main()
{  
  // int t;
  // cin>>t;
  // while(t--){
    solve();
 // }
  return 0;
}

