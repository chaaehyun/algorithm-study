import java.util.*;

class Solution {
    public int solution(int[] p, int l) {
        Queue<Map.Entry<Integer, Integer>> queue = new LinkedList<>();
        int cnt=0;
        
        for(int i=0; i<p.length; i++){
            queue.offer(new AbstractMap.SimpleEntry<>(i, p[i]));
        }
        
        while(!queue.isEmpty()){
            Map.Entry<Integer, Integer> current = queue.poll();
            int currentPriority = current.getValue();
            int currentIndex = current.getKey();
            
            boolean isHigher = true;
            for(Map.Entry<Integer, Integer> entry : queue){
                if(entry.getValue()>currentPriority){
                    queue.offer(current);
                    isHigher=false;
                    break;
                }
            }
            
            if(isHigher == true){
                cnt++;
                if(currentIndex == l)
                    return cnt;
            }
        }
        
        return -1;
    }
}