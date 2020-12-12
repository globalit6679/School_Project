#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct quick {
    int school_num, phone_num[11];
    char name[8], major[22], gender[3];
}quick;

void SWAP(quick* arr, int a, int b)
{
    quick temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void SORT(quick* arr, int m, int n)
{
    if (m < n)
    {
        int key = m;
        int i = m + 1;
        int j = n;
        while (i <= j)
        {
            while (i <= n && arr[i].school_num <= arr[key].school_num)
                i++;
            while (j > m && arr[j].school_num >= arr[key].school_num)
                j--;
            if (i > j)
                SWAP(arr, j, key);
            else
                SWAP(arr, i, j);
        }
        SORT(arr, m, j - 1);
        SORT(arr, j + 1, n);
    }
}
int main() {
    FILE* fp, * fp2;
    fp = fopen("학생 데이터.txt", "r+");
    fp2 = fopen("정렬 후 데이터.txt", "w+");
    int i = 0;
    quick sArr[50];
    printf("== 정렬 전 ==\n");
    while (!feof(fp)) {
        fscanf(fp, "%d %s %s %s %s",&sArr[i].school_num,sArr[i].name,sArr[i].major,sArr[i].phone_num,sArr[i].gender);
        printf("%d\t%s\t%s\t%s\t%s\n", sArr[i].school_num, sArr[i].name, sArr[i].major, sArr[i].phone_num, sArr[i].gender);
        i++;
    }
    SORT(sArr, 0, 49);

    printf("\n== 정렬 후 ==\n");
    for (i = 0; i < 50; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n", sArr[i].school_num, sArr[i].name, sArr[i].major, sArr[i].phone_num, sArr[i].gender);
        fprintf(fp2, "%d %s %s %s %s\n", sArr[i].school_num, sArr[i].name, sArr[i].major, sArr[i].phone_num, sArr[i].gender);
    }
    printf("\n");

    fclose(fp);
    fclose(fp2);
    return 0;
}
