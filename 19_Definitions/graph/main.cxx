#include <iostream>
#include <vector>

using namespace std;

// Структура для хранения графа
struct Edge {
  int u = 0;
  int v = 0;
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Перечисление множеств
    vector<Edge> edges = { {0, 3}, {0, 4}, {1, 3}, {1, 5}, {2, 4} };
    
    // Матрица смежности
    const int n = 7; // количество вершин (3 + 4)
    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));
    for (const auto& edge : edges) {
        adjacency_matrix[edge.u][edge.v] = 1;
        adjacency_matrix[edge.v][edge.u] = 1;
    }
    
    // Матрица инцидентности
    const int m = 5; // количество рёбер
    vector<vector<int>> incidence_matrix(n, vector<int>(m, 0));
    int edge_index = 0;
    for (const auto& edge : edges) {
        incidence_matrix[edge.u][edge_index] = 1;
        incidence_matrix[edge.v][edge_index] = 1;
        edge_index++;
    }

    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    // Вывод матриц
    cout << "Матрица смежности:" << endl;
    printMatrix(adjacency_matrix);
    cout << endl;
    
    cout << "Матрица инцидентности:" << endl;
    printMatrix(incidence_matrix);
    
    return 0;
}
