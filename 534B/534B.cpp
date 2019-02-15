#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <limits>
#include <cstdio>
using namespace std;



int main() {
    string str;
    cin >> str;
    stack<char> s;
    s.push(str[0]);
    int wins = 0;
    for (int i = 1; i<str.length(); i++) {
        if (!s.empty()) {
            if (str[i] == s.top()) {
                s.pop();
                wins++;
            } else {
                s.push(str[i]);
            }
        } else {
            s.push(str[i]);
        }
    }
    if (wins%2 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}