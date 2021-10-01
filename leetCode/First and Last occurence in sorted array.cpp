#include <bits/stdc++.h>

using namespace std;

int main () {

    int n, q;

    cin >> n >> q;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)

        cin >> arr[i];

    while(q--) {

        int k;

        cin >> k;

        // Actual code begin.

        // First occurrence.

        int lo = 0, hi = n-1, mid;

        // p(x): arr[mid] >= k

        // first T

        while (lo < hi) {

            // Mid computation

            mid = lo + (hi - lo)/2;

            // Decision.

            if (arr[mid] >= k)

                hi = mid;

            else

                lo = mid + 1;

        }

        // Sanity check.

        // Not present.

        if (arr[lo] != k) {

            cout << "-1 -1" << endl;

            continue;

        }

        cout << lo << " ";

        // Last occurrence.

        lo = 0, hi = n-1;

        // p(x): arr[mid] > k

        // last F

        while (lo < hi) {

            // Mid computation.

            mid = lo + (hi - lo + 1)/2;

            // Decision.

            if (arr[mid] > k)

                hi = mid - 1;

            else

                lo = mid;

        }

        // No Sanity check.

        cout << lo << endl;

    }

}
