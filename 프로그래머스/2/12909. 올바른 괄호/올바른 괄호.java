import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            
            if(stack.isEmpty() && c==')')
                return false;
            else if(c=='(')
                stack.push(c);
            else
                stack.pop();
        }
        
        if(!stack.isEmpty())
            return false;

        return true;
    }
}