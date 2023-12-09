// 백준 1302 베스트셀러.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int book = 0;
    std::cin >> book;

    std::string book_name;
    std::string* book_list = new std::string[book]{};
    std::vector<std::string> result_list;

    int* book_list_num = new int[book] {};
    int book_case = 0;
    int max = 1;

    while (book--) {
        std::cin >> book_name;
        bool isNew = true;
        for (int i = 0; i < book_case; i++) {
            if (book_list[i] == book_name) {
                isNew = false;
                book_list_num[i]++;

                if (max == book_list_num[i])result_list.push_back(book_name);
                else if (max < book_list_num[i]) {
                    max = book_list_num[i];
                    if (result_list.size() == 1) break;
                    result_list.clear();
                    result_list.push_back(book_name);
                }

                break;
            }
        }

        if (isNew) {
            book_list[book_case] = book_name;
            book_list_num[book_case]++;
            book_case++;

            if (max == 1)result_list.push_back(book_name);
        }
    }

    std::sort(result_list.begin(), result_list.end());

    std::cout << result_list[0];

    delete[] book_list_num;
    delete[] book_list;
    return 0;
}
