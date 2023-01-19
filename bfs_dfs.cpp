#include <iostream>
#define MAXN 200
const int n = 10;
/* Start from v */
const int v = 1;

const int A[MAXN][MAXN] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0}};

bool used[MAXN];
void InitUsed()
{
    for (int i = 0; i < n; i++)
        used[i] = 0;
}

void BFS(int i)
{
    int k, j, p, queue[MAXN], currentVert, level, queueEnd;
    for (k = 0; k < n; k++)
        queue[k] = 0;
    for (k = 0; k < n; k++)
        used[k] = 0;
    queue[0] = i;
    used[i] = 1;
    currentVert = 0;
    level = 1;
    queueEnd = 1;
    int depth = 0;
    while (currentVert < queueEnd)
    {
        std::cout << depth << ": ";
        for (p = currentVert; p < level; p++)
        {

            std::cout << queue[p] + 1 << " ";
            currentVert++;
            for (j = 0; j < n; j++)
                if (A[queue[p]][j] && !used[j])
                {
                    queue[queueEnd++] = j;
                    used[j] = 1;
                }
        }
        std::cout << "\n";
        level = queueEnd;
        depth++;
    }
}

void DFS(int i)
{
    int k;
    used[i] = 1;
    std::cout << i + 1 << " ";
    for (k = 0; k < n; k++)
        if (A[i][k] && !used[k])
            DFS(k);
}

int main()
{
    int k;
    InitUsed();
    std::cout << "\nBFS " << v << "\n";
    BFS(v - 1);
    std::cout << "\n";

    InitUsed();
    std::cout << "\nDFS " << v << "\n";
    DFS(v - 1);
    std::cout << "\n";
    return 0;
}
