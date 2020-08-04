#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,m,q,t1,t2,t3, dis[501][501], INF = 1e16;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m >> q;
	for(int i = 1; i<=n; i++)
		for(int j = i+1; j<=n; j++)
			dis[i][j] = INF;

	for(int i = 1; i<=n; i++)
		dis[i][i] = 0;
	
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2 >> t3;
		if(t1 > t2)swap(t1,t2);
		dis[t1][t2] = min(dis[t1][t2],t3);
	}

	for(int k = 1; k<=n; k++)
		for(int i = 1; i<=n; i++)
			for(int j = i; j<=n; j++)
				dis[i][j] = min(dis[i][j], dis[min(i,k)][max(i,k)] + dis[min(j,k)][max(j,k)]);
	
	for(int i = 1; i<=q; i++){
		cin >> t1 >> t2;
		if(t1 > t2) swap(t1,t2);
		cout << (dis[t1][t2] >= INF ? -1 : dis[t1][t2]) << endl;
	}

	cout.flush();
	return 0;
}