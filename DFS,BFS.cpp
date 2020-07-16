#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int n, m, start; // n:Á¤Á¡ÀÇ °¹¼ö, m:°£¼±ÀÇ °¹¼ö
int graph[1001][1001];
bool checked[1001];

void DFS(int num)
{
    checked[num] = true;
    cout << num << " ";

    for (int i = 1; i <= n; i++)
    {
        if (graph[num][i] == 1 && checked[i] == false)
            DFS(i);
    }
}
void BFS(int num)
{
    queue<int> q;
    q.push(num);
    checked[num] = true;
    while (1)
    {
        if (q.empty())
            break;

        int temp = q.front();
        q.pop();
        cout << temp << " ";
        num = temp;

        for (int i = 1; i <= n; i++)
        {
            if (graph[num][i] == 1 && checked[i] == false)
            {
                q.push(i);
                checked[i] = true;
            }
        }
    }
}
void init()
{
    for (int i = 0; i <= n; i++)
        checked[i] = 0;
}
int main() {

    cin >> n >> m >> start;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            graph[i][j] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    init();
    DFS(start);

    cout << endl;

    init();
    BFS(start);

    return 0;
}