#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    // Store the start and end times of each advertisement
    vector<pair<int, int>> ads(N);
    for (int i = 0; i < N; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        ads[i] = {t1, t2};
    }

    // Sort the advertisements by start time
    sort(ads.begin(), ads.end());

    // Check for any interval of 3600 seconds with more than T seconds of ads
    int start = 0;
    int totalAds = 0;
    while (start < 3600) {
        // Count the total ads in the current interval
        totalAds = 0;
        for (const auto& ad : ads) {
            if (ad.first >= start && ad.second <= start + 3600) {
                totalAds += ad.second - ad.first;
            }
        }

        // If the total ads in the current interval exceed T, return the start time
        if (totalAds > T) {
            cout << start << endl;
            return 0;
        }

        // Move to the next interval
        start++;
    }

    // If no such interval was found, return -1
    cout << -1 << endl;
    return 0;
}