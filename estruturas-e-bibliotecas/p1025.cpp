#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int bsearch(vector<int> v, int lower, int upper, int target)
{
    int pos = (upper + lower) / 2;
    if (target == v[pos])
        return pos;
    else if (upper == lower)
        return -1;
    else {
        if (target < v[pos])
            return bsearch(v, lower, pos, target);
        else
            return bsearch(v, pos + 1, upper, target);
    }
}

int main()
{
    int a, b, kase = 1;
    while (1) {
        scanf ("%d %d ", &a, &b);
        if (!a && !b) break;

        int x;
        vector<int> v;
        for (int i = 0; i < a; i++) {
            scanf ("%d ", &x);
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        printf ("CASE# %d:\n", kase);
        for (int i = 0; i < b; i++) {
            scanf ("%d ", &x);
            int pos = bsearch(v, 0, v.size() - 1, x);
            if (pos != -1) {
                printf ("%d found at %d\n", x, pos + 1);
            }
            else {
                printf ("%d not found\n", x);
            }
        }
        kase++;
    }
    return 0;
}
