#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, m; // n:정점의 갯수, m:간선의 갯수
    cin >> n >> m;

    int** graph = new int*[n];
    for (int i = 0; i <= n; ++i)
        graph[i] = new int[n];
    
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
            graph[i][j] = 0;
    }

    // 간선 정보 저장
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
        // 단방향의 경우 graph[u][v] = 1;
        // 가중치가 있는, 단방향의 경우 graph[u][v] = 가중치값;
    }
}