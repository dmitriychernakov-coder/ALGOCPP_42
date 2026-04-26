#include<iostream>
#include<fstream>
#include<queue>

void bfs(int** graph, bool* visited, int start_vertex, int n);


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

        int start_input{0};

        std::cout << "В графе " << n << " вершин." << std::endl;
        std::cout << "Введите номер вершины, с которой начнётся обход: ";
        std::cin >> start_input;
        int start_vertex = start_input - 1;

        if (start_vertex < 0 || start_vertex >= n) {
        std::cerr << "Ошибка: неверный номер вершины." << std::endl;

        for (int i = 0; i < n; ++i) delete[] graph[i];
        delete[] graph;
        delete[] visited;
        return 1;
        }

        std::cout << "Порядок обхода вершин: ";
        
        bfs(graph,visited,start_vertex,n);
        
        
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

void bfs(int** graph, bool* visited, int start_vertex, int n) {

    std::queue<int> queue;
    queue.push(start_vertex);
    visited[start_vertex] = true;
    std::cout << start_vertex + 1 << " ";

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        for (int v = 0; v < n; ++v) {
            if(graph[vertex][v] == 1 && !visited[v]) {
                queue.push(v);
                visited[v]=true;
                std::cout << v + 1 << " ";
            }
        }
    }
}