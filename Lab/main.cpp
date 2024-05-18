#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// Định nghĩa struct kí tự và tần suất
struct CharFrequency {
    char character;
    int frequency;

    string toString() const {
        return string(1, character) + ": " + to_string(frequency);
    }
};

// Heapify cho HeapSort
void heapify(CharFrequency arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].character > arr[largest].character)
        largest = left;

    if (right < n && arr[right].character > arr[largest].character)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Thuật toán HeapSort
void heapSort(CharFrequency arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Thuật toán Shell Sort
void shellSort(CharFrequency arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            CharFrequency temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].frequency > temp.frequency; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

CharFrequency* countCharacters(const string& input, int& uniqueCount) {
    map<char, int> charCount;
    for (char c : input) {
        charCount[c]++;
    }
    uniqueCount = charCount.size();
    CharFrequency* result = new CharFrequency[uniqueCount];
    
    int i = 0;

    for (const auto& pair : charCount) {
        result[i].character = pair.first;
        result[i].frequency = pair.second;
        i++;
    }

    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    input.erase(remove(input.begin(), input.end(), ' '), input.end());

    int n;

    CharFrequency* arr = countCharacters(input, n);

    heapSort(arr, n);
    cout << "ASCII:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].character << " ";
    cout << endl;

    shellSort(arr, n);
    cout << "Frequence:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].character;
   }
   cout << "\n";
     for (int i = 0; i < n; i++) {
        cout << arr[i].frequency;
   }
    cout << endl;

    return 0;
}