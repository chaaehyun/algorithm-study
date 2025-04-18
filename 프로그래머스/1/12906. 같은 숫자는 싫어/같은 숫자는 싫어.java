import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Queue<Integer> queue = new LinkedList<>(); //큐는 LinkedList 형태임
        
        if(arr.length != 0){
            int prev = arr[0];
            queue.offer(prev); //큐에 값 넣기
            
            for(int i=1; i<arr.length; i++){
                if(arr[i] != prev){
                    queue.offer(arr[i]);
                    prev = arr[i];
                }
            }
        }
        
        int i = 0;
        int[] answer = new int[queue.size()];
        while(!queue.isEmpty()){
            answer[i++] = queue.poll(); //C++과 다른 점, i++과 ++i의 차이
        }

        return answer;
    }
}