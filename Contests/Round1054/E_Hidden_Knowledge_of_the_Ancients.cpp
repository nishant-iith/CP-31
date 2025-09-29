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
    ll countAtMost(vi& a, int maxDistinct, int maxLength) {
        if (maxLength <= 0 || maxDistinct < 0) 
            return 0;
        int n = a.size();
        if (maxDistinct == 0) return 0;

        unordered_map<int, int> freq;
        freq.reserve(maxDistinct + 1);
        // Optional: freq.max_load_factor(0.25);

        ll ans = 0;
        int left = 0;
        int distinct = 0;

        for (int right = 0; right < n; ++right) {
            int x = a[right];
            if (freq[x] == 0) {
                distinct++;
            }
            freq[x]++;

            while (distinct > maxDistinct) {
                int y = a[left];
                freq[y]--;
                if (freq[y] == 0) {
                    distinct--;
                }
                left++;
            }

            int minLeft = right - maxLength + 1;
            int L = max(left, minLeft);
            if (L <= right) {
                ans += (right - L + 1);
            }
        }
        return ans;
    }

public:
    void solve() {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vi a = arrayInput(n);

        auto G = [&](int d, int len) -> ll {
            return countAtMost(a, d, len);
        };

        ll ans = (G(k, r) - G(k - 1, r)) - (G(k, l - 1) - G(k - 1, l - 1));
        cout << ans << '\n';
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