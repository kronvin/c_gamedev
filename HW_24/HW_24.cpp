// HW_24.cpp 

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <sstream>

unsigned int uniqueWordsCount(const std::string& line)
{
    std::unordered_set<std::string> uniqueWords;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) 
    {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}


std::string mostOccuredWord(const std::string& line)
{
    std::unordered_map<std::string, int> wordCount;
    std::istringstream iss(line);
    std::string word;
    std::string mostOccured;
    int maxCount = 0;

    while (iss >> word)
    {
        wordCount[word]++;
        if (wordCount[word] > maxCount) 
        {
            maxCount = wordCount[word];
            mostOccured = word;
        }
    }

    return mostOccured;
};

bool BracketsAreClosed(const std::string& line)
{
    std::stack<char> s;
    std::unordered_map<char, char> pairs = { {')', '('}, {']', '['}, {'}', '{'} };

    for (char c : line) 
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (s.empty() || s.top() != pairs[c]) 
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
};


struct Node 
{
    int data;
    Node* next;
};


bool HasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) 
        {
            return true;
        }
    }
    return false;
};

int main()
{
    std::string list = "Hello Hey Hello Bye Hey Hello";
    std::cout << "Unique words count: " << uniqueWordsCount(list) << std::endl;
    std::cout << "Most occurred word: " << mostOccuredWord(list) << std::endl;

    std::string FirstSetOfBrackets = "{[()]}";
    std::cout << "Brackets balanced: " << (BracketsAreClosed(FirstSetOfBrackets) ? "Balanced" : "Not balanced") << std::endl;

    std::string SecondSetOfBrackets = "{[)}])";
    std::cout << "Brackets balanced: " << (BracketsAreClosed(SecondSetOfBrackets) ? "Balanced" : "Not balanced") << std::endl;

    Node* head = new Node{ 1, nullptr };
    Node* second = new Node{ 2, nullptr };
    Node* third = new Node{ 3, nullptr };
    head->next = second;
    second->next = third;
    third->next = head;

    std::cout << "First list has cycle: " << (HasCycle(head) ? "True" : "False") << std::endl;

    Node* headTwo = new Node{ 1, nullptr };
    Node* secondTwo = new Node{ 2, nullptr };
    Node* thirdTwo = new Node{ 3, nullptr };
    headTwo->next = secondTwo;
    secondTwo->next = thirdTwo;
    thirdTwo->next = nullptr;

    std::cout << "Second list has cycle: " << (HasCycle(headTwo) ? "True" : "False") << std::endl;

    return 0;
}
