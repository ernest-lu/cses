#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, q, bl[200001][35], t1, t2;

int jmp(int g, int k){
	for(int i = 30; i>=0; i--){
		if(((LL)1 << i) > k)continue;
		g = bl[g][i]; k -= ((LL)1 << i);
	}
	return g;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q;
	for(int i = 1; i<=n; i++)
		cin >> bl[i][0];
	
	for(int j = 1; j<=30; j++)
		for(int i = 1; i<=n; i++)
			bl[i][j] = bl[bl[i][j-1]][j-1];

	while(q--){
		cin >> t1 >> t2;
		cout << jmp(t1, t2) << endl;
	}

	cout.flush();
	return 0;
}