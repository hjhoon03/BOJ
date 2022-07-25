#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> dna;

    for(int i = 0; i < n; ++i) {
        dna.emplace_back();
        cin >> dna[i];
    }

    string output = "";
    int HD_sum = 0;

    for(int i = 0; i < m; ++i) {
        int nucleotide[4] = {0}; // A, C, G, T
        for(int j = 0; j < n; ++j) {
            if(dna[j][i] == 'A')
                ++nucleotide[0];
            else if(dna[j][i] == 'C')
                ++nucleotide[1];
            else if(dna[j][i] == 'G')
                ++nucleotide[2];
            else if(dna[j][i] == 'T')
                ++nucleotide[3];
        }

        int max_idx = 0;
        for(int j = 1; j < 4; ++j)
            if(nucleotide[j] > nucleotide[max_idx])
                max_idx = j;

        if(max_idx == 0)
            output.append("A");
        else if(max_idx == 1)
            output.append("C");
        else if(max_idx == 2)
            output.append("G");
        else if(max_idx == 3)
            output.append("T");

        HD_sum += (n - nucleotide[max_idx]);
    }

    cout << output << '\n' << HD_sum;

    return 0;
}
