#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c=='$'||c=='^'){
        return 3;
    }
    else if(c=='+'||c==')'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2; 
    }
    else{
        return -1;
    }
}
void toPostfix(string s){
    string r;
    stack<char> st;
    // create_stack(sizeof(s));
    for(int i=0;i < s.length();i++){
        char c=s[i];
        if(c>='a'&& c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'){
            r+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top()!='('){
                r+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty()&&prec(s[i])<=prec(st.top())){
                r+=st.top();
                st.pop();
            }
            st.push(c);
        }

    }
    while(!st.empty()){
        r+=st.top();
        st.pop();
    }
    cout<<"Infix : "<<s<<endl;
    cout<<"postfix : "<<r<<endl;
}
void toPrefix(string s){    
    string r;
    stack<char> st1;
    int n=s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    // cout<<s;
    for(int i=0;i < s.length();i++){
        char c=s[i];
        if(c>='a'&& c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'){
            r+=c;
        }
        else if(c==')'){
            st1.push(c);
        }
        else if(c=='('){
            while(st1.top()!=')'){
                r+=st1.top();
                st1.pop();
            }
            st1.pop();
        }
        else{
            while(!st1.empty()&&prec(s[i])<prec(st1.top())){
                r+=st1.top();
                st1.pop();
            }
            st1.push(c);
        }

    }
    while(!st1.empty()){
        r+=st1.top();
        st1.pop();
    }
    int n1=r.length();
    for (int i = 0; i < n1 / 2; i++)
        swap(r[i], r[n1 - i - 1]);
    cout<<"Infix : "<<s<<endl;
    cout<<"prefix : "<<r<<endl;
}

int main(){
    string s;
    cout<<"Enter expression:- \n";
    cin>>s;
    toPostfix(s);
    toPrefix(s);
    return 0;
}