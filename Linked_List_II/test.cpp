#include <bits/stdc++.h>
using namespace std;
int N;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> N;

        vector<vector<vector<int>>> mat;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    cin >> mat[i][j][k];
                }
            }
        }

        int i = 0, j = 0, k = 0;
        int temp, next;
        // here row is 0 ie. j
        temp = mat[i][j][k];
        mat[i][j][k] = mat[N - 1][N - 1][N - 1];

        while (i < N - 1 && k < N - 1)
        {
            //  i  j k
            // [ith 2d][jth row][kth column]
            int next = mat[i + 1][j][k + 1];
            mat[i + 1][j][k + 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i++;
            k++;
        }

        // 2nd row
        j += 1;
        next = mat[N - 1][j][N - 1];
        mat[N - 1][j][N - 1] = temp;
        temp = next;

        // change matrix and column

        while (i > 0 && k > 0)
        {
            next = mat[i - 1][j][k - 1];

            // next =  mat[i-1][j][k-1];
            mat[i - 1][j][k - 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i--;
            k--;
        }

        // 3nd row
        if (j < N - 1)
            j += 1;

        next = mat[0][j][0];
        mat[0][j][0] = temp;
        temp = next;
        //     mat[N-1][j][N-1] = temp;
        //    temp = next;

        while (i < N - 1 && k < N - 1)
        {
            //  i  j k
            // [ith 2d][jth row][kth column]
            next = mat[i + 1][j][k + 1];
            mat[i + 1][j][k + 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i++;
            k++;
        }

        // mat[0][0][0] = temp;

        // testing
        //     for (int k = 0; k < N; k++)
        //     {
        //         for (int i = 0; i < N; i++)
        //         {
        //             for (int j = 0; j < N; j++)
        //             {
        //                 cout << mat[k][i][j];
        //                 if (j == N - 1)
        //                 {
        //                     cout << endl;
        //                 }
        //             }
        //         }
        //         cout << "\n\n";
        //     }
        // }

        int temp, next;

        int i, j, k;

        i = N - 1;
        j = 0;
        k = 0;
        temp = mat[N - 1][0][0];
        mat[N - 1][0][0] = mat[0][N - 1][N - 1];

        while (i > 0 && k < N - 1)
        {
            next = mat[i - 1][j][k + 1];

            // next =  mat[i-1][j][k-1];
            mat[i - 1][j][k + 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i--;
            k++;
        }

        j += 1;
        next = mat[i][j][k];
        mat[i][j][k] = temp;
        temp = next;

        while (i < N - 1 && k > 0)
        {
            //  i  j k
            // [ith 2d][jth row][kth column]
            next = mat[i + 1][j][k - 1];
            mat[i + 1][j][k - 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i++;
            k--;
        }

        j += 1;
        next = mat[i][j][k];
        mat[i][j][k] = temp;
        temp = next;

        while (i > 0 && k < N - 1)
        {
            next = mat[i - 1][j][k + 1];

            // next =  mat[i-1][j][k-1];
            mat[i - 1][j][k + 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i--;
            k++;
        }

        // change matrix and column

        // 3nd row
        if (j < N - 1)
            j += 1;

        next = mat[0][j][0];
        mat[0][j][0] = temp;
        temp = next;
        //     mat[N-1][j][N-1] = temp;
        //    temp = next;

        while (i < N - 1 && k < N - 1)
        {
            //  i  j k
            // [ith 2d][jth row][kth column]
            next = mat[i + 1][j][k + 1];
            mat[i + 1][j][k + 1] = temp;
            temp = next;
            // mat[i+1][j][k+1] =    ///mat[i][j][k];
            i++;
            k++;
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cout << mat[k][i][j] << " ";
                }
            }
        }
    }

    cout << endl;
    
}