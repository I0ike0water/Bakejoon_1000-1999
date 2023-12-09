// 백준 1463 1로 만들기

#include <iostream>
#include <algorithm>

int make_1(int num) {
    int* result_list = new int[num + 1]{};
    result_list[1] = 0; result_list[2] = 1; result_list[3] = 1;

    for (int i = 4; i < num+1; i++) {
        result_list[i] = result_list[i-1] + 1;
        
        if(i % 3 == 0){
            result_list[i] = std::min(result_list[i], result_list[i / 3] + 1);
        }

        if (i % 2 == 0) {
            result_list[i] = std::min(result_list[i], result_list[i / 2] + 1);
        }
    }

    return result_list[num];
}

int main()
{
    int num = 0;
    std::cin >> num;
    
    printf("%d", make_1(num));
    return 0;
}

/*
6
->2

12
->3

10
->3

11
->4

2
->1

1001
->10

1
->0
*/