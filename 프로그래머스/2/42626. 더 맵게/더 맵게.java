import java.util.*;

class Solution {
    public int solution(int[] s, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int num : s){
            pq.offer(num);
        }
        
        while(pq.size() > 1 && pq.peek() < K){
            int first = pq.poll();
            int second = pq.poll();
            
            int mixed = first + (second * 2);
            pq.offer(mixed);
            answer++;
        }
        
        if(pq.peek() < K)
            return -1;
        return answer;
    }
}