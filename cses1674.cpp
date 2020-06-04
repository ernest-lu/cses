#include<bits/stdc++.h>
using namespace std;
#define pb push_back

//var 
int n,a,sub[200001];
vector<int> e[200001];

void dfs(int g,int p){
	sub[g] = 1;
	for(int u : e[g]){
		if(u==p)continue;
		dfs(u,g);
		sub[g]+=sub[u];
	}
};

int main(){
	cin >> n;
	for(int i = 2; i<=n; i++){
		cin >> a;
		e[i].pb(a);
		e[a].pb(i);
	}dfs(1,-1);
	for(int i = 1; i<=n; i++)cout << sub[i]-1 << " "; 
	cout << endl;
}