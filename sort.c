#include <omp.h>
#include <stddef.h>

inline void swap(int* lhs, int* rhs)
{
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void qsort_iter(int* a, size_t begin, size_t end)
{
    if (!(begin < end)) {
        return;
    }
    size_t left = begin, right = end;
    int pivot = a[(begin + end + 1) / 2];
    do {
        while(a[left] < pivot)
            left++;
        while(a[right] > pivot)
            right--;
        if (left <= right) {
            swap(a + left++, a + right--);
        }
    } while (left <= right);

    #pragma omp task
    {
        qsort_iter(a, begin, right);
    }
    #pragma omp task
    {
        qsort_iter(a, left, end);
    }
}

void parallel_qsort(int* base, size_t nmemb)
{
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            qsort_iter(base, 0, nmemb - 1);
        }
    }
}
