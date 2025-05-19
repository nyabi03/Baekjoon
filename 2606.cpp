#include <iostream>
#include <vector>

bool visited[101];
std::vector<int> graph[101];
int infected_count = 0;

void dfs(int computer)
{
    visited[computer] = true;
    infected_count++;

    for (int connected_computer : graph[computer])
    {
        if(!visited[connected_computer])
        {
            dfs(connected_computer);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    std::cout << infected_count -1 << std::endl;
}