#include <iostream>
#include <vector>
using namespace std;

struct SortMetrics {
    int comparisons = 0;
    int swaps = 0;
};

void SortVs(vector<int>& arr, SortMetrics& metrics) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j)
        {
            metrics.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            metrics.swaps++;
        }
    }
}

void SortV(vector<int>& arr, SortMetrics& metrics)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            metrics.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                metrics.swaps++;
            }
            else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<int> array = { 5, 3, 8, 6, 2 };
    vector<int> original = array; 

    SortMetrics metricsVs;
    SortVs(array, metricsVs);
    cout << "После сортировки выбором: ";
    for (int num : array) cout << num << " ";
    cout << "\nСравнений: " << metricsVs.comparisons
        << ", Перестановок: " << metricsVs.swaps << endl;

    array = original;

    SortMetrics metricsV;
    SortV(array, metricsV);
    cout << "После сортировки вставками: ";
    for (int num : array) cout << num << " ";
    cout << "\nСравнений: " << metricsV.comparisons
        << ", Перестановок: " << metricsV.swaps << endl;

}