import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> days = new LinkedList<>();
        
        for(int i=0; i<progresses.length; i++){
            int remain = 100-progresses[i];
            int day = remain/speeds[i];
            
            if(remain%speeds[i]!=0)
                day++;
          
            days.offer(day);
        }
        
        List<Integer> result = new ArrayList<>();
        
        while(!days.isEmpty()){
            int current = days.poll();
            int cnt = 1;
            
            while(!days.isEmpty() && days.peek()<=current){
                days.poll();
                cnt++;
            }
            
            result.add(cnt);
        }
        
        return result.stream()
            .mapToInt(i -> i)
            .toArray();
    }
}