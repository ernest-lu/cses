#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, q, p[200001];
map<int,int> fen;
char tt;

void upd(int g, int k){
	for(; g<=1e9; g+=(g&-g))
		fen[g] += k;
}

int ge(int g){
	int res = 0;
	for(; g>0; g-=(g&-g))
		res += fen[g];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> p[i];
		upd(p[i], 1);
	}

	while(q--){
		cin >> tt;
		if(tt == '!'){
			int g, k;
			cin >> g >> k;
			upd(p[g], -1); p[g] = k;
			upd(p[g], 1);
			continue;
		}
		int a, b;
		cin >> a >> b;
		cout << ge(b) - ge(a-1) << endl;
	}

	cout.flush();
	return 0;
}