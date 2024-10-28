#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double t, p, min, ans, current;
    int n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> p;
        ans = pow(p / 100.0, (n - 1.0) / (n * 1.0)) * 100;
        // current = pow(p / 100.0, n - 1);
        // ans = pow(current, 1.0 / n) * 100.0;
        if (ans > 0)
            cout << "Case #" << i + 1 << ": " << fixed << setprecision(15) << ans - p << endl;
        else
            cout << "Case #" << i + 1 << ": " << fixed << setprecision(15) << 0 << endl;
    }
}