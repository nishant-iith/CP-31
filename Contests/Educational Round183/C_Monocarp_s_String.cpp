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
    void solve(){
        int n;
        string s;
        cin >> n >> s;
        int total_a = 0;
        for (char c : s) if (c == 'a') total_a++;
        int total_b = n - total_a;
        int diff = total_a - total_b;
        if (diff == 0) {
            cout << 0 << endl;
            return;
        }
        vi prefix(n + 1, 0);
        loop(i, 1, n + 1) prefix[i] = prefix[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
        mii last_occur;
        last_occur[0] = 0;
        int min_len = INT_MAX;
        loop(j, 1, n + 1) {
            int needed = prefix[j] - diff;
            if (last_occur.count(needed)) {
                int k = last_occur[needed];
                int cur_len = j - k;
                min_len = min(min_len, cur_len);
            }
            last_occur[prefix[j]] = j;
        }
        int ans = (min_len == n ? -1 : min_len);
        cout << ans << endl;
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