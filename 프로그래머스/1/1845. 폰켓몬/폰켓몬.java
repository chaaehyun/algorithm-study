import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i : nums){
            map.put(i, map.getOrDefault(i,0)+1);
        }
        
        if(nums.length/2 <= map.size())
            answer = nums.length/2;
        else {
            answer = map.size();
        }
        
        return answer;
    }
}