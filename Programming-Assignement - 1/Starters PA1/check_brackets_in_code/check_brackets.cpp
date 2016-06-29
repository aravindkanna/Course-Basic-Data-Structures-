#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    stack<char> opening_bracket;
    stack<int> position;

    for(int i = 0;i < text.length();i++){
        if(text[i] == '('){
            opening_bracket.push(text[i]);
            position.push(i + 1);
        }
        else if(text[i] == '{'){
            opening_bracket.push(text[i]);
            position.push(i + 1);
        }
        else if(text[i] == '['){
            opening_bracket.push(text[i]);
            position.push(i + 1);
        }
        else if(text[i] == ')'){
            if(opening_bracket.empty() || opening_bracket.top() != '('){
                cout << i + 1 << endl;
                return 0;
            }
            else{
                opening_bracket.pop();
                position.pop();
            }
        }
        else if(text[i] == '}'){
            if(opening_bracket.empty() || opening_bracket.top() != '{'){
                cout << i + 1 << endl;
                return 0;
            }
            else{
                opening_bracket.pop();
                position.pop();
            }
        }
        else if(text[i] == ']'){
            if(opening_bracket.empty() || opening_bracket.top() != '['){
                cout << i + 1 << endl;
                return 0;
            }
            else{
                opening_bracket.pop();
                position.pop();
            }
        }
    }

    if(!opening_bracket.empty()){
        int pos = 0;
        while(!position.empty()){
            pos = position.top();
            position.pop();
        }
        cout << pos << endl;
    }
    else{
        cout << "Success" << endl;
    }

    return 0;
}
