import java.util.*;

public class Eight_Queen_Real_BFS {
		static Queue<Integer[][]> q = new LinkedList<Integer[][]>();
		
		public static void print(Integer[][] board) {
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					System.out.print(board[i][j] + " ");
				}
				System.out.println();
			}
		}
		
		public static boolean check(Integer board[][]) {
			int total_queens = 0;
			for(int i = 0; i < 8; i++) {
				for(int j = 0; j < 8; j++) {
					//row
					if(board[i][j] == 1) {
						total_queens++;
						for(int k = 0; k < 8; k++) {
							if(board[i][k] == 1 && k != j) {
								return false;
							}
						}
						//column
						for(int k = 0; k < 8; k++) {
							if(board[k][j] == 1 && k != i) {
								return false;
							}
						}
						//diagonal\
						int t1i = i, t1j = j;
						while(t1i + 1 < 8 && t1j + 1< 8) {
							if(board[t1i + 1][t1j + 1] == 1) {
								return false;
							}
							t1i++;
							t1j++;
						}
						t1i = i;
						t1j = j;
						while(t1i - 1 >= 0 && t1j - 1 >=  0) {
							if(board[t1i - 1][t1j - 1] == 1) {
								return false;
							}
							t1i--;
							t1j--;
						}
						//diagonal/
						t1i = i;
						t1j = j;
						while(t1i + 1 < 8 && t1j - 1 >=  0) {
							if(board[t1i + 1][t1j - 1] == 1) {
								return false;
							}
							t1i++;
							t1j--;
						}
						t1i = i;
						t1j = j;
						while(t1i - 1 >= 8 && t1j + 1 < 8) {
							if(board[t1i - 1][t1j + 1] == 1) {
								return false;
							}
							t1i--;
							t1j++;
						}
						
					}
			
				}
			}

			return true && total_queens == 8; 
		}
		
		
		public static boolean bfs() {
			Integer[][] t = new Integer[8][8], temp = new Integer[8][8];
			for(int j = 0; j < 8; j++) {
				for(int k = 0; k < 8; k++) {
					t[j][k] = 0;
				}
			}
			q.add(t);
			int col = 0;
			while(!q.isEmpty()) {
				int size = q.size();
				while(size-- > 0) {
						temp = q.remove();
					
					for(int i = 0; i < 8; i++) {
						Integer[][] temp1 = new Integer[8][8];
						for(int j = 0; j < 8; j++) {
							for(int k = 0; k < 8; k++) {
								temp1[j][k] = temp[j][k];
							}
						}
						temp1[i][col] = 1;
						if(check(temp1)) {
							print(temp1);
							return true;
						}
						q.add(temp1);
					}
				}
				col++;
			}
			return false;
		}
		
		public static void main(String args[]) {
			Integer arr[][] = new Integer[8][8];
			if(!bfs()) {
				System.out.println("No Solution Found");
			}
		}
}
