#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> s;
    list<int> ::iterator it=s.begin(),it2;
    for(int i=0;i<5;i++)
        s.push_back(i);
    for(it=s.begin();it!=s.end();){
        if(*it==2){
            it2=it;
            it++;
            s.erase(it2);
        }
        else
            it++;
    }
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
