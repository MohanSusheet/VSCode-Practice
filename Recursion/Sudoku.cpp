#include<iostream>
#include<vector>

using namespace std;



class Solution
{
public:

    bool checks(int i, int j, char c, vector<vector<char>>&b)
    {
        for(int n = 0; n < 9; n++)
        {
            if(b[i][n] == c)return false;  //checking the ith row

            if(b[n][j] == c)return false;  //checking the jth column

            //checking the corresponding submatrix 3X3
            if(b[3 * (i / 3) + n /3][3* (j / 3) + n % 3] == c)return false;
        }

        return true;
    }

    bool optimizedCheck(int i, int j, char c, vector<vector<char>>&b)
    {
        
    }

    bool solve(vector<vector<char>>&b)
    {
        int n = b.size(); //or we can directly run the loop from 0-8 [as board is 9X9 (give)]
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(b[i][j] != '.')continue; //means there already exists a number at b[i][j]

                for(char c = '1'; c <= '9'; c++)
                {
                    if(optimizedCheck(i, j, c, b))
                    {
                        
                    }

                    if(checks(i, j, c, b))  //T.C --> O(n)
                    {
                        b[i][j] = c;
                        if(solve(b) == true) 
                        {
                            return true;  //some solution was found
                        }
                        else b[i][j] = '.';
                    }
                }
                return false;
            }
        }

        return true;
    }
    
    void solveSudoku(vector<vector<char>>&board)
    {
        solve(board);
    }
};


int main()
{
    vector<vector<char>> board = {{'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};
    
    Solution sol;

    sol.solveSudoku(board);

    for(auto it: board)
    {
        for(char i: it)cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}