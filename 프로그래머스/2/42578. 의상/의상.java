import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        int sum = 0;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String[] c : clothes){
            String type = c[1];
            map.put(type, map.getOrDefault(type, 0)+1);
        }
        
       
        for(String key : map.keySet()){
            answer *= (map.get(key)+1);
        }
        answer--;
        
        return answer;
    }
}