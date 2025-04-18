import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Stack<Integer> stack = new Stack<>(); //큐와 달리 stack 형이 있음
        
        for(int num : arr){
            if(stack.isEmpty() || stack.peek() != num)
                stack.push(num);
        }
        
        int []answer = new int[stack.size()];
        for(int i=stack.size()-1; i>=0; i--){
            answer[i] = stack.pop();
        }

        return answer;
    }
}