#include <iostream>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string text;
    cin >> text;

    string find;
    cin >> find;

    int n = text.length();

    for(int i = 0; i < n; ++i) {
        if(isdigit(text[i])) {
            text.erase(i, 1);
            --n;
            --i;
        }
    }

    if(text.find(find) < n)
        cout << 1;
    else
        cout << 0;

    return 0;
}