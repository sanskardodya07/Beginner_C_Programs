#include <stdio.h>
#include <stdlib.h>

int main () {
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int x, y, win = 0, turn = 0;
    char mark;

    while (1) {
        printf(" 1 2 3\n");
        for (int i = 0; i < 3; i++) {
            printf ("%d", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf ("\n");
        }
        
        int count;

        do {
            count = 0;

            printf ("Enter y co-ordinates of box to mark on: ");
            scanf ("%d", &x);
            printf ("Enter x co-ordinates of box to mark on: ");
            scanf ("%d", &y);
            x--;
            y--;

            if (x < 0 || x > 2 || y < 0 || y > 2) {
                printf ("Invalid input, try again!!\n");
                count++;
            } else if (board[x][y] != ' ') {
                printf ("Box already marked, try again!!\n");
                count++;
            }
        } while (count != 0);

        if (turn % 2 == 0) {
            mark = 'X';
        } else {
            mark = 'Y';
        }

        board[x][y] = mark;

        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                win = 1;
                break;
            }
        }

        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || (board[2][0] == mark && board[1][1] == mark && board[0][2] == mark) || win == 1) {
            printf ("%c Won!!\n", mark);
            break;
        } else if (turn == 8) {
            printf ("It's a DRAW!!\n");
            break;
        }

        turn++;
    }
    return 0;
}