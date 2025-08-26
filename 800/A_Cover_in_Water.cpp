#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        int ctr = 0;
        int found = false;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                ctr++;
                if(i+2>n) continue;
                if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.'){
                    cout<<"2\n";
                    found = true;
                    break;
                }
            }
        }
        if(!found) cout<<ctr<<"\n";
    }
}