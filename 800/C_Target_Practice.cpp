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
    private:
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
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vector<vector<int>> mask(10, vector<int>(10));
            loop(i, 0, 10) {
                loop(j, 0, 10) {
                    char c;
                    cin >> c;
                    if(c == '.') mask[i][j] = 0;
                    else mask[i][j] = 1;
                }
            }

            const int grid[10][10] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
                {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
                {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
                {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
                {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            };

            int score = 0;
            loop(i, 0, 10) {
                loop(j, 0, 10) {
                    score += mask[i][j] * grid[i][j];
                }
            }
            cout<<score<<endl;
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