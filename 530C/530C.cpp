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

string str;
int k;

int main() {
    cin >> str >> k;
    int numlets = 0;
    int numsf = 0;
    int numcand = 0;
    for (int i = 0; i<str.length(); i++) {
        if (isalpha(str[i])) {
            numlets++;
        }
        if (str[i] == '?') {
            numcand++;
        }
        if (str[i] == '*') {
            numsf++;
        }
    }
    if (k>numlets) {
        if (!numsf) {
            cout << "Impossible" << endl;
        } else {
            bool afsf = false;
            for (int i = 0; i<str.length(); i++) {
                if (str[i] == '*' && !afsf) {
                    for (int j = 0; j<k-numlets; j++) {
                        cout << str[i-1];
                    }
                    afsf = true;
                } else if (isalpha(str[i])) {
                    cout << str[i];
                }
            }
            cout << endl;
        }
    } else if (k<numlets) {
        if (numlets-numsf-numcand>k) {
            cout << "Impossible" << endl;
        } else {
            string newstr = "";
            int deleted = 0;
            for (int i = str.length()-1; i>=0; i--) {
                if (numlets-deleted>k && !isalpha(str[i])) {
                    deleted++;
                    i--;
                } else if (isalpha(str[i])) {
                    newstr = (str[i]+string())+newstr;
                }
            }
            cout << newstr << endl;
        }
    } else {
        for (int i = 0; i<str.length(); i++) {
            if (isalpha(str[i])) {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}