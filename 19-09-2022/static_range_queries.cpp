// prefix sum


#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
	int n,q;
	cin>>n>>q;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int>pre(n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+v[i-1];
	}
	// for(int i=0;i<n+1;i++){
	// 	cout<<pre[i]<<" ";
	// }
	//cout<<endl;
    while(q--){
       int l,r;
       cin>>l>>r;
       l--;
       cout<<pre[r]-pre[l]<<endl;
    }
	return 0;
}
