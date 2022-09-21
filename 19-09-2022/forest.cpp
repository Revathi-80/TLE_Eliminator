//prefix sum


#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,q;
	cin>>n>>q;
	char v[n][n];
	int pre[n+1][n+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
           cin>>v[i][j];
		}
	}
	memset(pre,0,sizeof(pre));
    for(int i=1;i<n+1;i++){
    	if(v[i-1][0]=='*')
    		pre[i][0]=pre[i-1][0]+1;
    	else
    		pre[i][0]=pre[i-1][0];
    	if(v[0][i-1]=='*')
    		pre[0][i]=pre[0][i-1]+1;
    	else
    		pre[0][i]=pre[0][i-1];
    }
    for(int i=1;i<n+1;i++){
    	for(int j=1;j<n+1;j++){
    		pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
             if(v[i-1][j-1]=='*')
             	pre[i][j]++;
    	}
    }
// for(int i=1;i<n+1;i++){
//     	for(int j=1;j<n+1;j++){
//     		cout<<pre[i][j]<<" ";
//     	}
//     	cout<<endl;
//     }
    while(q--){
    	int a1,b1,a2,b2;
    	cin>>a1>>b1>>a2>>b2;
    	int ans=pre[a2][b2]-pre[a2][b1-1]-pre[a1-1][b2]+pre[a1-1][b1-1];
    	cout<<ans<<endl;
    	
    }

	return 0;
}
