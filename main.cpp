
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 1004

using namespace std;

int grid[MAX_SIZE][MAX_SIZE];
int dp[2][MAX_SIZE][MAX_SIZE];


int perform_dp(int n, int m) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[0][i][m] = grid[i][m];
        dp[1][i][m] = -grid[i][m];
    }
    int chaged_max, not_changed_max;
    for (int j = m-1; j >= 1; --j) {
        for (int i = 1; i <= n; ++i) {
            not_changed_max = max(max(max(dp[0][i - 1][j + 1], dp[0][i][j + 1]), dp[0][i + 1][j + 1]), 0);
            chaged_max = max(max(max(dp[1][i - 1][j + 1], dp[1][i][j + 1]), dp[1][i + 1][j + 1]), 0);

            dp[0][i][j] = grid[i][j] + not_changed_max;

            dp[1][i][j] = max(-grid[i][j] + not_changed_max, grid[i][j] + chaged_max);
        }
    }
    int max_value = 0;
    for (int i = 1; i <= n; ++i) {
        max_value = max(dp[0][i][1], max_value);
        max_value = max(dp[1][i][1], max_value);
    }
    return max_value;
}


int main()
{

    //FILE* f= freopen("in.txt", "r+", stdin);

    int m, n;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    int origin_value;
    int max_result = 0, ret;

    ret = perform_dp(n, m);
    if (ret > max_result) {
        max_result = ret;
    }
    printf("%d\n", max_result);

    return 0;
}