#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

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
    void solve() {
        int n, k; 
        cin >> n >> k;
        string s; 
        cin >> s;

        int c0 = 0, c1 = 0, c2 = 0;
        for (char ch : s) {
            if (ch == '0') ++c0;
            else if (ch == '1') ++c1;
            else ++c2;
        }

        int tmin = c0;
        int tmax = c0 + c2;
        int remain = n - k;

        string ans(n, '?');
        loop(i, 1, n + 1) {
            int L = max(tmin, i - remain);
            int R = min(tmax, i - 1);
            bool canStay = (L <= R);

            if (!canStay) {
                ans[i - 1] = '-';
            } else {
                if (i >= tmax + 1 && i <= remain + tmin) {
                    ans[i - 1] = '+';
                } else {
                    ans[i - 1] = '?';
                }
            }
        }

        cout << ans << "\n";
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