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
        // Your code here
        int n; cin >> n;
        vector<ll> a(n);
        for (auto &x: a) cin >> x;
        sort(a.begin(), a.end());

        vector<ll> L; vector<int> C;
        for (int i=0;i<n;){
            int j=i; while (j<n && a[j]==a[i]) ++j;
            L.pb(a[i]); C.pb(j-i);
            i=j;
        }
        int k = (int)L.size();

        vector<ll> ps(k), poSum(k), poTop1(k), poTop2(k);
        vector<long long> pc(k), poCnt(k);
        for (int i=0;i<k;i++){
            ps[i]   = (i?ps[i-1]:0) + L[i]*1LL*C[i];
            pc[i]   = (i?pc[i-1]:0) + C[i];
            bool odd = (C[i]&1);
            poCnt[i]= (i?poCnt[i-1]:0) + (odd?1:0);
            poSum[i]= (i?poSum[i-1]:0) + (odd?L[i]:0);
            ll t1 = (i?poTop1[i-1]:0), t2 = (i?poTop2[i-1]:0);
            if (odd){
                if (L[i] >= t1) { t2 = t1; t1 = L[i]; }
                else if (L[i] > t2) t2 = L[i];
            }
            poTop1[i]=t1; poTop2[i]=t2;
        }

        ll ans = 0;
        for (int i=k-1;i>=0;i--){
            ll S = ps[i], M = L[i];
            long long cnt = pc[i], oc = poCnt[i];
            ll oSum = poSum[i], t1 = poTop1[i], t2 = poTop2[i];

            ll cost = (oc<=2) ? 0 : (oSum - (t1 + t2));
            ll Sprime = S - cost;
            long long sides = cnt - max(0LL, oc - 2);

            if (sides >= 3 && 2*M < Sprime) { ans = Sprime; break; }
        }
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