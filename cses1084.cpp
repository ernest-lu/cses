#include<bits/stdc++.h>
using namespace std;

//var 
int n,m,a[200001],b[200001],k,apt = 1,ans=0;

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i<=n; i++)cin >> a[i];
	for(int i = 1; i<=m; i++)cin >> b[i];
	sort(a+1,a+n+1); sort(b+1,b+m+1);
	for(int i = 1; i<=n; i++){
		while(apt<=m&&(a[i]-b[apt])>k){
			apt++;
			if(apt>m)break;
		}
		
		if(apt<=m){
			ans+=abs(a[i]-b[apt])<=k;
			if(abs(a[i]-b[apt])<=k)apt++;
		}//cout << i << " " << apt << endl;
	}cout << ans << endl;
}