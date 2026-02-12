#include <iostream>
#include <vector>
using namespace std;

//get value of determinant recursively
int determinant(int order, vector<vector<int>>& matrix);
//function to form a minor matrix with respect to element in ith row and jth column of matrix
vector<vector<int>> get_minor(int i, int j, int order, vector<vector<int>>& matrix);
//utility function
void print_matrix(vector<vector<int>> matrix);

int main()
{
    int order;
    cout << "Enter the order of the matrix: \n";
    cin >> order;

    vector<vector<int>> matrix(order, vector<int>(order));
    cout << "Enter the matrix: \n";
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // vector<vector<int>> matrix{{1, 2}, {3, 4}};
    // int order = 2;
    //Answer for determinant is -2.

    // vector<vector<int>> matrix{{1, 2, 3}, {3, 4, 5}, {6, 7, 8}};
    // int order = 3;
    //Answer for determinant is 0.

    // vector<vector<int>> matrix{{1, 2, 3, 4}, {4, 8, -9, 1}, {6, 2, 4, 8}, {1, 9, 3, 1}};
    // int order = 4;
    //Answer for determinant is 1512.

    int ans = determinant(order, matrix);
    cout << ans;
    return 0;
}


int determinant(int order, vector<vector<int>>& matrix)
{
    if (order == 1)
    {
        return matrix[0][0];
    }

    int ans = 0;
    int multiplier = 1;
    for (int i = 0; i < order; i++)
    {
        //if the element is zero, directly add zero without further calling determinant function
        if (matrix[0][i])
        {
            vector<vector<int>> minor_matrix = get_minor(0, i, order, matrix);
            ans += matrix[0][i] * determinant(order - 1, minor_matrix) * (multiplier);
        }
        multiplier *= -1;
    }
    return ans;
}


vector<vector<int>> get_minor(int i, int j, int order, vector<vector<int>>& matrix)
{
    if (order == 1)
    {
        vector<vector<int>> minor_matrix(1, vector<int>(1));
        minor_matrix[0][0] = matrix[i][j];
        return minor_matrix;
    }
    vector<vector<int>> minor_matrix(order - 1, vector<int>(order - 1));

    for (int k = 0, m = 0; m < order; m++)
    {
        if (m == i) continue;
        for (int l = 0, n = 0; n < order; n++)
        {
            if (n == j) continue;
            minor_matrix[k][l] = matrix[m][n];
            l++;
        }
        k++;
    }

    return minor_matrix;
}


void print_matrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }
}
