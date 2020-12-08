class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        if(n < 1) return answer;
        generate_parenthesis(answer, "", 0, 0, n);
        return answer;
    }
    void generate_parenthesis(vector<string>& answer, string current_parenthesis, int num_open, int num_close, int max_number){
        if(current_parenthesis.length() == max_number * 2){
            answer.push_back(current_parenthesis);
            return;
        }
        if(num_open < max_number){
            generate_parenthesis(answer, current_parenthesis + "(", num_open + 1, num_close, max_number);
        }
        if(num_close < num_open){
            generate_parenthesis(answer, current_parenthesis + ")", num_open, num_close + 1, max_number);
        }
        
    }
};