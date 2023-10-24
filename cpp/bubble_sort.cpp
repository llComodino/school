// Bubble sort
// Complexity: O(n^2)

#include <bits/utility.h>
#include <iostream>

using namespace std;

int main(void) {
    
    // Declare a vector N size
    int N;
    cin >> N;
    vector<int> v(N);

    // Input N elements
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // Bubble sort
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }

    // Print sorted vector
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
