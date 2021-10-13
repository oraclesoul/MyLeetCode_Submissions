class Solution {
public:
    string interpret(string command) {
        string result;
        for(int i = 0; i < command.length(); i++)
        {
            if(command[i] == 'G')
                result.push_back('G');
            else
            {
                if(command[i + 1] == ')')
                    result.push_back('o'), i += 1;
                else
                {
                    result += "al";
                    i += 3;
                }
            }
        }
        return result;
    }
};