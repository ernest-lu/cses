#include<bits/stdc++.h>
using namespace std;

//var 
int n,q,a[200001],t[400001],t1,t2,tt;

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = min(t[2*i],t[2*i+1]);
}

void modify(int g, int k){
	for(t[g+=n] = k; g > 0; g/=2) t[g/2] = min(t[g],t[g^1]); 
}

int query(int l, int r) {  //interval [l,r]
  int res = INT_MAX;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
  	//cout << l-n << " " << r-n << " ";
    if (l%2) res = min(t[l++],res);
    if (r%2) res = min(t[--r],res);
  }
  return res;
}

int main(){
	cin >> n >> q;
	for(int i = 0; i<=2*n; i++)t[i] = INT_MAX;
	for(int i = 0; i<n; i++)cin >> t[n+i];
	build();
	for(int i = 1; i<=q; i++){
		cin >> tt >> t1 >> t2; tt--;
		if(tt) cout << query(t1-1,t2) << endl;
		else modify(t1-1,t2);
	}
}