#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Helper {
    protected:
        vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        
        vi arrayInput(int n){
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }

        string stringInput(){
            string s;
            cin>>s;
            return s;
        }

        void printArray(const vi &arr){
            for(int i=0; i<arr.size(); i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi b = arrayInput();
            ll n = b.size();
            vi count(n+1, 0);
            vector<vi> indices(n+1);
            loop(i, 0, n){
                ll k = b[i];
                if (k <= n) {
                    count[k]++;
                    indices[k].push_back(i);
                }
            }
            bool valid = true;
            loop(k, 1, n+1){
                if (count[k] % k != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                cout << -1 << endl;
            } else {
                vi a(n);
                ll next_val = 1;
                loop(k, 1, n+1) {
                    ll sz = indices[k].size();
                    if (sz > 0) {
                        ll groups = sz / k;
                        loop(g, 0, groups) {
                            loop(j, 0, k) {
                                ll idx = indices[k][g * k + j];
                                a[idx] = next_val;
                            }
                            next_val++;
                        }
                    }
                }
                printArray(a);
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