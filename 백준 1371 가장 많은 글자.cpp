// 백준 1371 가장 많은 글자.cpp 

#include <iostream>
#include <string>
#include <queue>

int main(){
	int alphabet[26]{};
	std::string line;
	std::queue <char> q;

	while (std::getline(std::cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != ' ') alphabet[line[i] - 'a']++;
		}
	}
	int max = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			while (!q.empty()) q.pop();
			max = alphabet[i];
			q.push((i + 'a'));
		}
		else if (alphabet[i] == max) q.push((i + 'a'));
	}
	while (!q.empty()) {
		std::cout << q.front();
		q.pop();
	}
}
