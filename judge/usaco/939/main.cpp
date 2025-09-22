#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    pair<int, int> start, goal, rock;

    char ch;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j <= 10; j++){
            cin >> ch;
            if (ch == 'B'){
                start = {i, j};
            } else
            if (ch == 'L'){
                goal = {i, j};
            } else 
            if (ch == 'R'){
                rock = {i, j};
            }
        }
    }

    int condition1 = (start.first == rock.first && rock.first == goal.first && ((start.second < rock.second && rock.second < goal.second) || (goal.second < rock.second && rock.second < start.second)));
    int condition2 = (start.second == rock.second && rock.second == goal.second && ((start.first < rock.first && rock.first < goal.first) || (goal.first < rock.first && rock.first < start.first)));
    if (condition1 || condition2){
        printf("%d\n", abs(start.first-goal.first)+abs(start.second-goal.second)+1);
    } else {
        printf("%d\n", abs(start.first-goal.first)+abs(start.second-goal.second)-1);
    }
    return 0;
}