#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,m,t1,t2,t3, ans[100001];
vector<pii> e[100001];
priority_queue<pii,vector<pii>,greater<pii>> dij;
pii tt;
bool v[100001];

int main(){
	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2 >> t3;
		e[t1].pb(mp(t3,t2));
	} dij.push(mp(0,1));
	while(!dij.empty()){
		tt = dij.top();
		dij.pop();
		if(v[tt.s])continue;
		v[tt.s] = 1; ans[tt.s] = tt.f;
		for(auto u : e[tt.s]){
			if(v[u.s])continue;
			dij.push(mp(tt.f+u.f,u.s));
		} 
	}
	for(int i = 1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;
}