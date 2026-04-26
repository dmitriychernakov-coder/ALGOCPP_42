#include<iostream>
#include<fstream>

void dfs(int** graph, bool* visited, int vertex, int n);


int main(int argc, char** argv) {
    std::ifstream file("input.txt");

    if(file.is_open()) {
        int n;
        file >> n;
        int** graph = new int*[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                file >> graph[i][j];
            }
            
        }
        file.close();
        bool* visited = new bool[n]();
        std::cout << "Порядок обхода вершин: ";
        dfs(graph,visited,0,n);
        std::cout << std::endl;
        for (int i = 0; i < n; i++){
            delete[]graph[i];
        }
        delete[]graph;
        delete[]visited;
        return 0;

    } else {
        std::cout << "Не получилось открыть файл input.txt!" << std::endl;
        return 1;
    }
}

void dfs(int** graph, bool* visited, int vertex, int n) {
    visited[vertex] = true;
    std::cout << vertex + 1 << " ";

    for (int i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && !visited[i]) {
            dfs(graph,visited,i,n);
        }
    }
}