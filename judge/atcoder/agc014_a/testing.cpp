#include <bits/stdc++.h>
using namespace std;

int main(){
    for (int initA = 2; initA <= 1000; initA += 2){
        for (int initB = 2; initB <= 1000; initB += 2){
            for (int initC = 2; initC <= 1000; initC += 2){
                int a = initA, b = initB, c = initC;
                int next_a, next_b, next_c;
                int cnt = 0;
                while (a%2 == 0 && b%2 == 0 && c%2 == 0){
                    cnt++;
                    next_a = (b+c)/2;
                    next_b = (a+c)/2;
                    next_c = (a+b)/2;

                    a = next_a;
                    b = next_b;
                    c = next_c;

                    if (a == b && b == c){
                        cnt = -1;
                        break;
                    }
                }

                
                if (cnt > 5){
                    printf("=================");
                    printf("%d %d %d => %d\n", initA, initB, initC, cnt);
                }
            }
        }
    }

    
    return 0;
}