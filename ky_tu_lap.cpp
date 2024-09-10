#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int minOverlap = INT_MAX;
int n;
int countOverlap(string a, string b){
    int frequency[26] = {0};
    for(char it : a){
        frequency[it - 'A']++;
    }
    for(char it : b){
        frequency[it - 'A']++;
    }
    int cnt = 0;
    for(auto it : frequency){
        if(it == 2){
            cnt++;
        }
    }
    return cnt;
}
void backTracking(int idx, int currentOverlap, vector<string> &current){
    if(currentOverlap >= minOverlap) return;
    if(idx == n){
        minOverlap = currentOverlap;
        return;
    }
    else if(currentOverlap < minOverlap){
        for(int i = idx; i < n; i++){
            swap(current[idx], current[i]);
            int newOverlap = currentOverlap;
            if(idx > 0){
                newOverlap += countOverlap(current[idx - 1], current[idx]);
            }
            backTracking(idx + 1, newOverlap, current);
            swap(current[idx], current[i]);
        }
    }
}
void TestCase(){
    cin >> n;
    vector<string> str;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        str.push_back(s);
    }
    backTracking(0, 0, str);
    cout << minOverlap << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */