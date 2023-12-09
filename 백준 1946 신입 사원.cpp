// 백준 1946 신입 사원

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int partition(std::vector<std::pair<int, int>>& score, int start, int end) {
    
    int pivot = score[end].first;
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (score[j].first < pivot) {
            i++;
            std::swap(score[i], score[j]);
        }
    }
    std::swap(score[i + 1], score[end]);
    return i + 1;
}

void quicksort(std::vector<std::pair<int, int>>& score, int left, int right) {
    if (left < right) {
        int q = partition(score, left, right);
        quicksort(score, left, q - 1);
        quicksort(score, q + 1, right);
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int test = 0;
    std::cin >> test;
    while (test--) {
        int employee = 0;
        std::cin >> employee;
        std::vector<std::pair<int, int>> score(employee, {0 , 0});
        
        for (int i = 0; i < employee; i++) {
            std::cin >> score[i].first >> score[i].second;
        }

        std::sort(score.begin(), score.end());
        //quicksort(score, 0, employee - 1);

        int max_score = score[0].second;
        int count = 1;
        for (int i = 1; i < employee; i++) {
            if (score[i].second < max_score) {
                count++;
                max_score = score[i].second;
            }
        }
        std::cout << count << "\n";
    }
}


/*
1
10
1 10
2 9
3 8
4 7
5 6
6 5
7 4
8 3
9 2
10 1
-> 10

1
5
1 5
2 3
3 4
4 2
5 1
-> 4

2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1
->
4
3

*/