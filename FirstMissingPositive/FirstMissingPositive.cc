int firstMissingPositive(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] <= 0 && A[i] > n) {
            continue;
        }
        
        while (a[i] != i+1) {
            temp = a[a[i] - 1];
            a[a[i] - 1] = a[i];
            a[i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            break;
        }
    }

    if (i > 0 ) {
        return i;
    }

    return -1;
}


int main(int argc, const char *argv[])
{
    
    return 0;
}
