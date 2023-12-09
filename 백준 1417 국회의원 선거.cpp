// 백준 1417 국회의원 선거.cpp
#include <iostream>

void sum(int list[], int temp_list[], int start, int mid, int end) {
    int s = start;
    int m = mid + 1;
    int temp = start;

    while (s <= mid && m <= end) {
        if (list[s] <= list[m]) { temp_list[temp++] = list[s++]; }
        else temp_list[temp++] = list[m++];
    }

    if (s > mid) {
        for (int i = m; i <= end; i++) temp_list[temp++] = list[i];
    }
    else {
        for (int i = s; i <= mid; i++) temp_list[temp++] = list[i];
    }

    for (int i = start; i <= end; i++) list[i] = temp_list[i];
}

void merge_sort(int list[], int temp_list[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(list, temp_list, start, mid);
        merge_sort(list, temp_list, mid + 1, end);
        sum(list, temp_list, start, mid, end);
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int candidate = 0;
    std::cin >> candidate;

    int can_list[51]{};
    int temp_list[51]{};

    int dasome = 0;
    std::cin >> dasome;
    candidate--;

    int temp = 0; int idx = 0;
    
    for (int i = 0; i < candidate; i++) {
        std::cin >> temp;
        if(temp >= dasome) can_list[idx++] = temp;
    }

    if (idx == 0) {
        std::cout << 0;
        return 0;
    }

    merge_sort(can_list, temp_list, 0, idx - 1);

    int bride = 0;
    while (dasome <= can_list[idx - 1]) {
        dasome++; 
        can_list[idx - 1]--; 
        bride++;
        merge_sort(can_list, temp_list, 0, idx - 1);

        if (dasome > can_list[idx - 1]) break;
    }

    std::cout << bride;
    return 0;
}