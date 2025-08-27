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

class Helper {
    public:
        static vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        static string stringInput(){
            string s;
            cin>>s;
            return s;
        }
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi arr = arrayInput();

            map<ll, ll> mpp;
            loop(i, 0, arr.size()){
                mpp[arr[i]]++;
            }

            if(mpp.size()>2){
                cout<<"No\n";
            } else {
                ll freq_1 = mpp.begin()->second;
                ll freq_2 = mpp.rbegin()->second;

                if(freq_1 == freq_2){
                    cout<<"Yes\n";
                }
                else if (arr.size() % 2 == 1 && abs(freq_1 - freq_2) == 1){
                    cout<<"Yes\n";
                } else {
                    cout<<"No\n";
                }
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