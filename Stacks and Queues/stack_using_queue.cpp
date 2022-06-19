//uSING 2 QUEUES
class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
      while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
      
        return;
    }
    
    int pop() {
        int x = q2.front();
        q2.pop();
        return x;
    }
    
    int top() {
        int x=q2.front();
        return x;
    }
    
    bool empty() {
        return q2.empty();
    }
};

//USING 1 QUEUE
class MyStack {
public:
    queue<int>q1;
   
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        for(int i=0;i<q2.size()-1;i++){
            q2.push(q2.front());
            q2.pop();
        }
        
        return;
    }
    
    int pop() {
        int x = q2.front();
        q2.pop();
        return x;
    }
    
    int top() {
        int x=q2.front();
        return x;
    }
    
    bool empty() {
        return q2.empty();
    }
};
