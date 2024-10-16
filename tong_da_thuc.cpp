#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

priority_queue<pair<int, int>> solve(string str){
    priority_queue<pair<int, int>> q;
    stringstream ss(str);
    string word;
    while(ss >> word){
        if(word != "+"){
            string coefficient = "", exponent = "";
            for(int i = 0; i < word.size(); i++){
                if(word[i] != '*'){
                    coefficient += word[i];
                }
                else break;
            }
            for(int i = word.size() - 1; i >= 0; i--){
                if(word[i] != '^'){
                    exponent += word[i];
                }
                else break;
            }
            reverse(exponent.begin(), exponent.end());
            q.push({stoi(exponent), stoi(coefficient)});
        }
    }
    return q;
}
void TestCase(){
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    priority_queue<pair<int, int>> q1, q2;
    q1 = solve(str1);
    q2 = solve(str2);
    vector<pair<int, int>> res;
    while(!q1.empty() && !q2.empty()){
        auto top1 = q1.top(), top2 = q2.top();
        int exponent1 = top1.first, coeficient1 = top1.second;
        int exponent2 = top2.first, coeficient2 = top2.second;
        if(exponent1 == exponent2){
            int total = coeficient1 + coeficient2;
            q1.pop();
            q2.pop();
            res.push_back({total, exponent1});
        }
        else if(exponent1 < exponent2){
            res.push_back({coeficient2, exponent2});
            q2.pop(); 
        }
        else if(exponent1 > exponent2){
            res.push_back({coeficient1, exponent1});
            q1.pop(); 
        }
    }
    while(!q1.empty()){
        auto top = q1.top();
        q1.pop();
        int exponent = top.first, coeficient = top.second;
        res.push_back({coeficient, exponent});
    }
    while(!q2.empty()){
        auto top = q2.top();
        q2.pop();
        int exponent = top.first, coeficient = top.second;
        res.push_back({coeficient, exponent});
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i].first << "*x^" << res[i].second;
        if(i != res.size() - 1) cout << " + ";
    }
    cout << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */