// 백준 1238 파티.cpp

#include <iostream>
#include <vector>
#include <queue>

void dijkstra(int start, int student,
	std::vector<std::vector<std::pair<int, int>>>& list, std::vector<int>& distance) {

	std::priority_queue<std::pair<int, int>,
		std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	
	distance[start] = 0;
	pq.push({ start, distance[start]});
	while (pq.empty() == false) {
		std::pair<int, int> current = pq.top();
		pq.pop();

		for (auto next : list[current.first]) {
			if (distance[next.first] > distance[current.first] + next.second) {
				distance[next.first] = distance[current.first] + next.second;
				pq.push({ next.first, distance[next.first] });
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int student = 0; int road = 0; int party = 0;
	std::cin >> student >> road >> party;

	std::vector<std::vector<std::pair<int, int>>> list(student + 1);
	std::vector<std::vector<std::pair<int, int>>> reverseList(student + 1);

	for (int i = 0; i < road; i++) {
		int start = 0; int dest = 0; int cost = 0;
		std::cin >> start >> dest >> cost;

		list[start].push_back(std::make_pair(dest, cost));
		reverseList[dest].push_back(std::make_pair(start, cost));
	}

	int result = 0;

	std::vector<int> distance(student + 1, 10000000);
	std::vector<int> reverseDistance(student + 1, 10000000);

	dijkstra(party, student, list, distance);
	dijkstra(party, student, reverseList, reverseDistance);

	for (int i = 1; i <= student; i++) {
		result = std::max(result, distance[i] + reverseDistance[i]);
	}

	std::cout << result;
	return 0;
}
