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
            cin >> n >> k;
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            
            if (k == 0) {
                ll sum = 0;
                for (int x : a) sum += x;
                cout << sum << endl;
            }
            
            vector<int> freq(n + 2, 0);
            for (int x : a) {
                if (x <= n) {
                    freq[x]++;
                }
            }
            
            int M0 = 0;
            while (freq[M0] > 0) {
                M0++;
            }
            
            int count_F = 0;
            ll F_sum = 0;
            for (int x = 0; x < M0; x++) {
                if (freq[x] == 1) {
                    count_F++;
                    F_sum += x;
                }
            }
            
            int L = n - count_F;
            
            if (count_F == M0 && L == 1) {
                ll S1 = F_sum + M0 * L;
                cout << S1 << endl;
            } else {
                ll S1 = F_sum + M0 * L;
                if (k == 1) {
                    cout << S1 << endl;
                } else {
                    if (count_F == M0) {
                        int M1 = M0 + 1;
                        ll S2 = F_sum + M1 * L;
                        if (k % 2 == 0) {
                            cout << S2 << endl;
                        } else {
                            cout << S1 << endl;
                        }
                    } else {
                        int M1 = M0;
                        for (int x = 0; x < M0; x++) {
                            if (freq[x] != 1) {
                                M1 = x;
                                break;
                            }
                        }
                        ll S2 = (ll)(M1 - 1) * M1 / 2 + (ll)M1 * (n - M1);
                        if (n - M1 == 1) {
                            cout << S2 << endl;
                        } else {
                            ll S3 = (ll)(M1 - 1) * M1 / 2 + (ll)(M1 + 1) * (n - M1);
                            if (k % 2 == 0) {
                                cout << S2 << endl;
                            } else {
                                cout << S3 << endl;
                            }
                        }
                    }
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