#include "graphics.h"
#include <iostream>
#include <vector>
#include <fmt/format.h>
#include "Blueprint.h"
#include "Wrapper.h"

using namespace std;

inputData _inputData();

int main()
{
    //int nPoint;
    //vector<vector<int>> point(10, vector<int>(10)); // default length 10
    //inputData(&nPoint, &point);

    auto data = _inputData();


    // input 5   0 1 1 0 1   1 0 1 0 0   1 1 0 1 0   0 0 1 0 1   1 0 0 1 0

    cout << endl;
    
    for (int i = 0; i < data.nPoint; i++) {
        for (int j = 0; j < data.nPoint; j++) {
            cout << data.point[i][j] << " ";
        }
        cout << endl;
    }

    

    initwindow(1200, 700, "Group: 5");

    for (int i = 1; i <= data.nPoint; i++) {
        auto click = Wrapper::getClick();
        Vertex v = {
            click.x,
            click.y,
            i
        };
        data.Vertexs.push_back(v);
        Wrapper::drawCircle(v, 5);
    }

    Wrapper::drawLine(data);


    while (!kbhit())
    {
        delay(300);
    }
    return 0;
}

/*
void inputData(int *nPoint, vector<vector<int>> *point) {
    cout << "Enter number of point: ";
    cin >> *nPoint;
    cout << typeid(*nPoint).name() << endl;
    cout << "Enter: " << *nPoint << endl;

    //point->reserve(*nPoint);
    for (int i = 0; i < *nPoint; i++) {
        for (int j = 0; j < *nPoint; j++) {
            //cout << "Enter [" << i << "][" << j << "]: ";
            cout << fmt::format("Enter [{}][{}]", i, j);
            cin >> (*point)[i][j];
        }
    }
}
*/

inputData _inputData() {
    struct inputData data;

    cout << "Enter number of point: ";
    cin >> data.nPoint;
    cout << typeid(data.nPoint).name() << endl;
    cout << "Enter: " << data.nPoint << endl;

    //data.point.
    //point->reserve(*nPoint);
    int input;
    //data.point.reserve(10);
    data.point.resize(data.nPoint);
    data.Lines.reserve(data.nPoint);
    //cout << "size: " << data.point.size();
    for (int i = 0; i < data.nPoint; i++) {
        data.point[i].reserve(data.nPoint);
        //data.point[i].resize(10);
        for (int j = 0; j < data.nPoint; j++) {
            //cout << "Enter [" << i << "][" << j << "]: ";
            cout << fmt::format("Enter [{}][{}]: ", i, j);
            //cin >> (data.point)[i][j];
            cin >> input;
            (data.point)[i].push_back(input);
            if (input == 1) {
                Line line;
                line.start = i;
                line.end = j;
                data.Lines.push_back(line);
            }
             //data.d.push_back(x);

        }
    }
    return data;
}