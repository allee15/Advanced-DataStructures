/*#include<bits/stdc++.h>

using namespace std;

ifstream f("bomboane.in");
ofstream g("bomboane.out");

int n, suma, iMinim, iMaxim, ceva;
//vector<int> matrix(1001);
multiset<pair<int,int>> matrix;
vector<vector<int>>result(1001, vector<int>(3));
pair<int, int> minim, maxim;
void moveCandies() {
    suma /= n;
    int ok = 1;
    while(ok)
    {
        minim = *matrix.begin();
        maxim = *prev(matrix.end());
        if (minim.first == maxim.first) {
            ok = 0;
        }
        else {
            result[++ceva][0] = maxim.second;
            result[ceva][1] = minim.second;
            result[ceva][2] = suma - minim.first;
            matrix.erase(matrix.begin());
            matrix.erase(prev(matrix.end()));
            matrix.insert({suma, minim.second});
            matrix.insert({ maxim.first - (suma - minim.first), maxim.second});
        }


    //    minim = 1000000;
        maxim = -1;
        for (int i = 1; i <= n; i++)
        {
            if(minim > matrix[i]) {
                minim = matrix[i];
                iMinim = i;
            }
            if(maxim < matrix[i]) {
                maxim = matrix[i];
                iMaxim = i; }
        }
        if(minim == maxim)
            ok = 0;
        else
        {
            result[++ceva][0] = iMaxim;
            result[ceva][1] = iMinim;
            result[ceva][2] = suma - minim;
            matrix[iMinim] = suma;
            matrix[iMaxim] = maxim - (suma - minim);
        }//
    }
    g << ceva << '\n';
    for (int i = 1; i <= ceva; i ++)
    {
        for (int j = 0; j < 3; j++)
            g << result[i][j] << ' ';
        g << '\n';
    }
}

int main()
{
    f >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        f >> x;
        matrix.insert({x,i});
        suma += x;
    }
    if(suma%n)
        g << -1;
    else
    {
        moveCandies();
    }
    f.close();
    g.close();

    return 0;
}*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

ifstream f("bomboane.in");
ofstream g("bomboane.out");

int n, suma, ceva;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
vector<vector<int>>result(1001, vector<int>(3));

void moveCandies() {
    suma /= n;
    int ok = 1;
    while(ok)
    {
        if (maxHeap.empty() || minHeap.empty() || maxHeap.top() == minHeap.top()) {
            ok = 0;
        }
        else {
            result[++ceva][0] = maxHeap.top();
            result[ceva][1] = minHeap.top();
            result[ceva][2] = suma - minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(suma);
            minHeap.push(suma - (suma - minHeap.top()));
        }
    }
    g << ceva << '\n';
    for (int i = 1; i <= ceva; i ++)
    {
        for (int j = 0; j < 3; j++)
            g << result[i][j] << ' ';
        g << '\n';
    }
}

int main()
{
    f >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        f >> x;
        maxHeap.push(x);
        minHeap.push(x);
        suma += x;
    }
    if(suma%n)
        g << -1;
    else
    {
        moveCandies();
    }
    f.close();
    g.close();

    return 0;
}

