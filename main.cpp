#include <iostream>
#include <vector>
using namespace std;
int sort(int a, vector <int>& b){
    vector <int> min(b.size());
    int delta = 0;
    int delta_ = 0;
    for (auto i : b){
        delta_ = abs(i - a);
        b.push_back()


    }
    return delta;
}
int main() {
    int n, m, k;
    vector <int> a1 = {10, 20, 30};
    vector <int> a2(m);
//    vector <int> a3(n + m);
//    cin >> n;
//    for (int i = 0; i < n; i++){
//        cin >> k;
//        a1.push_back(k);
//        a3.push_back(k);
//    }
//    cin >> m;
//    for (int i = 0; i < m; i++){
//        cin >> k;
//        a2.push_back(k);
//        a3.push_back(k);
//    }
//    auto max = std::max(a3.begin(), a3.end());
//    auto min = std::min(a3.begin(), a3.end());
//    auto delta = max - min;
    cout << sort(9, a1);

}

