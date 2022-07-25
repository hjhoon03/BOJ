#include <iostream>
#include <string>

using namespace std;

void easymove(string, int*);
void hardmove(string, int*);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int king[2], rock[2];
    int king_copy[2], rock_copy[2];
    string spot;

    cin >> spot;
    king[0] = (int)(spot[0] - 'A') + 1;
    king[1] = (int)(spot[1] - '0');

    cin >> spot;
    rock[0] = (int)(spot[0] - 'A') + 1;
    rock[1] = (int)(spot[1] - '0');

    king_copy[0] = king[0];
    king_copy[1] = king[1];
    rock_copy[0] = rock[0];
    rock_copy[1] = rock[1];

    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) {
        string command;
        cin >> command;
        if(command.length() == 1) easymove(command, king_copy);
        else hardmove(command, king_copy);

        if(king_copy[0] > 8 || king_copy[0] < 1 || king_copy[1] > 8 || king_copy[1] < 1) {
            king_copy[0] = king[0];
            king_copy[1] = king[1];
            continue;
        }

        if(king_copy[0] == rock_copy[0] && king_copy[1] == rock_copy[1]) {
            if(command.length() == 1) easymove(command, rock_copy);
            else hardmove(command, rock_copy);

            if(rock_copy[0] > 8 || rock_copy[0] < 1 || rock_copy[1] > 8 || rock_copy[1] < 1) {
                king_copy[0] = king[0];
                king_copy[1] = king[1];
                rock_copy[0] = rock[0];
                rock_copy[1] = rock[1];
                continue;
            }
        }

        king[0] = king_copy[0];
        king[1] = king_copy[1];
        rock[0] = rock_copy[0];
        rock[1] = rock_copy[1];
    }

    cout << (char)(king[0] + (int)'A' - 1) << king[1] << '\n' << (char)(rock[0] + (int)'A' - 1) << rock[1];

    return 0;
}

void easymove(string command, int* thing) {
    if(command[0] == 'R') thing[0] ++;
    else if(command[0] == 'L') thing[0] --;
    else if(command[0] == 'B') thing[1] --;
    else if(command[0] == 'T') thing[1] ++;
}

void hardmove(string command, int* thing) {
    if(command[0] == 'R') thing[0] ++;
    else if(command[0] == 'L') thing[0] --;

    if(command[1] == 'B') thing[1] --;
    else if(command[1] == 'T') thing[1] ++;
}