#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    int pnr,coach[10][5];
class wl{
public:

    int src,dst,seats,pnr;
};
list<wl> wlist;

void allocate(int sr,int ds,int seats){
        pnr++;
    cout<<"Booking has successfully completed!"<<endl;
    cout<<"your PNR number is : "<<pnr<<endl;
    cout<<"your seats are : ";

     for(int i=0,j;i<8&&seats>0;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
        if(j==ds){
            for(j=sr;j<ds;j++){
            coach[i][j]=pnr;
            }
            seats--;
        cout<<i+1<<" ";
        }
    }
    cout<<endl;
}

void realot(int sr,int ds,int seats,int cpnr){
    int temp=seats;
    bool flag=false;

     for(int i=8,j;i<10&&temp>0;i++){
            flag=false;
            for(j=0;j<5;j++)
            if(cpnr==coach[i][j]){
                flag=true;
                coach[i][j]=0;
            }
            if(flag)
                temp--;
        }

     for(int i=0,j;i<8&&seats>0;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
        if(j==ds){
            for(j=sr;j<ds;j++){
            coach[i][j]=cpnr;
            }
            seats--;
        }
    }
}
void reallocate(){
    int sr,ds,seats,ct=0,cpnr;
    list<wl>::iterator y;
    for(list<wl>::iterator x =wlist.begin();x!=wlist.end();){
            ct=0;
        sr=x->src;ds=x->dst;seats=x->seats;cpnr=x->pnr;
        for(int i=0,j;i<8;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
        if(j==ds)
            ct++;
    }
    if(seats<=ct){
        y=x;
        x++;
       // cout<<"found location for pnr : "<<cpnr<<endl;
       realot(sr,ds,seats,cpnr);
       wlist.erase(y);
    }
    else
        x++;
    }
}
void allocate_w(int sr,int ds,int seats){
     pnr++;
     wl t;
     t.src=sr;t.dst=ds;t.seats=seats;
     t.pnr=pnr;
     wlist.push_back(t);
     cout<<"seats are not available, your waiting list number is : "<<wlist.size()<<endl;
     for(int i=8,j;i<10&&seats>0;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
        if(j==ds){
            for(j=sr;j<ds;j++){
            coach[i][j]=pnr;
            }
            seats--;
        }
    }


}
void bookit(int sr,int ds,int seats){
    int ct=0;
    for(int i=0,j;i<8;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
        if(j==ds)
            ct++;
    }
    if(seats<=ct){
       allocate(sr,ds,seats);
       return ;
    }
    else {
            ct=0;
         for(int i=8,j;i<10;i++){
        for(j=sr;j<ds;j++){
            if(coach[i][j]!=0)
                break;
        }
            if(j==ds)
                ct++;
        }
        if(ct>=seats){
            allocate_w(sr,ds,seats);
            return ;
        }
        else{
                cout<<"Seats are not available :( "<<endl;
            return ;
        }
    }
}

void cancel(int cpnr,int seats){
    bool flag=false;
        for(int i=0,j;i<8&&seats>0;i++){
                flag=false;
            for(j=0;j<5;j++)
            if(cpnr==coach[i][j]){
                flag=true;
                coach[i][j]=0;
            }
            if(flag)
                seats--;
        }
        if(seats==0){
            reallocate();
            cout<<"your cancellation is successful!!"<<endl;
        }
        else if(cpnr>=pnr){
            cout<<"your PNR is not valid"<<endl;
        }
        else
            cout<<"your ticket is not yet confirmed"<<endl;
}


int main(){
 pnr=0;
    while(1){
        int op;
        cout<<"1. book "<<endl<<"2. cancel"<<endl<<"3. Chart"<<endl;
        cout<<"enter option : ";
        cin>>op;


        char sr,ds;
        int seats,cpnr;
        switch(op){
        case 1:
            cout<<"enter from , to and no.of seats : ";
            cin>>sr>>ds>>seats;
            cout<<sr-'A'<<" "<<ds-'A'<<endl;
            bookit(sr-'A',ds-'A',seats);
            break;
        case 2:
            cout<<"enter your pnr and no. of seats to cancel : ";
            cin>>cpnr>>seats;
            cancel(cpnr,seats);
            break;
        case 3:
            cout<<"enter station for the Chart : ";
            cin>>sr;
            for(int i=0;i<8;i++){
                if(coach[i][sr-'A']!=0)
                    cout<<"Seat number : "<<i+1<<" is reserved for PNR no. "<<coach[i][sr-'A']<<endl;
            }
            break;
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<5;j++)
                cout<<coach[i][j]<<" ";
            cout<<endl;
        }
        cout<<"wlist size "<<wlist.size()<<endl;
        list<wl> ::iterator itr=wlist.begin();
        cout<<itr->src<<" "<<itr->dst<<" "<<itr->seats<<" "<<itr->pnr<<endl;
    }
    return 0;
}
