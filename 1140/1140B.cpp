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

// 1: '<'
// 2: '>'

int main() {
    int t;
    cin >> t;
    for (int ii = 0; ii<t; ii++) {
        int N;
        string str;
        cin >> N >> str;
        string str2 = str;
        int case1 = 0, case2 = 0;
        for (int i = 0; i<str.length(); i++) {
            if (str[i] == '>') {
                if ((i == 0 && str[i+1] == '>') || (i == str.length()-1 && str[i-1] == '<') || (str[i-1] == '>' && str[i+1] == '<')) {
                    str = str.substr(0, i)+str.substr(i+1);
                    i--;
                    case1++;
                }
            }
        }
        for (int i = 0; i<str2.length(); i++) {
            if (str2[i] == '<') {
                if ((i == 0 && str2[i+1] == '>') || (i == str2.length()-1 && str2[i-1] == '<') || (str2[i-1] == '>' && str2[i+1] == '<')) {
                    str2 = str2.substr(0, i)+str2.substr(i+1);
                    i--;
                    case2++;
                }
            }
        }
        cout << min(case1, case2) << endl;
    }
    return 0;
}