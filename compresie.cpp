#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>

using namespace std;

// Function to calculate the result
int get_res(int n, int m, vector<int>& A, vector<int>& B) {
    int counter = 0;

    for (int i = 0; i < n;) {
        for (int j = 0; j < m;) {
            // If elements at current indices in A and B are equal
            if (A[i] == B[j]) {
                counter++;  // Increment counter
                i++;        // Move to the next element in A
                j++;        // Move to the next element in B

            // If element in A is greater than element in B
            } else if (A[i] > B[j]) {
                B[j + 1] += B[j];   // Sum elem j and j + 1 in B
                j++;                // Move to the next element in B

            // If element in A is less than element in B
            } else {
                A[i + 1] += A[i];   // Sum elem i and i + 1 in A
                i++;                // Move to the next element in A
            }
        }
    }
    // Return the result
    return counter;
}

int main() {
    long int n, m, asum, bsum;

    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    // Read the value of 'n'
    fin >> n;
    vector<int> A(n);
    // Read values into vector A
    for (int i = 0; i < n; i++) {
        fin >> A[i];
    }
    // Read the value of 'm'
    fin >> m;
    vector<int> B(m);
    // Read values into vector B
    for (int i = 0; i < m; i++) {
        fin >> B[i];
    }
    // Calculate the sum of elements in vectors A and B
    asum = accumulate(A.begin(), A.end(), 0);
    bsum = accumulate(B.begin(), B.end(), 0);

    // If the sums are not equal, print -1
    if (asum != bsum) {
        fout << -1;
    } else {
        // Otherwise, calculate and print the result
        int max_len = get_res(n, m, A, B);
        fout << max_len;
    }
    // Close input/output files
    fin.close();
    fout.close();

    return 0;
}
