#include <iostream>
using namespace std;
#define n 9

bool findEmptyloc(int grid[n][n], int &r, int &c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                r = i;
                c = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeRow(int grid[n][n], int r, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[r][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeCol(int grid[n][n], int c, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][c] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeGrid(int grid[n][n], int r, int c, int num)
{
    int rowFactor = r - (r % 3);
    int colFactor = c - (c % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[n][n], int r, int c, int num)
{
    if (isSafeRow(grid, r, num) && isSafeCol(grid, c, num) && isSafeGrid(grid, r, c, num))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int grid[n][n])
{
    int r, c;
    if (!findEmptyloc(grid, r, c))
    {
        return true;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (isSafe(grid, r, c, i))
        {
            grid[r][c] = i;
            if (solveSudoku(grid))
            {
                return true;
            }
            grid[r][c] = 0;
        }
    }
    return false;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int grid[n][n];

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    solveSudoku(grid);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}