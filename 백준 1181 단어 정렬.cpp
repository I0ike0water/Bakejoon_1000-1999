// 백준 1181 단어 정렬.cpp

/*
#include <iostream>
#include <algorithm>
#include <string>

struct Word {
    std::string word;
};

void qsort(Word *word_list, int low, int high) {
    if (low < high) {
        int idx = low - 1;
        std::string pivot = word_list[high].word;

        for (int i = low; i < high; i++) {
            if (word_list[i].word <= pivot) { //pivot 보다 idx의 값은 낮은데 들어있는 값은 큰 경우 바꾼다는 뜻
                idx++;
                std::swap(word_list[idx], word_list[i]);
            }
        }
        std::swap(word_list[idx + 1], word_list[high]);
        int pivot_idx = idx + 1;

        qsort(word_list, low, pivot_idx - 1);
        qsort(word_list, pivot_idx + 1, high);
    }
}

void bsort(Word* word_list, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1;j++) {
            if (word_list[j].word.length() > word_list[j + 1].word.length()) {
                std::swap(word_list[j], word_list[j + 1]);
            }
        }
    }
}

int main(){
    int num_word;
    int size_idx = 0;
    std::cin >> num_word;
    std::string temp;
    
    Word* word_list = new Word[num_word];
    for (int i = 0; i < num_word; i++) {
        std::cin >> temp;
        bool not_multiple = true;
        for (int j = 0; j < size_idx; j++) {
            if (word_list[j].word == temp) {
                not_multiple = false;
                size_idx--;
                break;
            }
        }
        if (not_multiple) {
            word_list[size_idx].word = temp;
            size_idx++;
        }
    }
    qsort(word_list, 0, size_idx-1);
    bsort(word_list, size_idx);
    for (int i = 0; i < size_idx; i++) {
        std::cout << word_list[i].word << "\n";
    } 
    delete[] word_list;
}
*/
/*
#include <iostream>
#include <algorithm>
#include <string>

struct Word {
    std::string word;
};

void qsort(Word* word_list, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        std::string pivot = word_list[mid].word;

        int left = low;
        int right = high;
        while (left <= right) {
            while (word_list[left].word < pivot) left++;
            while (word_list[right].word > pivot) right--;
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

void qsort_size(Word* word_list, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        std::string pivot = word_list[mid].word;

        int left = low;
        int right = high;
        while (left <= right) {
            while (left <= right) {
                while (word_list[left].word.length() < pivot.length()) left++;
                while (word_list[right].word.length() > pivot.length()) right--;
                if (left <= right) {
                    std::swap(word_list[left], word_list[right]);
                    left++;
                    right--;
                }
            }
            qsort_size(word_list, low, right);
            qsort_size(word_list, left, high);
        }
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
        bool not_multiple = true;
        for (int j = 0; j < size_idx; j++) {
            if (word_list[j].word == temp) {
                not_multiple = false;
                break;
            }
        }
        if (not_multiple) {
            word_list[size_idx].word = temp;
            size_idx++;
        }
    }
    qsort(word_list, 0, size_idx - 1);
    qsort_size(word_list, 0, size_idx -1);
    for (int i = 0; i < size_idx; i++) std::cout << word_list[i].word << "\n";
    delete[] word_list;
}
*/

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
        
        bool not_multiple = true;
        for (int j = 0; j < size_idx; j++) {
            if (word_list[j].word == temp) {
                not_multiple = false;
                break;
            }
        }
        /*
        bool multiple = false;
        multiple = std::find(word_list, word_list + size_idx, temp);
        */
        if (not_multiple) {
            word_list[size_idx].word = temp;
            size_idx++;
        }
        //word_list + size_idx는 word_list 배열에서 i번째 원소의 메모리 주소
        
    }
    qsort(word_list, 0, size_idx - 1);
    for (int i = 0; i < size_idx; i++) std::cout << word_list[i].word << "\n";
    delete[] word_list;
}

