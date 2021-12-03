#include<bits/stdc++.h>
using namespace std;
long long inv;

void cal(int l,int mid,int r, vector<int>&arr){
    int ptr1=l,ptr2=mid+1;
    vector<int>temp(r-l+1);
    int ind=0;
    while(ptr1<=mid && ptr2<=r){
        if(arr[ptr1]<=arr[ptr2]){
            temp[ind++]=arr[ptr1++];
            inv+=ptr2-(mid+1);
        }
        else{
            temp[ind++]=arr[ptr2++];
        }
    }
    while(ptr1<=mid){
        temp[ind++]=arr[ptr1++];
        inv+=ptr2-(mid+1);
    }
    while(ptr2<=r){
        temp[ind++]=arr[ptr2++];
    }
    ind=0;
    for(int i=l;i<=r;i++){
        arr[i]=temp[ind++];
    }
}

void merge(int l,int r,vector<int> &arr){
    if(l<r){
        int mid=(l+r)/2;
        merge(l,mid,arr);
        merge(mid+1,r,arr);

        cal(l,mid,r,arr);
    }
}

long long solve(int n,vector<int>arr){
    inv=0;
    merge(0,n-1,arr);
    return inv;
}
