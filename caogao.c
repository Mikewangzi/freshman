// // // #include <stdio.h>
// // // #define STLEN 10

// // // int main(void) {
// // //     char words[STLEN];
// // //     puts("Enter strings (empty line to quit):");
    
// // //     while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
// // //         fputs(words, stdout);
// // //     }
    
// // //     puts("Done.");
// // //     return 0;
// // // }
// // // //while(fgets(name,SIZE,stdin)!=NULL&&name[0]!='\n')
// // //    // puts(name,stdout);
// // // #include <stdio.h>

// // // int main() {
// // //     char message[1000]; // 假设消息的最大长度不超过1000个字符
// // //     char ch;
// // //     int index = 0;

// // //     printf("Enter a message: ");

// // //     // 逐字符读取输入，直到遇到换行符 '\n' 或达到数组长度限制
// // //     while ((ch = getchar()) != '\n' && index < sizeof(message) - 1) {
// // //         message[index++] = ch;
// // //     }

// // //     message[index] = '\0'; // 在字符串末尾添加空字符以构成C字符串

// // //     printf("Reversal is: ");

// // //     // 逆序打印消息
// // //     for (int i = index - 1; i >= 0; i--) {
// // //         putchar(message[i]);
// // //     }

// // //     printf("\n");

// // //     return 0;
// // // }
// // #include<stdio.h>
// // char* s_gets(char* s,int n)
// // {
// //     int i=0;
// //     char* ret=fgets(s,n,stdin);
// //     if(ret)
// //     {
// //         while(ret[i]!='\n'&&ret[i]!='\0') 
// //             i++;     
// //         if(ret[i]=='\n')
// //             ret[i]='\0';
// //         else
// //             while(getchar()!='\n')
// //                 continue;
           
// //     }
// //     return ret;
// // }
// // int main()
// // {
// //     char s[5]={0};
// //     char* ret=s_gets(s,5);
// //     puts(ret);
// //     return 0;
// // }
// #include <stdio.h>
// #include <stdbool.h>

// #define BOARD_SIZE 15

// // 定义棋盘
// char board[BOARD_SIZE][BOARD_SIZE];

// // 初始化棋盘
// void initializeBoard() {
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         for (int j = 0; j < BOARD_SIZE; j++) {
//             board[i][j] = ' ';
//         }
//     }
// }

// // 打印棋盘
// void printBoard() {
//     printf("   ");
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         printf("%2d ", i + 1);
//     }
//     printf("\n");
    
//     for (int i = 0; i < BOARD_SIZE; i++) {
//         printf("%2d ", i + 1);
//         for (int j = 0; j < BOARD_SIZE; j++) {
//             printf("|%c ", board[i][j]);
//         }
//         printf("|\n");
//     }
// }

// // 检查是否赢得比赛
// bool checkWin(int row, int col, char player) {
//     // 检查水平方向
//     int count = 0;
//     for (int i = col - 4; i <= col + 4; i++) {
//         if (i < 0 || i >= BOARD_SIZE) continue;
//         if (board[row][i] == player) {
//             count++;
//             if (count == 5) return true;
//         } else {
//             count = 0;
//         }
//     }

//     // 检查垂直方向
//     count = 0;
//     for (int i = row - 4; i <= row + 4; i++) {
//         if (i < 0 || i >= BOARD_SIZE) continue;
//         if (board[i][col] == player) {
//             count++;
//             if (count == 5) return true;
//         } else {
//             count = 0;
//         }
//     }

//     // 检查对角线方向（左上到右下）
//     count = 0;
//     for (int i = -4; i <= 4; i++) {
//         int r = row + i;
//         int c = col + i;
//         if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) continue;
//         if (board[r][c] == player) {
//             count++;
//             if (count == 5) return true;
//         } else {
//             count = 0;
//         }
//     }

//     // 检查对角线方向（左下到右上）
//     count = 0;
//     for (int i = -4; i <= 4; i++) {
//         int r = row + i;
//         int c = col - i;
//         if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) continue;
//         if (board[r][c] == player) {
//             count++;
//             if (count == 5) return true;
//         } else {
//             count = 0;
//         }
//     }

//     return false;
// }

// int main() {
//     int row, col;
//     char currentPlayer = 'X';
//     bool gameover = false;

//     initializeBoard();

//     while (!gameover) {
//         printBoard();
//         printf("Player %c, enter row and column (e.g., 3 4): ", currentPlayer);
//         scanf("%d %d", &row, &col);

//         if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] != ' ') {
//             printf("Invalid move. Try again.\n");
//             continue;
//         }

//         board[row - 1][col - 1] = currentPlayer;

//         if (checkWin(row - 1, col - 1, currentPlayer)) {
//             printBoard();
//             printf("Player %c wins!\n", currentPlayer);
//             gameover = true;
//         } else {
//             currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
//         }
//     }

//     return 0;
// }