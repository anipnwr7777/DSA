#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
// Function to find the length of the longest repeated subsequence
// of substring `X[0…n-1]`
int LRSLength(string X, int n)
{
    // lookup table stores solution to already computed subproblems;
    // i.e., `lookup[i][j]` stores the length of LRS of substring
    // `X[0…i-1]` and `X[0…j-1]`
    int lookup[n + 1][n + 1];
 
    // first column of the lookup table will be all 0
    for (int i = 0; i <= n; i++) {
        lookup[i][0] = 0;
    }
 
    // first row of the lookup table will be all 0
    for (int j = 0; j <= n; j++) {
        lookup[0][j] = 0;
    }
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if characters at index `i` and `j` matches
            // and the index are different
            if (X[i - 1] == X[j - 1] && i != j) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            // otherwise, if characters at index `i` and `j` are different
            // then look at (i-1,j) and (i,j-1), in this manner the case of elements being at (i,j) is automatically 
            // getting ignored.
            else {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }
 
    // LRS will be the last entry in the lookup table
    return lookup[n][n];
}
 
int main()
{
    string X = "ATACTCGGA";
 
    int n = X.length();
 
    cout << "The length of the longest repeating subsequence is " <<
            LRSLength(X, n);
 
    return 0;
}