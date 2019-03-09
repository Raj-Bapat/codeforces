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
    string curr = "";
    while (str != "") {
        if (str.size()%2 == 0) {
            curr = (str[str.size()-1]+string())+curr;
            str = str.substr(0, str.size()-1);
        } else {
            curr = (str[0]+string()) + curr;
            str = str.substr(1);
        }
    }
    cout << curr << endl;
    return 0;
}