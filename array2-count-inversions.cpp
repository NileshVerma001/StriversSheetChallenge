
#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(long long *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    long long leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    return inversions;
}

long long mergeSortAndCount(long long *arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, left, mid);
        inversions += mergeSortAndCount(arr, mid + 1, right);

        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

long long getInversions(long long *arr, int n) {
    return mergeSortAndCount(arr, 0, n - 1);
}

