#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, flag = 0;
vector<int> nums(max_n);
void init(){
    for(int i = 1; i <= (n + 1) / 2; i++){
        nums[i] = 0;
    }
}
void generate(){
    int i = (n + 1) / 2;
    while(i >= 1 && nums[i] == 1){
        nums[i] = 0;
        --i;
    }
    if(i == 0){
        flag = 1;
    }
    else{
        nums[i] = 1;
    }
}
void TestCase(){
    cin >> n;
    while(!flag){
        for(int i = 1; i <= (n + 1) / 2; i++){
            cout << nums[i] << " ";
        }
        for(int i = (n) / 2; i >= 1; i--){
            cout << nums[i] << " ";
        }
        cout << endl;
        generate();
    }
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