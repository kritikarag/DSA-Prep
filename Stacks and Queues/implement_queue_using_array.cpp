#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int start,end,currsize,maxsize;
    Queue(){
        arr = new int[16];
        start = -1;
        end =-1;
        currsize = 0;
    }

    Queue(int maxsize){
        (*this).maxsize = maxsize;
        arr = new int[maxsize];
        start = -1;
        end = -1;
        currsize = 0;
    }

    void push(int x){
        if(currsize==maxsize){
            cout<<"Queue if full"<<endl;
            return;
        }

        if(end==-1){
            start =0;
            end =0;
        }
        else{
            end = (end+1)%maxsize;
        }
        arr[end] = x;
        cout<<"The element pushed"<<endl;
        currsize++;
    }

    void pop(){
        if(start==-1){
            cout<<"Queue is empty"<<endl;
            return;
        }
        if(currsize==1){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%maxsize;
        }
        currsize--;
    }

    int top(){
        if(start==-1){
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        return arr[start];
    }

    int size(){
        return currsize;
    }
};