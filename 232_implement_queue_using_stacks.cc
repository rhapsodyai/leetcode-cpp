#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;
class MyQueue {
    stack<int> stk;
    stack<int> stk2;
 
    /** Initialize your data structure here. */
    MyQueue() {
        this->stk = {};
        this->stk2 = {};
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        //1. pop everything from stk onto stk2
        while(!stk.empty()) {
            stk2.push(stk.top());
            stk.pop();
        }
        
        //2. push e onto stk
        stk.push(x);
        
        //3. pop everything from stk2 onto stk
        while(!stk2.empty()) {
            stk.push(stk2.top());
            stk2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        /*
        since Queue is FIFO
        ---------      ----------
        */
        if(!stk.empty()) {
            //1. push all elements but one onto stk2
            for(int i = 0; i < stk.size()-1; i++) {
                stk2.push(stk.top());
                stk.pop();
            }

            //2. get the last element
            int temp = stk.top();
            stk.pop();

            //3. push all elements from stk2 to stk
            while(!stk2.empty()) {
                stk.push(stk2.top());
                stk2.pop();
            }
            
            return temp;
        } else {
            return -1;
        }
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->stk.empty() ? true : false;
    }
};


int main(int argc, char** argv) {
	/*
	stack<int> stk = {};

	stk.push(1);
	stk.push(2);
	stk.push(3);

	int stk_size = stk.size();
	for(int i = 0; i < stk_size; i++) {
		cout << "y" << endl;
		cout << stk.top() << endl;
		stk.pop();
	}

	//cout << stk << endl;
	*/
}