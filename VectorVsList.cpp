#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;
using namespace chrono;

int main() {
    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    vector<int> randomNumbers;
    srand(time(0));

    // Generate n random numbers
    for (int i = 0; i < n; i++) {
        randomNumbers.push_back(rand() % 100000);
    }

    // Sorted insertion into vector using linear search
    vector<int> sortedVec;
    auto startVec = high_resolution_clock::now();

    for (int num : randomNumbers) {
        auto pos = sortedVec.begin();
        while (pos != sortedVec.end() && *pos < num) {
            ++pos;
        }
        sortedVec.insert(pos, num);
    }

    auto endVec = high_resolution_clock::now();
    auto vecDuration = duration_cast<microseconds>(endVec - startVec);

    // Sorted insertion into linked list using linear search
    list<int> sortedList;
    auto startList = high_resolution_clock::now();

    for (int num : randomNumbers) {
        auto pos = sortedList.begin();
        while (pos != sortedList.end() && *pos < num) {
            ++pos;
        }
        
        sortedList.insert(pos, num);
    }

    auto endList = high_resolution_clock::now();
    auto listDuration = duration_cast<microseconds>(endList - startList);

    // Results
    cout << "\nTime taken to insert " << n << " elements into a sorted vector (linear search): "
         << vecDuration.count() << " microseconds." << endl;

    cout << "Time taken to insert " << n << " elements into a sorted linked list (linear search): "
         << listDuration.count() << " microseconds." << endl;

    return 0;
}
