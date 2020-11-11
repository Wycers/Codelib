package net.mooctest;

public class Board {

    /*
     * createBoard method creates initial Othello board,
     * X means black, O means white.
     * */

    public String[][] createBoard() {

        String[][] board = new String[8][8];
        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                if ((i == 3 && k == 3) || (i == 4 && k == 4))
                    board[i][k] = "O";
                else if ((i == 3 && k == 4) || (i == 4 && k == 3))
                    board[i][k] = "X";
                else
                    board[i][k] = ".";
            }
        }
        return board;
    }

    /*
     * printBoard method displays any of boards.
     * */

    public void printBoard(String[][] board) {
        System.out.println("  01234567");
        for (int i = 0; i < 8; i++) {
            System.out.print(i);
            System.out.print(" ");
            for (int k = 0; k < 8; k++)
                System.out.print(board[i][k]);
            System.out.println();
        }
        System.out.println();
    }

    /*
     * checkPossibleWhiteMoves method puts '1' to all
     * squares which are neighbor of black squares.
     * We are putting '1' because later all '1's will
     * be checked for game rules.
     * We need this method since we can not move any
     * random square in the board according to game
     * rules. In other words, in each turn we should
     * move legally.
     * */

    public String[][] checkPossibleWhiteMoves(String[][] game_board) {

        String[][] white_board = new String[8][8];

        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
                white_board[i][k] = game_board[i][k];

        Boolean[][] isChecked = new Boolean[8][8];
        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                isChecked[i][k] = false;
            }
        }

        for (int i = 0; i < 8; i++) {

            for (int k = 0; k < 8; k++) {
                if (white_board[i][k] == "X") {
                    if ((i - 1 >= 0) && white_board[i - 1][k] != "X" && white_board[i - 1][k] != "O")
                        white_board[i - 1][k] = "1";
                    if ((i - 1 >= 0) && (k + 1 <= 7) && white_board[i - 1][k + 1] != "X" && white_board[i - 1][k + 1] != "O")
                        white_board[i - 1][k + 1] = "1";
                    if ((k + 1) <= 7 && white_board[i][k + 1] != "X" && white_board[i][k + 1] != "O")
                        white_board[i][k + 1] = "1";
                    if ((i + 1 <= 7) && (k + 1 <= 7) && white_board[i + 1][k + 1] != "X" && white_board[i + 1][k + 1] != "O")
                        white_board[i + 1][k + 1] = "1";
                    if ((i + 1 <= 7) && white_board[i + 1][k] != "X" && white_board[i + 1][k] != "O")
                        white_board[i + 1][k] = "1";
                    if ((i + 1 <= 7) && (k - 1 >= 0) && white_board[i + 1][k - 1] != "X" && white_board[i + 1][k - 1] != "O")
                        white_board[i + 1][k - 1] = "1";
                    if ((k - 1 >= 0) && white_board[i][k - 1] != "X" && white_board[i][k - 1] != "O")
                        white_board[i][k - 1] = "1";
                    if ((i - 1 >= 0) && (k - 1 >= 0) && white_board[i - 1][k - 1] != "X" && white_board[i - 1][k - 1] != "O")
                        white_board[i - 1][k - 1] = "1";
                }
            }
        }

        for (int i = 0; i < 8; i++) {

            for (int k = 0; k < 8; k++) {
                if (white_board[i][k] == "1") {
                    if ((i - 1 >= 0) && white_board[i - 1][k] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i - 1, k, -1, 0);
                    }
                    if ((i - 1 >= 0) && (k + 1 <= 7) && white_board[i - 1][k + 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i - 1, k + 1, -1, 1);
                    }
                    if ((k + 1) <= 7 && white_board[i][k + 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i, k + 1, 0, 1);
                    }
                    if ((i + 1 <= 7) && (k + 1 <= 7) && white_board[i + 1][k + 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i + 1, k + 1, 1, 1);
                    }
                    if ((i + 1 <= 7) && white_board[i + 1][k] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i + 1, k, 1, 0);
                    }
                    if ((i + 1 <= 7) && (k - 1 >= 0) && white_board[i + 1][k - 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i + 1, k - 1, 1, -1);
                    }
                    if ((k - 1 >= 0) && white_board[i][k - 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i, k - 1, 0, -1);
                    }
                    if ((i - 1 >= 0) && (k - 1 >= 0) && white_board[i - 1][k - 1] == "X") {
                        finalizeWhiteMoves(isChecked, white_board, i - 1, k - 1, -1, -1);
                    }
                }
            }
        }

        return white_board;

    }

    /*
     * checkPossibleBlackMoves method puts '1' to all
     * squares which are neighbor of white squares.
     * We are putting '1' because later all '1's will
     * be checked for game rules.
     * We need this method since we can not move any
     * random square in the board according to game
     * rules. In other words, in each turn we should
     * move legally.
     * */

    public String[][] checkPossibleBlackMoves(String[][] game_board) {

        String[][] black_board = new String[8][8];

        for (int i = 0; i < 8; i++)
            for (int k = 0; k < 8; k++)
                black_board[i][k] = game_board[i][k];

        Boolean[][] isChecked = new Boolean[8][8];
        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                isChecked[i][k] = false;
            }
        }

        for (int i = 0; i < 8; i++) {

            for (int k = 0; k < 8; k++) {
                if (black_board[i][k] == "O") {
                    if ((i - 1 >= 0) && black_board[i - 1][k] != "X" && black_board[i - 1][k] != "O")  // if that square includes a point.
                        black_board[i - 1][k] = "1";
                    if ((i - 1 >= 0) && (k + 1 <= 7) && black_board[i - 1][k + 1] != "X" && black_board[i - 1][k + 1] != "O")
                        black_board[i - 1][k + 1] = "1";
                    if ((k + 1) <= 7 && black_board[i][k + 1] != "X" && black_board[i][k + 1] != "O")
                        black_board[i][k + 1] = "1";
                    if ((i + 1 <= 7) && (k + 1 <= 7) && black_board[i + 1][k + 1] != "X" && black_board[i + 1][k + 1] != "O")
                        black_board[i + 1][k + 1] = "1";
                    if ((i + 1 <= 7) && black_board[i + 1][k] != "X" && black_board[i + 1][k] != "O")
                        black_board[i + 1][k] = "1";
                    if ((i + 1 <= 7) && (k - 1 >= 0) && black_board[i + 1][k - 1] != "X" && black_board[i + 1][k - 1] != "O")
                        black_board[i + 1][k - 1] = "1";
                    if ((k - 1 >= 0) && black_board[i][k - 1] != "X" && black_board[i][k - 1] != "O")
                        black_board[i][k - 1] = "1";
                    if ((i - 1 >= 0) && (k - 1 >= 0) && black_board[i - 1][k - 1] != "X" && black_board[i - 1][k - 1] != "O")
                        black_board[i - 1][k - 1] = "1";
                }
            }
        }

        for (int i = 0; i < 8; i++) {

            for (int k = 0; k < 8; k++) {
                if (black_board[i][k] == "1") {      // for checking whether we can really put 1 or not
                    if ((i - 1 >= 0) && black_board[i - 1][k] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i - 1, k, -1, 0); // -1 = i-1 - i, 0 = k-k
                    }
                    if ((i - 1 >= 0) && (k + 1 <= 7) && black_board[i - 1][k + 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i - 1, k + 1, -1, 1);
                    }
                    if ((k + 1) <= 7 && black_board[i][k + 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i, k + 1, 0, 1);
                    }
                    if ((i + 1 <= 7) && (k + 1 <= 7) && black_board[i + 1][k + 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i + 1, k + 1, 1, 1);
                    }
                    if ((i + 1 <= 7) && black_board[i + 1][k] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i + 1, k, 1, 0);
                    }
                    if ((i + 1 <= 7) && (k - 1 >= 0) && black_board[i + 1][k - 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i + 1, k - 1, 1, -1);
                    }
                    if ((k - 1 >= 0) && black_board[i][k - 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i, k - 1, 0, -1);
                    }
                    if ((i - 1 >= 0) && (k - 1 >= 0) && black_board[i - 1][k - 1] == "O") {
                        finalizeBlackMoves(isChecked, black_board, i - 1, k - 1, -1, -1);
                    }
                }
            }
        }

        return black_board;

    }

    /*
     * finalizeWhiteMoves method reduces the unnecessary '1' s
     * that were put in checkPossibleWhiteMoves. Finally, we are
     * replacing '1' s which are located in playable squares with '*'.
     * Before a user move, he or she can choose squares having '*'.
     * */

    public void finalizeWhiteMoves(Boolean[][] isChecked, String[][] board, int current_row, int current_column, int r, int c) { // r = row_step, c = column_step
        int row_counter = current_row + r;
        int column_counter = current_column + c;
        int actual_row = current_row - r;
        int actual_column = current_column - c;

        while (row_counter <= 8 && column_counter <= 8 && row_counter >= -1 && column_counter >= -1 && isChecked[actual_row][actual_column] == false) {

            if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                if (board[row_counter][column_counter] == "O") {
                    board[actual_row][actual_column] = "*";
                    isChecked[actual_row][actual_column] = true;
                    break;
                } else if ((board[row_counter][column_counter] == "*" || board[row_counter][column_counter] == "." || board[row_counter][column_counter] == "1")) {
                    board[actual_row][actual_column] = ".";
                    break;
                }
            } else
                board[actual_row][actual_column] = ".";

            row_counter += r;
            column_counter += c;

        }

    }

    /*
     * finalizeBlackMoves method reduces the unnecessary '1' s
     * that were put in checkPossibleBlackMoves. Finally, we are
     * replacing '1' s which are located in playable squares with '*'.
     * Before a user move, he or she can choose squares having '*'.
     * */

    public void finalizeBlackMoves(Boolean[][] isChecked, String[][] board, int current_row, int current_column, int r, int c) { // r = row_step, c = column_step
        int row_counter = current_row + r;
        int column_counter = current_column + c;
        int actual_row = current_row - r;
        int actual_column = current_column - c;

        while (row_counter <= 8 && column_counter <= 8 && row_counter >= -1 && column_counter >= -1 && isChecked[actual_row][actual_column] == false) {

            if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                if (board[row_counter][column_counter] == "X") {
                    board[actual_row][actual_column] = "*";
                    isChecked[actual_row][actual_column] = true;
                    break;
                } else if ((board[row_counter][column_counter] == "*" || board[row_counter][column_counter] == "." || board[row_counter][column_counter] == "1")) {
                    board[actual_row][actual_column] = ".";
                    break;
                }
            } else
                board[actual_row][actual_column] = ".";

            row_counter += r;
            column_counter += c;

        }

    }

    /*
     * makeNodesWhite method updates the board after white player
     * move. The color of black squares which are between white
     * squares change into white.
     * */

    public void makeNodesWhite(String[][] game_board, int row, int column) {

        String[][] white_movement = new String[8][8];
        int check = 1;

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++)
                white_movement[i][k] = game_board[i][k];
        }

        int row_step, column_step, row_counter, column_counter;

        if (row - 1 >= 0 && column - 1 >= 0 && game_board[row - 1][column - 1] == "X")
            white_movement[row - 1][column - 1] = "1";
        if (row - 1 >= 0 && game_board[row - 1][column] == "X")
            white_movement[row - 1][column] = "1";
        if (row - 1 >= 0 && column + 1 <= 7 && game_board[row - 1][column + 1] == "X")
            white_movement[row - 1][column + 1] = "1";
        if (column + 1 <= 7 && game_board[row][column + 1] == "X")
            white_movement[row][column + 1] = "1";
        if (row + 1 <= 7 && column + 1 <= 7 && game_board[row + 1][column + 1] == "X")
            white_movement[row + 1][column + 1] = "1";
        if (row + 1 <= 7 && game_board[row + 1][column] == "X")
            white_movement[row + 1][column] = "1";
        if (row + 1 <= 7 && column - 1 >= 0 && game_board[row + 1][column - 1] == "X")
            white_movement[row + 1][column - 1] = "1";
        if (column - 1 >= 0 && game_board[row][column - 1] == "X")
            white_movement[row][column - 1] = "1";


        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                if (white_movement[i][k] == "1") {

                    check = 1;
                    row_step = i - row;
                    column_step = k - column;
                    row_counter = i + row_step;
                    column_counter = k + column_step;

                    while (check > 0) {
                        if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                            if (white_movement[row_counter][column_counter] == "O")
                                break;
                            else if (white_movement[row_counter][column_counter] == ".")
                                check *= 0;
                            row_counter += row_step;
                            column_counter += column_step;

                        } else
                            check = 0;
                    }

                    row_step = i - row;
                    column_step = k - column;
                    row_counter = i;
                    column_counter = k;


                    while (row_counter <= 8 && column_counter <= 8 && row_counter >= -1 && column_counter >= -1 && check > 0) {
                        if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                            if (game_board[row_counter][column_counter] == "X") {
                                game_board[row_counter][column_counter] = "O";
                            } else
                                break;
                        }
                        row_counter += row_step;
                        column_counter += column_step;

                    }
                }
            }
        }
    }

    /*
     * makeNodesBlack method updates the board after black player
     * move. The color of white squares which are between black
     * squares change into black.
     * */

    public void makeNodesBlack(String[][] game_board, int row, int column) {

        String[][] black_movement = new String[8][8];
        int check = 1;

        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++)
                black_movement[i][k] = game_board[i][k];
        }

        int row_step, column_step, row_counter, column_counter;

        if (row - 1 >= 0 && column - 1 >= 0 && game_board[row - 1][column - 1] == "O")
            black_movement[row - 1][column - 1] = "1";
        if (row - 1 >= 0 && game_board[row - 1][column] == "O")
            black_movement[row - 1][column] = "1";
        if (row - 1 >= 0 && column + 1 <= 7 && game_board[row - 1][column + 1] == "O")
            black_movement[row - 1][column + 1] = "1";
        if (column + 1 <= 7 && game_board[row][column + 1] == "O")
            black_movement[row][column + 1] = "1";
        if (row + 1 <= 7 && column + 1 <= 7 && game_board[row + 1][column + 1] == "O")
            black_movement[row + 1][column + 1] = "1";
        if (row + 1 <= 7 && game_board[row + 1][column] == "O")
            black_movement[row + 1][column] = "1";
        if (row + 1 <= 7 && column - 1 >= 0 && game_board[row + 1][column - 1] == "O")
            black_movement[row + 1][column - 1] = "1";
        if (column - 1 >= 0 && game_board[row][column - 1] == "O")
            black_movement[row][column - 1] = "1";


        for (int i = 0; i < 8; i++) {
            for (int k = 0; k < 8; k++) {
                if (black_movement[i][k] == "1") {

                    check = 1;
                    row_step = i - row;
                    column_step = k - column;
                    row_counter = i;
                    column_counter = k;

                    while (check > 0) {
                        if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                            if (black_movement[row_counter][column_counter] == "X")
                                break;
                            else if (black_movement[row_counter][column_counter] == ".")
                                check *= 0;
                            row_counter += row_step;
                            column_counter += column_step;
                        } else
                            check = 0;
                    }

                    row_step = i - row;
                    column_step = k - column;
                    row_counter = i;
                    column_counter = k;


                    while (row_counter <= 8 && column_counter <= 8 && row_counter >= -1 && column_counter >= -1 && check > 0) {
                        if (row_counter <= 7 && column_counter <= 7 && row_counter >= 0 && column_counter >= 0) {
                            if (game_board[row_counter][column_counter] == "O") {
                                game_board[row_counter][column_counter] = "X";
                            } else
                                break;
                        }
                        row_counter += row_step;
                        column_counter += column_step;

                    }
                }
            }
        }
    }
}
