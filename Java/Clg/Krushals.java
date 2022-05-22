import java.util.*;

class Node{
    private int U,V,W;
       
    Node(int u,int v,int w){
        U = u;
        V = v;
        W = w;
    }
        
    INT GETU() {return U;}
    INT GETV() {return V;}
    INT GETW() {return W;}
}

class SortComparator implements Comparator<Node>{
    @Override
    
    public int compare(Node n1, Node n2){
        if (n1.getW() < n2.getW()) {
            return -1;
        }
        else if (n1.getW() > n2.getW()) {
            return 1;
        }
        else {
            return 0;
        }
    }
}   

public class Main
{
    int findPar (int node, int parent[]) {
        if (parent[node] == node) {
            return node;
        } 
        return parent[node] = findPar(parent[node], parent);
    }
    
    void union (int u, int v, int parent[], int rank[]) {
        u = findPar(u,parent);
        v = findPar(v,parent);
        
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[v] > rank[u]) {
            parent[v] = u;
        }
        else {
            parent[u] = v;
            rank[v]++;
        }
        
    }

    void KruskalAlgo (ArrayList<Node> Graph, int num_vertices) {

        Collections.sort(Graph, new SortComparator());
        int[] parent = new int[num_vertices];
        int[] rank = new int[num_vertices];
        
        for (int i=0;i<num_vertices;i++) {
            parent[i] = i;
            rank[i] = 0; 
        }
        
        int cost_mst = 0;
        
        ArrayList<Node> mst = new ArrayList<Node>();
        
        for (Node it: Graph) {
            
            if (findPar(it.getU(), parent) != findPar(it.getV(), parent)) {
                cost_mst +=it.getW();
                mst.add(it);
                union(it.getU(), it.getV(), parent, rank);
            }
        }
        
        System.out.println("\n| Minnimum Spannig Tree Cost => " + cost_mst + " |");
        System.out.println("Minnimum Spanning Tree -> ");
        
        for (Node it: mst) {
            System.out.println("\t( " + it.getU() + " " + it.getV() + " ) = " + it.getW());
        }
        
    }

	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    
	    System.out.println("<o> <o> Krushals Algorithm <o> <o>");
	    System.out.println("\n===[ ENTER VERTICES TO BE 0 BASED INDEXED ]===\n");
	    
	    int num_vertices, num_edges;
	    System.out.print("\nTotal Number of vertices: ");
	    num_vertices = sc.nextInt();
	    System.out.print("\nTotal Number of edges: ");
	    num_edges = sc.nextInt();
	    
	    ArrayList<Node> Graph = new ArrayList<Node>();
	    
	    int u,v,w;
	    for (int i=0;i<num_edges;i++) {
	        System.out.print("\nSource Node: ");
	        u = sc.nextInt();
	        System.out.print("Destination node: ");
	        v = sc.nextInt();
	        System.out.print("Edge weight: ");
	        w = sc.nextInt();
	        
	        Graph.add(new Node(u,v,w));
	    }
	    
	    Main obj = new Main();
	    obj.KruskalAlgo(Graph, num_vertices);
	    
	    System.out.print("\n\t[ Program End ]");
	}
}



