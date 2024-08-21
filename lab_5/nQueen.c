#include <stdio.h>
#include <stdbool.h>

#define N 4 // Define the size of the chessboard (8x8)

// Function to print the chessboard
void printBoard(int board[N][N])
{
    printf("Solution:\n");
    int queenCount = 1; // To keep track of the queen number
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                printf("Q%d ", queenCount++); // Print the queen with its number
            }
            else
            {
                printf("-  "); // Print a dot for an empty cell
            }
        }
        printf("\n");
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    // Check this row on the left side
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col)
{
    // If all queens are placed, return true
    if (col >= N)
    {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1; // Place the queen

            // Recur to place queens in the next columns
            if (solveNQueens(board, col + 1))
            {
                return true;
            }

            // If placing queen in current position does not lead to a solution
            board[i][col] = 0; // Backtrack
        }
    }

    return false; // No solution exists for this configuration
}

int main()
{
    int board[N][N] = {0}; // Initialize chessboard with 0s

    if (solveNQueens(board, 0))
    {
        printBoard(board); // Print the solution if found
    }
    else
    {
        printf("No solution exists\n");
    }

    return 0;
}
