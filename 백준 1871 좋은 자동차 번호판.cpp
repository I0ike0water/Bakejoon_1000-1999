// 백준 1871 좋은 자동차 번호판.cpp

#include <iostream>
#include <cmath>
#include <string>

int main()
{
    int num_license_plate;
    std::cin >> num_license_plate;
    std::string license_plate;
    bool* result = new bool[num_license_plate] {};

    for (int i = 0; i < num_license_plate; i++) {
        std::cin >> license_plate;

        int f_plate_value = (license_plate[0]-'A')*pow(26,2) + (license_plate[1]- 'A')*26 + (license_plate[2]- 'A');
        license_plate.erase(0, 4);
        int b_plate_value = stoi(license_plate);
        int nice_check = f_plate_value - b_plate_value;

        if (nice_check < 0) nice_check *= -1;
        if (nice_check <= 100) result[i] = true;
    }
    for (int i = 0; i < num_license_plate; i++) {
        if (result[i]) std::cout << "nice\n";
        else std::cout << "not nice\n";
    }
    delete[] result;
}

