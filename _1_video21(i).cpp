#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st,int top){
    if(st.empty()){
        st.push(top);
        return;
    }
    int topele = st.top();
    st.pop();
    insert_at_bottom(st,top);
    st.push(topele);
}

void reverse_stack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverse_stack(st);
    insert_at_bottom(st,top);

}

int main(){

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"Top element :- "<<st.top()<<endl;
    reverse_stack(st);
    cout<<"After reverse stack "<<endl;
    cout<<"Top element :- "<<st.top()<<endl;
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}