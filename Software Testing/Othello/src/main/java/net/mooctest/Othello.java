package net.mooctest;
import java.util.ArrayList;
import java.util.Random;


public class Othello {
	
	/*
	 * strategyOfBlackMove method is a combination of some strategies
	 * used in playing Othello. We have combined evaporation, mobility,
	 * corner, stability strategies.
	 * (http://radagast.se/othello/Help/strategy.html)
	 * Also we have created evaluation board with heuristic values of 
	 * these strategies.
	 * In some cases, we can have more than one square which has best
	 * evaluation value. We added randomness so that the result will 
	 * not be same at the end of the game. 
	 * */
	
	public ArrayList<Integer> strategyOfBlackMove(String[][] black_board, String[][] game_board){

		int[][] evaluation_board = {{120, -20,  20,   5,   5,  20, -20, 120,},
									{-20, -40,  -5,  -5,  -5,  -5, -40, -20,},
									{20,  -5,  15,   3,   3,  15,  -5,  20,},
									{5,  -5,   3,   3,   3,   3,  -5,   5,},
									{5,  -5,   3,   3,   3,   3,  -5,   5,},
									{20,  -5,  15,   3,   3,  15,  -5,  20,},
									{-20, -40,  -5,  -5,  -5,  -5, -40, -20,},
									{120, -20,  20,   5,   5,  20, -20, 120}};
		
		int[][] temp_evaluation_board = new int[8][8];
				
		Board b = new Board();
		int black_counter = 0;
		int white_counter = 0;
		int evaluate = -1000;
		int same_counter = 0;
		ArrayList<Integer> row_array = new ArrayList<Integer>();
		ArrayList<Integer> column_array = new ArrayList<Integer>();
		ArrayList<Integer> row_column = new ArrayList<Integer>();
		
		ArrayList<Integer> same_row = new ArrayList<Integer>();
		ArrayList<Integer> same_column = new ArrayList<Integer>();

		String[][] temp_game_board = new String[8][8];
		String[][] temp_white_board = new String[8][8];
		
		for (int i = 0; i < 8; i++){
			for (int k = 0; k < 8; k++){
				if (black_board[i][k] == "*"){
					black_counter ++;
					row_array.add(i);
					column_array.add(k);
				}
			}
		}
		
		for (int a = 0; a < black_counter; a++){
			
			white_counter = 0;
			
			for (int i = 0; i < 8; i++){
				for (int k = 0; k < 8; k++)
					temp_game_board[i][k] = game_board[i][k];
			}
			temp_game_board[row_array.get(a)][column_array.get(a)] = "X";
			b.makeNodesBlack(temp_game_board, row_array.get(a), column_array.get(a));
			temp_white_board = b.checkPossibleWhiteMoves(temp_game_board);
			
			for (int i = 0; i < 8; i++){
				for (int k = 0; k < 8; k++){
					if (temp_white_board[i][k] == "*"){
						white_counter ++;
					}
				}
			}

			evaluation_board[row_array.get(a)][column_array.get(a)] = evaluation_board[row_array.get(a)][column_array.get(a)] - white_counter;
			
			temp_evaluation_board[row_array.get(a)][column_array.get(a)] = evaluation_board[row_array.get(a)][column_array.get(a)];

			if (evaluation_board[row_array.get(a)][column_array.get(a)] > evaluate){
				evaluate = evaluation_board[row_array.get(a)][column_array.get(a)];
				
				row_column.add(0, row_array.get(a));
				row_column.add(1, column_array.get(a));
			}
			
			/*System.out.println("    0   1   2   3   4   5   6   7");
			for (int i = 0; i < 8; i++){
				System.out.print(i);
				System.out.print(" ");
				for (int k = 0; k < 8; k++)
					System.out.printf("%3d ", evaluation_board[i][k]);
				System.out.println();
			}
			System.out.println();*/

		}
		
		for (int a = 0; a < black_counter; a++){
			
			if (temp_evaluation_board[row_array.get(a)][column_array.get(a)] == evaluate){
				same_row.add(0, row_array.get(a));
				same_column.add(0, column_array.get(a));
				same_counter ++;
			}
			
		}
				
		if (same_counter != 1){
			Random rand = new Random();
	
			int n = rand.nextInt(same_counter);
			
			row_column.add(0, same_row.get(n));
			row_column.add(1, same_column.get(n));
		}
		
		
		return row_column;
		
	}	

}
