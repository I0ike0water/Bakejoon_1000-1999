// 백준 1004 어린 왕자.cpp

#include <iostream>
#include <math.h>
#include <queue>

struct Coordinate {
    int x;
    int y;
};

bool DistanceCalc(int x, int y, int r, Coordinate dot) {
    float distance = 0.f;
    float x_distance = 0.f;
    float y_distance = 0.f;

    x_distance = dot.x - x;
    y_distance = dot.y - y;

    distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));

    if (distance < r) return true;
    else return false;
}

int main()
{
    int test = 0;
    std::cin >> test;

    std::queue<int> q;

    while (test > 0) {
        Coordinate start;
        Coordinate end;

        std::cin >> start.x >> start.y >> end.x >> end.y;

        int num_planet = 0;
        std::cin >> num_planet;

        int num_entrance = 0;

        while (num_planet > 0) {
            int x = 0; int y = 0; int r = 0;
            std::cin >> x >> y >> r;

            bool start_is_in = DistanceCalc(x, y, r,start);
            bool end_is_in = DistanceCalc(x, y, r, end);

            if (start_is_in == true && end_is_in == false) {
                num_entrance++;
            }

            if(start_is_in == false && end_is_in == true ){
                num_entrance++;
            }
            num_planet--;
        }

        q.push(num_entrance);
        test--;
    }

    while (q.empty() == false) {
        std::cout << q.front() << "\n";
        q.pop();
    }

    return 0;
}
