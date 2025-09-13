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
            int n, k;
            cin>>n>>k;
            vi arr = arrayInput(n);

            vi feq(n+1, 0);
            loop(i, 0, n){
                feq[arr[i]]++;
            }

            // if any of the frequency is not divisible by k, then it's not possible
            bool valid = true;
            loop(i, 1, n+1){
                if(feq[i] % k != 0){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                cout<<0<<endl;
                return;
            }

            // atmost how many we can keep 
            vi atMost(n+1, 0);
            loop(i, 1, n+1){
                if (feq[i] > 0) {
                    atMost[i] = feq[i] / k;
                }
            }

            vi count(n+1, 0);
            int invalid = 0;
            ll ans = 0;

            int r = 0;

            loop(l, 0, n){
                while (r < n && invalid == 0) {
                int v = arr[r];
                    count[v]++;
                    if (count[v] > atMost[v]) {
                        invalid++;
                    }
                    r++;
                }
            
            if (invalid == 0) {
                ans += n - l;
            } else {
                ans += r - l - 1;
            }
            int v = arr[l];
            if (count[v] > atMost[v]) {
                invalid--;
            }
            count[v]--;
            }
            cout << ans << '\n';

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