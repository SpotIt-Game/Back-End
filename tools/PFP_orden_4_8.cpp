#include<iostream>
using namespace std;
#define ll unsigned long long int
#include<string>
#include<vector>

//resuelve SOLO los PPF que faltaban (4,8)

vector<vector<int>>cards;
bool flag; 

int f(int n){
    return n*n+n+1;
}

ll verify(ll msk1, ll msk2){ 
    return msk1&msk2;
}

ll combine(ll msk1, ll msk2){
    return msk1|msk2;
}

int countBits(ll msk){ 
    int cont=0;
    while(msk){
        cont++;
        msk-=msk&-msk;
    } return cont;
}

void fill(vector<vector<ll>>&v, vector<int>&card, int cardNum){
    for(int i=0;i<(int)card.size();i++){
        if(cardNum<64) v[card[i]][0]=combine(v[card[i]][0],1ULL<<(cardNum));
        else v[card[i]][1]=combine(v[card[i]][1],1ULL<<(cardNum%64));
    }
}

void print(){ //Solo sirve para imprimir Danilo
    for(int i=0;i<(int)cards.size();i++){
        cout<<"Card "<<i+1<<": ";
        for(int j=0;j<(int)cards[i].size();j++){
            cout<<cards[i][j]+1<<" ";
        } cout<<'\n';
    }
}

void copy(vector<int>&t,vector<int>&card){
    for(int i=0;i<(int)card.size();i++) t.push_back(card[i]);
}

void cardGenerator(vector<vector<ll>>&v, ll msk, ll msk2, int& n, vector<int> card, int index){ 
    if((int)card.size()==n+1){
        if(countBits(msk)+countBits(msk2)<(int)cards.size()) return;
        cards.push_back(card);
        flag=true;
    } for(int i=index;i<(int)v.size();i++){
        if(flag) break;
        if(!verify(v[i][0],msk) && !verify(v[i][1],msk2) && (countBits(v[i][1])+countBits(v[i][0])<n+1)){
            vector<int>t;
            copy(t,card);
            t.push_back(i);
            cardGenerator(v,combine(v[i][0],msk),combine(v[i][1],msk2),n,t,i+1);
        }
    }
}

int main(){
    int n; cin>>n;
    int cc=f(n);
    vector<vector<ll>>fig(cc,vector<ll>(2,0));
    for(int i=0;i<cc;i++){ 
        flag=false;
        vector<int>t;
        cardGenerator(fig,0,0,n,t,0);
        if(!flag) break; //precausion
        fill(fig,cards[i],i);                             
    } print();
    return 0;
}
