// 백준 1940 주몽

#include <iostream>

int main(){
    int material, num;
    std::cin >> material >> num;

    int* l_material = new int[material];
    for (int i = 0; i < material; i++) std::cin >> l_material[i];

    int armor = 0;
    for (int i = 0; i < material-1; i++) {
        for (int j = i + 1; j < material; j++) {
            if (l_material[i] + l_material[j] == num) {
                armor++;
                break;
            }
        }
    }
    std::cout << armor;
    delete[] l_material;
}
