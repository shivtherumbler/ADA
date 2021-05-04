import java.util.Arrays;

class PGraph {

  public void Prim(int G[][], int V) {

    int INFINITY = 9999999;

    int edge_no; 

    boolean[] vertex = new boolean[V];

    Arrays.fill(vertex, false);

    edge_no = 0;

    vertex[0] = true;

    System.out.println("Edge : Weight");
    int sum=0;
    while (edge_no < V - 1) {

      int min = INFINITY;
      int x = 0; 
      int y = 0;
      
      for (int i = 0; i < V; i++) {
        if (vertex[i] == true) {
          for (int j = 0; j < V; j++) {
          
            if (!vertex[j] && G[i][j] != 0) {
              if (min > G[i][j]) {
                min = G[i][j];
                x = i;
                y = j;
              }
            }
          }
        }
      }
      System.out.println((char)(x+65) + " - " + (char)(y+65) + " :  " + G[x][y]);
      vertex[y] = true;
      edge_no++;
      sum= sum+ G[x][y];
    }
    System.out.println("Total Weight: "+sum);
  }

  public static void main(String[] args) {
    PGraph g = new PGraph();

    int V = 5;

    int[][] G = { { 0, 9, 5, 2, 0 }, { 9, 0, 0, 6, 5 }, { 5, 0, 0, 4, 5 }, { 2, 6, 4, 0, 4 },
        { 0, 5, 5, 4, 0 } };

    g.Prim(G, V);
  }
}