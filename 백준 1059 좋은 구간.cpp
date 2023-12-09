// 백준 1059 좋은 구간.cpp

#include <iostream>

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int num = 0;
    std::cin >> num;

    int* num_list = new int[num];
    bool exist[1001]{};

    int max = 0; int min = 1001;
    for (int i = 0; i < num; i++) {
        std::cin >> num_list[i];
        exist[num_list[i]] = true;
        if (max < num_list[i]) max = num_list[i];
        if (min > num_list[i]) min = num_list[i];
    }

    int target = 0; int result = 0;
    std::cin >> target;

    for (int A = 1; A <= target; A++) {
        for (int B = target; B < max; B++) {
            bool isexist = false;
            for (int x = A; x <= B; x++) {
                if (exist[x]) {
                    isexist = true;
                    break;
                }
            }
            if (isexist == false && A != B) {
                result++;
            } 
        }
    }

    std::cout << result;

    delete[] num_list;
    return 0;
}

/*
3
7 8 9
2
-> 9

5
5 7 9 10 12
4
-> 3

4
1 7 14 10
2
->4

5
4 8 13 24 30
10
-> 5

8
3 7 12 18 25 100 33 1000
59
->1065
*/
