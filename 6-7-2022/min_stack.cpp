class MinStack {
public:
    //pair(val,minimal value) tc-O(1) sc-O(2N)
    
    // whenever we need to push minimal which is minimum than the previous minimum value 
    // push the modified value push(2*current_minimal - previous_minimal) and update         //  mini=current_minimal
    // getMin= print mini
    // top= if the top element is lesser than the mini then return mini
    // when you roll back
    // pop if the minimal value is poped out then mini=2*current_minimal-modified_value(st.top)
    // modified_value < mini
    // value<mini ==> value-mini<0 ==> 2*value-mini<value ==> modified_value<mini
    stack<long long>st;
    long long mini;
    MinStack() {
        while(st.empty()==false) st.pop(); 
        mini=INT_MAX;
        
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            mini=value;
            st.push(value);
        }
        else{
            if(value<mini){
                st.push(2*value*1LL -mini);
                mini=value;
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=2*mini-el;
            
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long el=st.top();
        if(el<mini) return mini;
        else
            return el;
    }
    
    int getMin() {
        return mini;
    }
};
