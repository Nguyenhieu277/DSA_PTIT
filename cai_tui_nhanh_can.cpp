#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Item{
    int weight;
    int value;
};
struct Node{
    int level;
    int profit;
    int bound;
    int weight;
    bool operator < (const Node& other) const {
        return bound < other.bound;
    }
};
bool compare(const Item& a, const Item& b){
    double x = (double) a.value / a.weight;
    double y = (double) b.value / b.weight;
    return x > y;
}
int bound(const Node& u, const int& n, const int& W, vector<Item>& items){
    if(u.weight >= W) return 0;
    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while((j < n) && (totweight + items[j].weight <= W)){
        totweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }
    if(j < n){
        profit_bound += (W - totweight) * ((double)items[j].value / items[j].weight);
    }
    return profit_bound;
}
int knapsack(const int& W, vector<Item>& items, const int& n){
    sort(items.begin(), items.end(), compare);
    priority_queue<Node> q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = bound(u, n, W, items);
    q.push(u);
    int maxProfit = 0;
    while(!q.empty()){
        u = q.top();
        q.pop();

        if(u.level == -1) v.level = 0;
        if(u.level == n - 1) continue;
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
        if(v.weight <= W && v.profit > maxProfit){
            maxProfit = v.profit;
        }
        v.bound = bound(v, n, W, items);
        if(v.bound > maxProfit){
            q.push(v);
        }
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if(v.bound > maxProfit){
            q.push(v);
        }
    }
    return maxProfit;
}
void TestCase(){
    int n, W;
    cin >> n >> W;
    vector<int> v, w;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        w.push_back(x);
    }
    vector<Item> items(n + 1);
    for(int i = 0; i < n; i++){
        items[i].weight = v[i];
        items[i].value = w[i];
    }
    cout << knapsack(W, items, n) << endl;
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