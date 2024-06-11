#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
#define MAX 1000000000

// Function to calculate cost with 50% discount on the second product
double sale50(vector<double> &prices, int i) {
    return max(prices[i], prices[i + 1]) + min(prices[i], prices[i + 1]) / 2.0;
}

// Function to calculate cost with 100% discount on the cheapest product
double sale100(vector<double> &prices, int i) {
    double a[3] = {prices[i], prices[i + 1], prices[i + 2]};
    sort(a, a + 3);
    return a[1] + a[2];
}

int main() {
    int N, K;
    // Read the data
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");
    // Read number of products from input file
    fin >> N;
    fin >> K;

    // Create a vector to store prices of products
    vector<double> prices(N);
    // Read prices
    for (int i = 0; i < N; i++) {
        fin >> prices[i];
    }

    // Initialize minCost array with a large value
    vector<double> minCost(N + 1, MAX);
    // Base case
    minCost[0] = 0;

    // Calculate minimum cost for buying different combinations of products
    for (int i = 0; i < N; i++) {
        // Buy the product individually
        minCost[i + 1] = min(minCost[i + 1], minCost[i] + prices[i]);
        if (i + 1 < N) {
            // Group two products with 50% discount on the second product
            minCost[i + 2] = min(minCost[i + 2],
                                        minCost[i] + sale50(prices, i));
        }
        if (i + 2 < N) {
            // Group three products with 100% discount on the cheapest product
            minCost[i + 3] = min(minCost[i + 3],
                                        minCost[i] + sale100(prices, i));
        }
    }

    // Get the total minimum cost
    double total = minCost[N];
    if (K > N)
    total = -1;

    // Write the total cost to output file with one decimal precision
    fout << fixed << setprecision(1) << total;

    // Close the input/output file stream
    fin.close();
    fout.close();

    return 0;
}
