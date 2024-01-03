#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
long long a, b, c, d;

vector<int> matrix(100001);

void increase(int k){
    while(k > 1){
        if(matrix[k] >= matrix[k / 2])
            return ;
        else {
            swap(matrix[k], matrix[k / 2]);
            k /= 2;
        }
    }
}

void decrease(int k, int n){
    while(2 * k <= n){
        int p = 2 * k;
        if(p + 1 <= n && matrix[p + 1] < matrix[p])
            p++;
        if(matrix[k] <= matrix[p])
            return ;
        else {
            swap(matrix[p], matrix[k]);
            k = p;
        }
    }
}

int main(){
    cin >> n >> k >> a >> b >> c >> d;
    matrix[1] = a;
    for(int i = 2; i <= n; ++i){
        a = (1ll * a * b + c) % d;
        if(i > k){
            if(a > matrix[1])
                matrix[1] = a, decrease(1, k);
        }
       else {
            matrix[i] = a;
            increase(i);
        }
    }
    while(k > 0){
        cout<<matrix[1]<<' ';
        matrix[1] = matrix[k];
        k--;
        decrease(1, k);
    }
    return 0;
}