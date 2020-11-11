package net.mooctest;



public class AlphaBetaPruning {

	/*
	 * createAlphaBetaTree method is created for Alpha-Beta
	 * Pruning Algorithm. 
	 * */
	
	public String createAlphaBetaTree(String[][] game_board, String[][] white_board, String[][] black_board, MyTreeNode<String> root){
		
		Board b = new Board();
		String[][] temp_game_board = new String[8][8];
		String[][] temp2_game_board = new String[8][8];
		String[][] temp_black_board = new String[8][8];
		String value = "";
		MyTreeNode<String> child1 = null;
		MyTreeNode<String> child2 = null;
		int score = 0;
		String result = "";
		
		for (int i = 0; i < 8; i++){
			for (int k = 0; k < 8; k++){
				if (white_board[i][k] == "*"){
					value = String.valueOf(i) + "," + String.valueOf(k);
					child1 = new MyTreeNode<String>(value);
					root.addChild(child1);
					
					resetBoard(game_board, temp_game_board);
					resetBoard(black_board, temp_black_board);
					
					temp_game_board[i][k] = "O";
					b.makeNodesWhite(temp_game_board, i, k);
					temp_black_board = b.checkPossibleBlackMoves(temp_game_board);

					for (int x = 0; x < 8; x++){
						for (int y = 0; y < 8; y++){
							if (temp_black_board[x][y] == "*"){
								value = String.valueOf(x) + "," + String.valueOf(y);
								child2 = new MyTreeNode<String>(value);
								child1.addChild(child2);

								resetBoard(temp_game_board, temp2_game_board);
								temp2_game_board[x][y] = "X";
								b.makeNodesBlack(temp2_game_board, x, y);
								score = calculateWhiteScore(temp2_game_board);
								child2.setValue(score);
							}
						}
					}
				}
			}
		}
		
		for(MyTreeNode<String> node : root.getChildren()) {
		    
		    for(MyTreeNode<String> node2 : node.getChildren()){
		    	node.setAlpha(root.getAlpha());
		    	if (node2.getValue() < node.getBeta()){
		    		node.setBeta(node2.getValue());
		    	}
		    	if(node.getBeta() <= node.getBeta()){
		    		break;												// prune nodes condition
		    	}
		    }
		    
		    if (root.getAlpha() < node.getBeta())
		    	root.setAlpha(node.getBeta());
		    node.setValue(node.getBeta());
		}	
		
	    root.setValue(root.getAlpha());

		for(MyTreeNode<String> node : root.getChildren()) {
			if(root.getValue() == node.getValue()){
				System.out.println("Next move of White : " + node.getData());
				result = node.getData();
				break;
			}
		}
		return result;
	    /*System.out.println("root value : " + root.getValue());
	    System.out.println("root alpha : " + root.getAlpha());
	    System.out.println("root beta : " + root.getBeta());

		for(MyTreeNode<String> node : root.getChildren()) {
		    System.out.println("	node value : " + node.getValue());
		    System.out.println("	node alpha : " + node.getAlpha());
		    System.out.println("	node beta : " + node.getBeta());
		    
		    for(MyTreeNode<String> node2 : node.getChildren()){
			    System.out.println("		node2 value : " + node2.getValue());
			    System.out.println("		node2 alpha : " + node2.getAlpha());
			    System.out.println("		node2beta : " + node2.getBeta());
		    }
		}*/
		
	}
	
	
	/*
	 * resetBoard method is used for resetting the relevant board
	 * for previous state.
	 * */
	
	public void resetBoard(String[][] game_board, String[][] current_game_board){
		for (int i = 0; i < 8; i++){
			for (int k = 0; k < 8; k++)
				current_game_board[i][k] = game_board[i][k];
		}
	}
	
	/*
	 * calculateWhiteScore method calculates the current difference
	 * between white score and black score. This difference is used
	 * in Alpha-Beta Pruning Algorithm.
	 * */
	
	public int calculateWhiteScore(String[][] game_board){
		int white_score = 0;
		int black_score = 0;
		
		for (int i = 0; i < 8; i++){
			for (int k = 0; k < 8; k++){
				if (game_board[i][k] == "O")
					white_score ++;
				if (game_board[i][k] == "X")
					black_score ++;	
			}
		}
		
		return white_score - black_score;
	}
	
}
