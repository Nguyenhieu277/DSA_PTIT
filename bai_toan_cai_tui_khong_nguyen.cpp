#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Item{
    int value, weight;
    float ratio;
};
bool compare(const Item a, const Item b){
    return a.ratio > b.ratio;
};
void TestCase(){
    int n, w;
    cin >> n >> w;
    vector<Item> item(n);
    for(int i = 0; i < n; i++){
        cin >> item[i].value >> item[i].weight;
        item[i].ratio = (float)item[i].value / item[i].weight;
    }
    sort(item.begin(), item.end(), compare);
    float totalValue = 0;
    int totalWeight = 0;
    int lastIndex = 0;
    for(int i = 0; i < n; i++){
        if(totalWeight <= w){
            totalValue += item[i].value;
            totalWeight += item[i].weight;
            lastIndex = i;
        }
    }
    if(totalWeight > w){
        totalValue -= float(totalWeight - w) * item[lastIndex].ratio;
    }
    cout << fixed << setprecision(2) << totalValue << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */