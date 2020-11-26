#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct quick {
    int school_num;
    char name[8], major[22], gender[3], phone_num[12];
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
    quick s[50];
    int i = 0;
    for (i = 0; i < 50; i++)
    {
        printf("Student Information (학번, 이름, 학과, 전화번호, 성별)\n");
        printf("학번 입력 : ");
        scanf_s("%d", &s[i].school_num);
        printf("이름 입력 : ");
        scanf("%s", s[i].name);
        printf("학과 입력 : ");
        scanf("%s", s[i].major);
        printf("전화번호 입력 : ");
        scanf("%s", s[i].phone_num);
        getchar();
        printf("성별 입력(남/여) : ");
        scanf("%s", s[i].gender);
    }
    SORT(s, 0, 49);
    printf("\n== 정렬 후 ==\n");
    for (i = 0; i < 50; i++)
        printf("%d\t%s\t%s\t%s\t%s\n", s[i].school_num, s[i].name, s[i].major, s[i].phone_num, s[i].gender);
    printf("\n");
    return 0;
}
