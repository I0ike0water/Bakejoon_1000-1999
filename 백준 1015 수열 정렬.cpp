// 백준 1015 수열 정렬.cpp

#include <iostream>

int main()
{
    int size = 0;
    std::cin >> size;

    int max = 0;
    int num_exist[1001]{};
    bool isused[1001]{};
    int num_list[1001]{};

    int* original_list = new int[size]{};

    int num = 0;
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        original_list[i] = num;

        num_exist[num]++;
    }

    int count = 0;
    for (int i = 0; i < 1001; i++) {
        if (num_exist[i] > 0 && isused[i] == false) {
            num_list[i] = count;
            count += num_exist[i];
        }
    }

    for (int i = 0; i < size; i++) {
        int temp = original_list[i];
        std::cout << num_list[temp] << " ";
        num_list[temp]++;
    }

    delete[] original_list;
    return 0;
}

/*
5
1 0 1 0 1
->
2 0 3 1 4

3
7 4 2
->
2 1 0

50
302 251 425 720 122 441 752 229 918 44 927 728 372 82 410 46 641 499 700 929
509 901 577 770 130 643 338 571 742 78 327 64 925 147 622 197 686 474 254 877
896 623 753 583 946 740 479 498 826 724
->
12 10 17 33 5 18 38 9 45 0 47 35 15 4 16 1 29 22 32 48 23 44 25 40 6 30 14 24 
37 3 13 2 46 7 27 8 31 19 11 42 43 28 39 26 49 36 20 21 41 34
*/
