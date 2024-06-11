#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007
using namespace std;

struct Block {
    int nr_blocks;  // The number of blocks
    char type;  // The type of the block ('H' or 'V')
};

// Function for calculating the power of a number
long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int K;
    fin >> K;  // Read the number of blocks
    long long total = 1;  // The total number of coloring ways

    vector<Block> blocks(K);  // Vector to store the blocks

    // Reading block values and types
    for (int i = 0; i < K; ++i) {
        fin >> blocks[i].nr_blocks >> blocks[i].type;
    }

    for (int i = 0; i < K; i++) {
        // Horizntal blocks
        if (blocks[i].type == 'H') {
            // It's the first horizontal block
            if (i == 0)
            total = (total * (6 * power(3, blocks[i].nr_blocks - 1))) % MOD;

            // If the previous block was horizontal
            else if (i > 0 && blocks[i - 1].type == 'H')
                total = (total * power(3, blocks[i].nr_blocks)) % MOD;

            // If the previous block was vertical
            else if (i > 0 && blocks[i - 1].type == 'V')
            total = (total * (2 * power(3, blocks[i].nr_blocks - 1))) % MOD;

        } else if (blocks[i].type == 'V') {  // Vertical blocks
            // It's the first vertical block encountered
            if (i == 0)
            total = (total * (3 * power(2, blocks[i].nr_blocks - 1))) % MOD;

            // If the previous block was horizontal
            else if (i > 0 && blocks[i - 1].type == 'H')
                total = (total * power(2, blocks[i].nr_blocks - 1)) % MOD;

            // If the previous block was vertical
            else if (i > 0 && blocks[i - 1].type == 'V')
                total = (total * power(2, blocks[i].nr_blocks)) % MOD;
        }
    }

    fout << total;  // Writing the total to the output
     // Closing the input/output file stream
    fin.close();
    fout.close();

    return 0;
}

