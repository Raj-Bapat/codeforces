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
    int horiz = 0;
    int vert = 0;
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == '0') {
            if (!vert) {
                cout << 1 << " " << 1 << endl;
                vert = 1;
            } else {
                cout << 3 << " " << 1 << endl;
                vert = 0;
            }
        } else {
            if (!horiz) {
                cout << 4 << " " << 3 << endl;
                horiz = 1;
            } else {
                cout << 4 << " " << 1 << endl;
                horiz = 0;
            }
        }
    }
    return 0;
}