// 백준 1085 직사각형에서 탈출.cpp

#include <iostream>
#include <algorithm>

int main(){
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;
	int distance[4] = {x, y , w-x, h-y};
	std::sort(distance, distance + 4);
	std::cout << distance[0];
}
