#include <bits/stdc++.h>

typedef std::vector<int> conjunto;

void fillGraph(std::vector<conjunto> & graph, int cards, int n){
    int index = 0;
    for(int i = 1; i < cards; i++){
        graph[i].push_back(graph[0][index]);
        if( i != 1 && i % (n - 1) == 0)index ++;
    }
}

void fillSeed(std::vector<conjunto> & graph, int n){
    for(int i = 1; i <= n; i++){
        graph[0].push_back(i);
    }
}

int main(){
    int n = 4;
    int cards = (n*(n-1) + 1);
    std::vector<conjunto> graph(cards);
    fillSeed(graph, n);
    fillGraph(graph, cards, n);
    for(conjunto i : graph){
        for(int j : i){
            std::cout << j << " ";
        }
        std::cout << '\n';
    }



    return 0;
}