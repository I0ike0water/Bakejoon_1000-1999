// 백준 1181 단어 정렬 - 오류 발생 상황.cpp

#include <iostream>
#include <algorithm>
#include <string>

struct Word {
    std::string word;
};

bool compare(std::string word1, std::string word2) {
    if (word1.length() == word2.length()) return word1 < word2;
    else return word1.length() < word2.length();
}

void qsort(Word* word_list, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        std::string pivot = word_list[mid].word;

        int left = low;
        int right = high;
        while (left <= right) {
            while (compare(word_list[left].word, pivot)) left++;
            while (compare(pivot, word_list[right].word)) right--;
            if (left <= right) {
                std::swap(word_list[left].word, word_list[right].word);
                left++;
                right--;
            }
        }

        qsort(word_list, low, right);
        qsort(word_list, left, high);
    }
}

int main() {
    int num_word;
    int size_idx = 0;
    std::cin >> num_word;
    std::string temp;

    Word* word_list = new Word[num_word];
    for (int i = 0; i < num_word; i++) {
        std::cin >> temp;

        bool multiple = false;
        if ((-1) < std::find(word_list, word_list + size_idx, temp)) multiple = true;
        
        if (!multiple) {
            word_list[size_idx].word = temp;
            size_idx++;
        }
        

    }
    qsort(word_list, 0, size_idx - 1);
    for (int i = 0; i < size_idx; i++) std::cout << word_list[i].word << "\n";
    delete[] word_list;
}