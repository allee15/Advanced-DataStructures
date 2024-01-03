#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream f("nrpits.in");
ofstream g("nrpits.out");

int main() {
    int n;
    f >> n;
    vector<int> matrix(n);
    for (int i = 0; i < n; i++) {
        f >> matrix[i];
    }
    stack<int> stiva;
    int gropi = 0;
    for (int i = 0; i < n; i++) {
        while (!stiva.empty() && stiva.top() < matrix[i]) {
            stiva.pop();
            if(stiva.size()>=1) {
                gropi++;
            }
        }
        stiva.push(matrix[i]);
    }
    g << gropi;
    return 0;
}