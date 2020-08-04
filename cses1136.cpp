#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, t1, t2, bl[200001][30], dep[200001], apl[200001][30];
vector<int> e[200001];

void dfs1(int g, int p, int d){
	bl[g][0] = p; dep[g] = d;
	for(int i = 1; i<=20; i++)
		bl[g][i] = bl[bl[g][i-1]][i-1];

	for(auto u : e[g]){
		if(u == p)continue;
		dfs1(u, g, d+1);
	}
}

int LCA(int a, int b){
	if(dep[a] > dep[b])
		swap(a, b);
	for(int i = 20; i>=0; i--){
		if(dep[bl[b][i]] < dep[a]) continue;
		b = bl[b][i];
	} if(a == b)return a;
	for(int i = 20; i>=0; i--){
		if(bl[b][i] == bl[a][i])continue;
		b = bl[b][i]; a = bl[a][i];
	} return bl[b][0];
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	} dfs1(1, 0, 1);

	while(m--){
		cin >> t1 >> t2;
		int L = LCA(t1, t2);
		//cout << t1 << " " << t2 << " " << L << endl;
		for(int i = 20; i>=0; i--){
			if(dep[bl[t1][i]] < dep[L]) continue;
			apl[t1][i]++;
			t1 = bl[t1][i];
		}

		for(int i = 20; i>=0; i--){
			if(dep[bl[t2][i]] < dep[L])continue;
			apl[t2][i]++;
			t2 = bl[t2][i];
		}

		apl[L][0]++;
	}

	for(int j = 20; j>=1; j--){
		for(int i = 1; i<=n; i++){
			//cout << i << " " << j << " " << apl[i][j] << endl;
			apl[i][j-1] += apl[i][j];
			apl[bl[i][j-1]][j-1] += apl[i][j];
		}
	}

	for(int i = 1; i<=n; i++){
		cout << apl[i][0] << " ";  
	} cout << endl;

	cout.flush();
	return 0;
}