#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board

void initialize_board() {
    // Initialize the board with empty spaces
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    // Print the current state of the board
    int i, j;
    printf("   1  2  3\n");
    for(i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for(j = 0; j < 3; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char player) {
    // Check rows, columns, and diagonals for a winning combination
    int i;
    for(i = 0; i < 3; i++) {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
           (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1; // There is a winner
        }
    }
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
       (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1; // There is a winner
    }
    return 0; // No winner yet
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    int moves = 0;
    
    initialize_board();
    
    printf("Welcome to Tic-Tac-Toe!\n");
    print_board();
    while(1) {
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);
        row--;
        col--;
        // Check if the chosen position is valid
        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        print_board();
        
        // Check if the current player wins
        if(check_winner(currentPlayer)) {
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }
        
        // If all positions are filled and no one wins, it's a draw
        if(moves == 9) {
            printf("It's a draw! Good game!\n");
            break;
        }
        
        // Switch player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}

