#include <bits/stdc++.h>

using namespace std;

double l, k, t1, t2, h;

double f(double v) {
    if (v <= l) {
        return v;
    }

    double timeNotLeaking = l*t1 / v;
    double timeLeaking = t1-timeNotLeaking;

    double amountLeaked = (timeLeaking + t2) * k;

    return l + (v-l - (amountLeaked > (v-l) ? (v-l) : amountLeaked));
}

int main() {
    // l  - leak height (mm)
    // k  - leak rate (mm/h)
    // t1 - duration of rainfall (h)
    // t2 - time between end of rainfall and observation (h)
    // h  - water level at observation (mm)
    cin >> l >> k >> t1 >> t2 >> h;

    // find min
    double lo = 0;
    double hi = DBL_MAX;
    double min;
    double max;

    while (hi-lo > 1e-7) {
        min = (hi+lo) / 2.0;
        if (f(min) < h) {
            lo = min;
        } else {
            hi = min;
        }
    }

    // find max
    lo = 0;
    hi = DBL_MAX;

    while (hi-lo > 1e-7) {
        max = (hi+lo) / 2.0;
        if (f(max) <= h) {
            lo = max;
        } else {
            hi = max;
        }
    }

    cout << fixed << setprecision(10) << min << " " << max << endl;

    return 0;
}