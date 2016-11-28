#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

class kruskal
{
private:
        int count_vertex, count_lines;
        int *nodes = new int[30];
        int last_node;

        struct line
        {
            int vertex1;
            int vertex2;
            int weight;

        } *lines = new line[30];

        kruskal(const kruskal&);
        kruskal &operator =(kruskal &);

public:
        explicit kruskal();

        void Sort();
        int Search(int n);
        void Show();
};


kruskal::kruskal()
{
    cout << "Введіть к-ть вершин: ";
    cin >> count_vertex;
    cout <<  "Введіть к-ть ребер: ";
    cin >> count_lines;

    for (int i = 0; i < count_vertex; i++)
        nodes[i] = -1 - i;

    cout << endl << "Задайте граф: " << endl;

    for (int i = 0; i < count_lines; i++)
    {
        cout << endl << "| Ребро #" << i + 1 << " |" << endl;
        cout << "Вершина #1 = "; cin >> lines[i].vertex1;
        cout << "Вершина #2 = "; cin >> lines[i].vertex2;
        cout << "Вага = "; cin >> lines[i].weight;
        cin.ignore();
    }

    cout << endl << "Граф задано!" << endl;
}

void kruskal::Sort()
{
    for (int i = 0; i < count_lines - 1; i++)
    for (int j = i; j < count_lines - 1; j++)
    if (lines[i].weight > lines[j].weight)
        swap(lines[i], lines[j]);
}

int kruskal::Search(int n)
{
    if (nodes[n] < 0)
    {
        last_node = n;
        return nodes[last_node];
    }
    else
        {
            int searched;
            searched = Search(nodes[n]);
            nodes[n] = last_node;
            return searched;
        }
}

void kruskal::Show()
{
    int suma = 0;

    cout << endl << "Каркас: " << endl;
    for (int i = 0; i < count_lines; i++)
    {
        int node1 = Search(lines[i].vertex2);
        int node2 = Search(lines[i].vertex1);
        if (node1 != node2)
        {
            nodes[last_node] = lines[i].vertex2;
            cout << "Ребро (" << lines[i].vertex1 << " - " << lines[i].vertex2 << ")";
            cout << " Вага: " << lines[i].weight << endl;
            suma += lines[i].weight;
        }
    }

    cout << "Мінімальна вага дерева становить = " << suma << endl;

}

#endif // HEADER_H
