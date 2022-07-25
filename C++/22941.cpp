#include <iostream>

using namespace std;

struct man {
    long long int hp;
    long long int atk;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    struct man me{}, en{};
    cin >> me.hp >> me.atk >> en.hp >> en.atk;
    int p, s;
    cin >> p >> s;

    if (en.hp % me.atk <= p) {
        if(en.hp % me.atk == 0) {
            if(me.atk <= p && me.atk < en.hp)
                en.hp += s;
        } else
            en.hp += s;
    }

    int atk_to_vic = en.hp / me.atk;
    int atk_to_gg = me.hp / en.atk;

    if(en.hp % me.atk)
        ++atk_to_vic;
    if(me.hp % en.atk)
        ++atk_to_gg;

    if(atk_to_vic > atk_to_gg)
        cout << "gg";
    else
        cout << "Victory!";

    return 0;
}