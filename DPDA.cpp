/*
    Semester Project
    By Aisha Jamal and Michalle Khan
    Theory of Computation
    CISC 4090
*/

#include <iostream>
#include <string>
#include <stack>
//#include <bits/stdc++.h> //- depending on which program you use, you may need to use <bits/stdc++.h>. You don't need this to run it in terminal, VScode, or Xcode.

using namespace std;

//This is the print function
void printStack(stack <char>);

//Function for all the rules
void rule1(string& state, int& step);
void rule2(string& state, int& step);
void rule3(string& state, int& step);
void rule4(string& state, int& step);
void rule5(string& state, int& step);
void rule6(string& state, int& step);
void rule7(string& state, int& step);
void rule8(string& state, int& step);

//Global Variables
stack<char> inputstack;
stack<char> sstack;
string inputstring;
int flag = 0;

int main()
{
    string state = "p"; //sets the input string with the default
    int step = 0;
    
    cout << "Enter in a string that is accepted by the context-free language L = {a^n b^n | n >= 0}" << endl;
    cout << "(Ex: write the string as (ab$, aabb$, etc.): ";
    
    cin >> inputstring;
    
    for (int j = 0; j < inputstring.length();j++) //determines if the input string is accepted by the program or not
    {
        if (inputstring[0] != 'a')
        {
            cout << "String rejected" << endl;;
            return 0;
        }
        
        else if (inputstring[j] != 'a')
        {
            if (inputstring[j] != 'b')
            {
                if (inputstring[j] != '$')
                {
                    cout << "String rejected" << endl;;
                    return 0;
                }
            }
        }
        
        else if (count(inputstring.begin(), inputstring.end(), 'a') != count(inputstring.begin(), inputstring.end(), 'b'))
        {
            cout << "String rejected" << endl;
            return 0;
        }
    }

    for (int i = inputstring.length()-1; i >= 0; i--) //Takes the input string and takes each character of the string at a time and pushes it on to a stack.
    {
        char test = inputstring.at(i);
        inputstack.push(test);
    };
    
    printStack(inputstack); //printing out the input string as a stack with each character as a separate input.
    
    cout << endl;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: e";
    cout << " | " << "Rule Used: -";
    cout << " | " << "R Used: -" << " | " << endl;
    
    while(!inputstack.empty()) //goes through this loop until the unread input string stack is empty.
    {

        if (state == "p")
            rule1(state, step);

        if (state == "q")
        {
            if (inputstack.top() == '$')
                rule6(state, step);

            else if (inputstack.top() == 'b')
                rule4(state, step);

            else
                rule2(state, step);
        }

        if (state == "qa")
        {
            if (sstack.top() == 'S')
                rule7(state, step);

            else
                rule3(state, step);
        }

        if (state == "qb")
        {
            if (sstack.top() == 'S')
                rule8(state, step);

            else
                rule5(state, step);
        }
    }
        return 0;
}

void printStack(stack <char> s) //prints the stack and prints e if the stack is empty.
{
    if (s.empty())
    {
        if (flag == 0)
        {
            cout << "e";
            return;
        }
        else
            return;
    }
    char x = s.top();
    s.pop();
    cout << x << " ";
    flag++;
    printStack(s);
    s.push(x);
}

void rule1(string& state, int& step)
{
    state = "q";
    sstack.push('S');
    flag=0;
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 1";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule2(string& state, int& step)
{
    state = "qa";
    flag=0;
    inputstack.pop();
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 2";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule3(string& state, int& step)
{
    state = "q";
    flag=0;
    sstack.pop();
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 3";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule4(string& state, int& step)
{
    state = "qb";
    flag=0;
    inputstack.pop();
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 4";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule5(string& state, int& step)
{
    state = "q";
    sstack.pop();
    step++;

    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    flag=0;
    printStack(inputstack);
    cout << " | " << "Stack: ";
    flag=0;
    printStack(sstack);
    cout << " | " << "Rule Used: 5";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule6(string& state, int& step)
{
    state = "q$";
    flag=0;
    inputstack.pop();
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 6";
    cout << " | " << "R Used: - " << " | " << endl;
}

void rule7(string& state, int& step)
{
    state = "qa";
    flag=0;
    sstack.pop();
    sstack.push('b');
    sstack.push('S');
    sstack.push('a');
    step++;
    
    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread Input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 7";
    cout << " | " << "R Used: S -> aSb" << " | " << endl;
}

void rule8(string& state, int& step)
{
    state = "qb";
    flag=0;
    sstack.pop();
    step++;

    cout<< "Step: " << step;
    cout << " | " << "State: " << state;
    cout << " | " << "Unread input: ";
    printStack(inputstack);
    cout << " | " << "Stack: ";
    printStack(sstack);
    cout << " | " << "Rule Used: 8";
    cout << " | " << "R Used: S -> e" << " | " << endl;
}

