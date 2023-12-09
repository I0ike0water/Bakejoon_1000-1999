// 백준 1931 회의실 배정.cpp

#include <iostream>
#include <vector>

//-----------------------병합 정렬-----------------------
std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>>& start,
    std::vector<std::pair<int, int>>& end) {
    std::vector<std::pair<int, int>> result;
    int i = 0;
    int j = 0;
    int s = start.size();
    int e = end.size();

    while (i < s && j < e) {
        if (start[i].first < end[j].first) {
            result.push_back(start[i]);
            i++;
        }
        else if (start[i].first > end[j].first) {
            result.push_back(end[j]);
            j++;
        }
        else {
            if (start[i].second < end[j].second) {
                result.push_back(start[i]);
                i++;
            }
            else{
                result.push_back(end[j]);
                j++;
            }
        }
    }

    while (i < s) {
        result.push_back(start[i]);
        i++;
    }

    while (j < e) {
        result.push_back(end[j]);
        j++;
    }

    return result;
}

std::vector<std::pair<int, int>> mergeSort(std::vector<std::pair<int, int>>& v) {
    int size = v.size();

    if (size <= 1) return v;

    int middle = size / 2;
    std::vector<std::pair<int, int>> start(v.begin(), v.begin() + middle);
    std::vector<std::pair<int, int>> end(v.begin() + middle, v.end());

    start = mergeSort(start);
    end = mergeSort(end);
    return merge(start, end);
}
//-----------------------병합 정렬-----------------------

int main()
{
    //std::cin.tie(0);
    //std::ios::sync_with_stdio(0);

    std::vector<std::pair<int, int>> v;
    int meeting = 0;

    std::cin >> meeting;

    for (int i = 0; i < meeting; i++) {
        int x = 0; int y = 0;
        std::cin >> x >> y;

        v.push_back(std::make_pair(x, y));
    }

    v = mergeSort(v);

    int c_end = v[0].second;
    int c_start = v[0].first;
    int num = 1;
    for (int i = 1; i < meeting; i++) {
        if (c_end > v[i].second) {
            c_end = v[i].second;
            c_start = v[i].first;
        }
        else {
            if (v[i].first >= c_end) {
                c_start = v[i].first;
                c_end = v[i].second;
                num++;
            }
        }
    }

    std::cout << num;
}

/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
-> 4

3
4 4
3 4
2 4
->2

3
0 0
0 0
0 0
->3

2
0 0
0 0
-> 2

4
1 2
3 100
4 5
5 6
-> 3

1
1 1
-> 1

8
1 3
2 3
3 3
4 4
5 5
6 6
7 7
3 6
-> 6

3
4 4
4 4
1 4
-> 3

3
5 7
1 6
6 11
-> 2

4
1 3
3 3
3 5
5 5
-> 4
*/