#include<bits/stdc++.h>
using namespace std;

//var 
long long n,q,x,u,k,a,b,tr[200001],cur[200001],t1,ty;

void up(long long i, long long j){
	long long x = i;
	for(;x<=n;x+=(x&-x)){
		tr[x]-=cur[i];
		tr[x]+=j;
	}
}

long long gt(long long i){
	long long c = 0;
	for(;i>=1;i-=(i&-i))c+=tr[i];
	return c;
}

int main(){
	cin >> n >> q;
	for(long long i = 1; i<=n; i++){
		cur[i] = 0; cin >> t1;
		up(i,t1);
		cur[i] = t1;
	}

	for(long long i = 1; i<=q; i++){
		cin >> ty; ty--;
		if(ty){
			cin >> a >> b;
			cout << gt(max(a,b)) - gt(min(a,b)-1) << endl;
		}
		else{
			cin >> k >> u;
			up(k,u); cur[k] = u;
		}
	}

}