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
private:
    static inline int getbit(uint64_t n, int j) {
        return (int)((n >> j) & 1ull);
    }
public:
    void solve() {
        uint64_t n; 
        cin >> n;
        if (n == 0) { 
            cout << "YES\n"; 
            return; 
        }
        int m = 64 - __builtin_clzll(n);      
        int Lmax = m + __builtin_ctzll(n);       
        bool ok = false;
        for(int L = m; L <= Lmax && !ok; ++L) {
            bool pal = true;
            for(int j = 0, k = L - 1; j <= k; ++j, --k) {
                int bj = getbit(n, j);
                int bk = getbit(n, k);
                if(j == k) {
                    if(bj != 0) { 
                        pal = false; 
                        break; 
                    }  
                }else if(bj != bk) {
                    pal = false; 
                    break;        
                }
            }
            if(pal) ok = true;
        }
        cout << (ok ?"YES\n" : "NO\n");
    }
};


int main(){
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