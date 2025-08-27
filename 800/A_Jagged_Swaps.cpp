#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)

class Solution {
    public:
        void solve(){
            // Your code here
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];

            if(arr[0] != 1) cout<<"NO\n";
            else cout<<"YES\n";
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}