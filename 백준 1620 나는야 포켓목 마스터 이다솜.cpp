// 백준 1620 나는야 포켓목 마스터 이다솜.cpp

#include <iostream>
#include <string>
#include <map>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    std::map<int, std::string> map_idx;
    std::map<std::string, int> map_name;

    int num = 0; int question = 0;
    std::cin >> num >> question;

    for (int i = 0; i < num; i++) {
        std::string name;
        std::cin >> name;
        map_idx.insert(make_pair(i + 1, name));
        map_name.insert(make_pair(name, i + 1));
    }

    while (question--) {
        std::string temp;
        std::cin >> temp;
        if (temp[0] >= '0' && temp[0] <= '9') {
            std::cout << map_idx.find(stoi(temp))->second << "\n";
        }
        else {
            std::cout << map_name.find(temp)->second << "\n";
        }
    }

    return 0;
}


/*
typedef struct dic {
    int idx;
    std::string name;
};

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int num = 0;
    int question = 0;

    std::cin >> num >> question;

    //dic* list_dic = new dic[num+1]{}; <- 버퍼 오버런
    dic* list_dic = new dic[num]{};

    for (int i = 0; i < num; i++) {
        list_dic[i].idx = i + 1;
        std::string temp;

        std::cin >> temp;
        list_dic[i].name = temp;
    }

    while (question--) {
        std::string temp;
        std::cin >> temp;
        try {
            int temp_num = std::stoi(temp);
            std::cout << list_dic[temp_num-1].name << "\n";
        } catch (const std::invalid_argument&) {
            for (int i = 0; i < num; i++) {
                if (temp == list_dic[i].name) {
                    std::cout << i + 1 << "\n";
                }
            }
        }
    }
    return 0;
}
*/