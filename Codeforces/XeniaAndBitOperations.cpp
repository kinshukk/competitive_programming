#include <bits/stdc++.h>
using namespace std;

vector<int> tree[20];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	int l = (int) pow(2, n);
	int inp;
	for(int i=0; i<l; i++){
		cin >> inp;
		tree[0].push_back(inp);
	}

	int ptr = 0;
	bool turn = 0;	//0 means OR, 1 means XOR

	//build original tree
	while(ptr <= n){
		if(!turn){
			for(int i=0; i<tree[ptr].size(); i += 2){
				tree[ptr+1].push_back( tree[ptr][i] | tree[ptr][i+1] );
			}
		}else{
			for(int i=0; i<tree[ptr].size(); i += 2){
				tree[ptr+1].push_back( tree[ptr][i] ^ tree[ptr][i+1] );
			}
		}
		turn = !turn;
		ptr++;
	}

	int p, b, ans;
	for(int i=0; i<m; i++){
		cin >> p >> b;
		p--;
		turn = 0;//init to OR first
		ptr = 0;
		ans = b;
		while(ptr < n){
			tree[ptr][p] = ans;
			if(turn){
				//XOR
				if(p%2 == 1){
					ans ^= tree[ptr][p-1];//left
				}else{
					ans ^= tree[ptr][p+1];//right
				}
			}else{
				//OR
				if(p%2 == 1){
					ans |= tree[ptr][p-1];//left
				}else{
					ans |= tree[ptr][p+1];//right
				}
			}

			p /= 2;
			ptr++;
			turn = !turn;
		}
		
		tree[ptr][p] = ans;

		cout << ans << endl;
	}
}
