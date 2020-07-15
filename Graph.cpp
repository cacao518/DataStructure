#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, m; // n:������ ����, m:������ ����
    cin >> n >> m;

    int** graph = new int*[n];
    for (int i = 0; i <= n; ++i)
        graph[i] = new int[n];
    
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
            graph[i][j] = 0;
    }

    // ���� ���� ����
    for (int i = 0; i < m; i++)  
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
        // �ܹ����� ��� graph[u][v] = 1;
        // ����ġ�� �ִ�, �ܹ����� ��� graph[u][v] = ����ġ��;
    }
}