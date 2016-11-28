#include <iostream>
#include "header.h"
#include "prim.h"

using namespace std;

int main()
{    
    int choise;
    cout << "1 - Краскал, 2 - Прім" << endl; cin >> choise;

    switch (choise)
    {
        case 1: { kruskal ob1; ob1.Sort(); ob1.Show();
                  break;
                }

        case 2: { prim ob2; ob2.algorithm();
                  break;
                }

        default: break;
    }

    return 0;
}
