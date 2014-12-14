/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack()
    {
        _head = NULL;
        _tail = NULL;
        _minHead = NULL;
        _minTail = NULL;
    }
    ~MinStack()
    {
        stackItem* cur = _head;
        stackItem* next;
        while (cur != NULL)
        {
            next = cur->points[pNext];
            delete cur;
            cur = next;
        }
    }
    void push(int x) {
        stackItem* item = new stackItem;
        item->value = x;
        if (_head == NULL)
        {
            _head = item;
            _tail = item;
            _minHead = item;
            _minTail = item;
            return;
        }
        insertNode(_tail, item, pPrev, pNext);
        _tail = item;
        stackItem* cur = _minHead;
        while(cur != NULL)
        {
            if (cur->value < x)
            {
                break;
            }
            cur = cur->points[pMinNext];
        }
        if (cur == _minHead)
        {
            _minHead->points[pMinPrev] = item;
            item->points[pMinNext] = _minHead;
            _minHead = item;
        }
        else if (cur == NULL)
        {
            _minTail->points[pMinNext] = item;
            item->points[pMinPrev] = _minTail;
            _minTail = item;
        }
        else
        {
            insertNode(cur->points[pMinPrev], item, pMinPrev, pMinNext);
        }
    }
    void pop() {
        removeFromTwoLinks(_tail);
    }
    int top() {
        if (_head == NULL)
        {
            return 0;
        }
        int x = _tail->value;
        removeFromTwoLinks(_tail);
        return x;
    }
    int getMin() {
        if (_head == NULL)
        {
            return 0;
        }
        int x = _minTail->value;
        removeFromTwoLinks(_minTail);
        return x;
    }
private:
    struct stackItem
    {
    public:
        int value;
        stackItem** points;
        stackItem()
        {
            points = new stackItem*[4]{NULL,NULL,NULL,NULL};
        }
        ~stackItem()
        {
            delete points;
        }
    };
    const int pPrev = 0;
    const int pNext = 1;
    const int pMinPrev = 2;
    const int pMinNext = 3;
    stackItem* _head;
    stackItem* _minHead;
    stackItem* _tail;
    stackItem* _minTail;

    void insertNode(stackItem* prev, stackItem* target, int prevPos, int nextPos)
    {
        target->points[nextPos] = prev->points[nextPos];
        target->points[prevPos] = prev;
        prev->points[nextPos] = target;
    }

    void removeNode(stackItem* target, int prevPos, int nextPos)
    {
        if (target->points[prevPos] != NULL)
        {
            target->points[prevPos]->points[nextPos] = target->points[nextPos];
        }
        if (target->points[nextPos] != NULL)
        {
            target->points[nextPos]->points[prevPos] = target->points[prevPos];
        }
    }

    void removeFromTwoLinks(stackItem* item)
    {
        if (item == NULL)
        {
            return;
        }
        if (item == _tail)
        {
            _tail = item->points[pPrev];
        }
        if (item == _minTail)
        {
            _minTail = item->points[pMinPrev];
        }
        if (item == _head)
        {
            _head = item->points[pNext];
        }
        if (item == _minHead)
        {
            _minHead = item->points[pMinNext];
        }
        removeNode(item, pPrev, pNext);
        removeNode(item, pMinPrev, pMinNext);
    }
};

int main()
{
    MinStack* s = new MinStack();
    s->push(-124);
    s->push(-164);
    s->getMin();
    s->getMin();
    s->getMin();
    s->pop();
    s->getMin();
    s->push(-24);
    s->push(-100);
    s->getMin();
    s->push(33);
    s->top();
    s->push(-22);
    s->getMin();
    s->push(197);
    s->getMin();
    s->push(127);
    s->push(122);
    s->getMin();
    s->push(139);
    s->push(142);
    s->push(189);
    s->getMin();
    s->top();
    s->push(-40);
    s->getMin();
    s->getMin();
    s->getMin();
    s->pop();
    s->push(174);
    s->getMin();
    s->getMin();
    s->getMin();
    s->top();
    s->top();
    s->push(-28);
    s->top();
    s->getMin();
    s->push(177);
    s->push(-117);
    s->getMin();
    s->top();
    s->push(42);
    s->getMin();
    s->getMin();
    s->top();
    s->top();
    s->push(-43);
    s->getMin();
    s->getMin();
    s->pop();
    s->pop();
    s->top();
    s->getMin();
    s->push(158);
    s->pop();
    s->push(25);
    s->push(-197);
    s->getMin();
    s->push(-120);
    s->push(-74);
    s->pop();
    s->getMin();
    s->getMin();
    s->push(51);
    s->push(60);
    s->getMin();
    s->push(182);
    s->getMin();
    s->push(-161);
    s->push(57);
    s->push(156);
    s->push(-182);
    s->push(28);
    s->getMin();
    s->pop();
    s->getMin();
    s->push(122);
    s->push(-119);
    s->push(-101);
    s->push(77);
    s->pop();
    s->getMin();
    s->top();
    s->getMin();
    s->getMin();
    s->top();
    s->push(-185);
    s->pop();
    s->push(-25);
    s->top();
    s->push(-7);
    s->push(91);
    s->push(-79);
    s->getMin();
    s->top();
    s->push(-168);
    s->push(115);
    s->push(-14);
    s->top();
    s->push(-95);
    s->push(-24);
    s->push(34);
    s->top();
    s->getMin();
    s->push(20);
    s->getMin();
    s->push(-88);
    s->top();
    s->push(1);
    s->push(186);
    s->getMin();
    s->pop();
    s->pop();
    s->push(-45);
    s->pop();
    s->getMin();
    s->top();
    s->getMin();
    s->top();
    s->push(89);
    s->getMin();
    s->push(-65);
    s->getMin();
    s->getMin();
    s->push(-100);
    s->getMin();
    s->push(-85);
    s->top();
    s->getMin();
    s->getMin();
    s->push(91);
    s->getMin();
    s->pop();
    s->getMin();
    s->getMin();
    s->getMin();
    s->top();
    s->pop();
    s->push(-80);
    s->top();
    s->getMin();
    s->getMin();
    s->getMin();
    s->push(-66);
    s->getMin();
    s->push(-3);
    s->pop();
    s->push(-185);
    s->push(-15);
    s->push(-185);
    s->push(-8);
    s->pop();
    s->getMin();
    s->pop();
    s->pop();
    s->push(177);
    s->top();
    s->push(-160);
    s->pop();
    s->getMin();
    s->getMin();
    s->push(-39);
    s->push(-67);
    s->getMin();
    s->pop();
    s->push(187);
    s->top();
    s->push(178);
    s->push(32);
    s->top();
    s->push(-119);
    s->push(-83);
    s->push(162);
    s->getMin();
    s->push(124);
    s->pop();
    s->getMin();
    s->push(-86);
    s->push(-21);
    s->getMin();
    s->push(19);
    s->getMin();
    s->pop();
    s->getMin();
    s->push(-126);
    s->push(-110);
    s->top();
    s->top();
    s->push(71);
    s->getMin();
    s->pop();
    s->push(-64);
    s->getMin();
    s->push(-21);
    s->push(148);
    s->getMin();
    s->top();
    s->pop();
    s->push(72);
    return 0;
}
