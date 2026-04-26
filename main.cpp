#include<iostream>

using namespace std;

#define STACKOVERFLOW -1
#define STACKUNDERFLOW -2

class ArrayStack{
    private:
        int top;
        int * stack;
        int iStackSize;

    public:
    ArrayStack(int iStackSize){
        top = -1;
        this->iStackSize = iStackSize;
        stack = new int[iStackSize];

    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == iStackSize-1;
    }

    int push(int iValue)
    {
        if(isFull()){
            return STACKOVERFLOW;
        }
        stack[++top] = iValue;
        return top;
    }

    int pop()
    {
        if(isEmpty())
        {
            return STACKUNDERFLOW;
        }
        int iPopedValue = stack[top];
        top--;
        return iPopedValue;
        
    }

    int peek()
    {
        if(isEmpty()) return STACKUNDERFLOW;
        return stack[top];
    }

    void clear()
    {
        top = -1;
    }

};

int main()
{
    ArrayStack st(10);

    cout<<st.push(10)<<endl;
    cout<<st.push(40)<<endl;
    cout<<st.push(50)<<endl;
    cout<<st.push(60)<<endl;
    cout<<st.push(20)<<endl;
    st.clear();
    cout<<st.peek()<<endl;
    return 0;
}