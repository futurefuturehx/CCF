#include <iostream>
using namespace std;

int board[32][32];

void eliminate(const int m, const int n)
{
    int con, cur;
    for (int i = 0; i < m; ++i)
    {
        cur = 0;
        con = 0;
        for (int j = 0; j <= n; ++j)
        {
            if (j < n && board[i][j] == cur || board[i][j] == -cur || cur == 0)
            {
                ++con;
            }
            else
            {
                // update board by neg
                if (con >= 3)
                {
                    for (int k = 1; k <= con; ++k)
                    {
                        board[i][j-k] = (cur < 0) ? cur : -cur;
                    }
                }

                con = 1;
            }
            cur = (j < n) ? board[i][j] : 0;
        }
    }

    for (int j = 0; j < n; ++j)
    {
        con = 0;
        cur = 0;
        for (int i = 0; i <= m; ++i)
        {
            if (i < m && board[i][j] == cur || board[i][j] == -cur || cur == 0)
            {
                ++con;
            }
            else
            {
                // update board by neg
                if (con >= 3)
                {
                    for (int k = 1; k <= con; ++k)
                    {
                        board[i-k][j] = (cur < 0) ? cur : -cur;
                    }
                }
                
                con = 1;
            }
            cur = (i < m) ? board[i][j] : 0;
        }
    }

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] < 0)
                board[i][j] = 0;
}

int main(int argc, char const *argv[])
{
    int m, n;
    // input
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    // cout << endl;

    eliminate(m, n);

    // cout << endl;

    // output
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
