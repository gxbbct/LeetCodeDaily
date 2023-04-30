#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

class DinnerPlates
{
public:
    DinnerPlates(int capacity)
    {
        this->capacity = capacity;
    }

    void push(int val)
    {
        if (notFull.empty())
        {
            stacks.emplace_back(stack<int>());
            stacks.back().push(val);
            if (capacity > 1)
            {
                notFull.insert(stacks.size() - 1);
            }
        }
        else
        {
            int index = *notFull.begin();
            stacks[index].push(val);
            if (stacks[index].size() == capacity)
            {
                notFull.erase(index);
            }
        }
    }

    int pop()
    {
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index)
    {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
        {
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        if (index == stacks.size() - 1 && stacks[index].empty())
        {
            while (!stacks.empty() && stacks.back().empty())
            {
                notFull.erase(stacks.size() - 1);
                stacks.pop_back();
            }
        }
        else
        {
            notFull.insert(index);
        }
        return val;
    }

private:
    int capacity;
    vector<stack<int>> stacks;
    set<int> notFull;
};

int main()
{
    DinnerPlates *obj = new DinnerPlates(2);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    cout << obj->popAtStack(0) << endl;
    obj->push(20);
    obj->push(21);
    cout << obj->popAtStack(0) << endl;
    cout << obj->popAtStack(2) << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
}