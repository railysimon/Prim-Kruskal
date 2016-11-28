#ifndef PRIM_H
#define PRIM_H

#include <iostream>
#include <fstream>

using namespace std;

class prim
{
private:
        int **graph;
        const int size;
        const int infinity = 999;
        int nodes[4], weight[4];
        bool used[4];

        prim(const prim &);
        prim &operator =(prim &);
public:
        explicit prim();
        ~prim();

        void algorithm();
        inline int minWeight();
        void Show();
};

prim::prim() : size(4)
{
    graph = new int*[size];
        for(int i=0; i<size; i++)
            graph[i] = new int;

        ifstream file("data.txt");

        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                file >> graph[i][j];

        cout << "Матриця суміжностей графа: " << endl;
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }

    file.close();
}

prim::~prim()
{
    for(int i=0; i<size; i++)
        delete graph[i];
    delete [] graph;
}

void prim::algorithm()
{
    for (int i=0; i<size; i++)
    {
       weight[i] = infinity;
       used[i] = false;
    }

    weight[0] = 0;
    nodes[0] = -1;

    for (int i=0; i < size-1; i++)
    {


       int val = minWeight();
       used[val] = true;
       for (int v = 0; v < size; v++)

         if (graph[val][v] && !(used[v]) && graph[val][v] <  weight[v])
            nodes[v]  = val, weight[v] = graph[val][v];
    }

    Show();
}

inline int prim::minWeight()
{
    int min = infinity, min_index;

    for (int i = 0; i < size; i++)
      if (!(used[i]) && weight[i] < min)
          min = weight[i], min_index = i;

    return min_index;

}

void prim::Show()
{
    int summa = 0;
    cout << endl;

    for (int i = 1; i < size; i++)
    {
       cout << "(" << nodes[i] + 1 << " - " << i + 1 << ") "  << "   Вага: "<< graph[i][nodes[i]] << endl;
       summa += graph[i][nodes[i]];
    }

    cout << endl << "Вага мінімального дерева: " << summa << endl;

}

#endif // PRIM_H
