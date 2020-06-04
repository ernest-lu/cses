#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second

//var 
LL n,m,h[200001],r[200001], tr[400001],x,g;

LL bes(LL a1, LL a2){
	return(h[a1] > h[a2] ? a1 : a2);
}

void upd(LL g){
	LL og = g;
	for(tr[g+=n] = og; g>1; g/=2)
		tr[g/2] = bes(tr[g],tr[g^1]);
}

LL que(LL l, LL r){
	LL le = l, ri = r-1;
	for(l += n, r += n; l<r; l /= 2, r /= 2){
		if(l%2)le = bes(le,tr[l++]);
		if(r%2)ri = bes(ri,tr[--r]);
	}
	return bes(le,ri);
}

int main(){
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> h[i];
		upd(i);
	}
	for(int i = 1; i<=m; i++){
		cin >> x;
		g = que(0,n);
		if(x <= h[g]){
			LL l = 1, r = n, mid;
			while(l < r){
				mid = (l + r)/2;
				if(h[que(0,mid)] >= x)r = mid;
				else l = mid+1;
			}
			g = que(0,l);
			h[g] -= x;
			upd(g);
			cout << g+1 << " ";
			continue;
		}
		cout << 0 << " ";
	}
}