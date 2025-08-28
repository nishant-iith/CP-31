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
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Solution {
    private:
        vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        string stringInput(){
            string s;
            cin>>s;
            return s;
        }

    public:
        void solve(){
            // Your code here
            int n, k;
            cin>>n>>k;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];

            bool numExists = false;
            loop(i, 0, n){
                if(arr[i] == k){
                    numExists = true;
                    break;
                }
            }
            if(numExists){
                cout<<"YES\n";
            } else {
                cout<<"NO\n";
            }
        }
};

int main(){
    // fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}