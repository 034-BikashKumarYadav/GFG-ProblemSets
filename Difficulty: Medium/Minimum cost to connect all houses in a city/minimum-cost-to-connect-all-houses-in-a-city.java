//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int[][] edge = new int[n][2];
            for (int i = 0; i < n; i++) {
                edge[i][0] = sc.nextInt();
                edge[i][1] = sc.nextInt();
            }
            Solution obj = new Solution();
            int res = obj.minCost(edge);

            System.out.println(res);
            System.out.println("~");
        }
    }
}

// } Driver Code Ends



class Solution {
   public static class GraphEdge{
       public int source;
       public int destination;
       public int weight;
       
       public GraphEdge(int source, int destination, int weight)
       {
           this.source = source;
           this.destination = destination;
           this.weight = weight;
       }
       public int getSoruce(){
           return source;
       }
       
       public int getDestination(){
           return destination;
       }
       public int getWeight(){
           return weight;
       }
        
    }
    private int manHattan(int []p, int p2[]){
        return Math.abs(p[0]-p2[0]) + Math.abs(p[1]-p2[1]);
    }

    public int minCost(int[][] houses) {
        // code here
        int n = houses.length;
        boolean visited[] = new boolean[n];
        
        PriorityQueue<GraphEdge> pq = new PriorityQueue<>
        (Comparator.comparingInt(GraphEdge::getWeight));
        visited[0] = true;
        
        for(int i =1;i<n;i++){
            int minCost = manHattan(houses[0], houses[i]);
            pq.offer(new GraphEdge(0,i,minCost));
        }
        int totalWeight =0;
        
        while(!pq.isEmpty()){
            GraphEdge curr = pq.poll();
            int destination = curr.getDestination();
            if(visited[destination]==true) continue;
            
            visited[destination] = true;
            totalWeight += curr.getWeight();
            
            for(int i =0;i<n;i++){
                if(visited[i]!=true){
                    int cost = manHattan(houses[destination],houses[i]);
                    pq.offer(new GraphEdge(destination,i,cost));
                }
            }
        }
        
        return totalWeight;
        
    }
}