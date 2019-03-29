#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int years[100010];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++) {
        cin >> years[i];
        int a = years[i]+1;
        while (true) {
            string s = to_string(a);
            unordered_set<char> sf;
            for (int j = 0; j<s.size(); j++) {
                sf.insert(s[j]);
            }
            if (sf.size() == s.length()) {
                cout << a << endl;
                break;
            }
            a++;
        }
    }
    return 0;
}