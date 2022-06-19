#include<stdio.h>
#include<stdlib.h>

struct SqList
{
    int* data;
    int lengh;
    int maxSize;
};

struct SqList* NewSqList(int maxSize)
{
    struct SqList* data = (struct SqList*) malloc(sizeof(struct SqList));
    data->lengh = 0;
    data->maxSize = maxSize;
    data->data = (int*) malloc(sizeof(int) * maxSize);
    return data;
}

void PrintSqList(struct SqList* in)
{
    if (in != NULL)
    {
        for (int i = 0; i < in->lengh; ++i)
        {
            int x = in->data[i];
            printf("{%d},", x);
        }
        printf("\n");
    }
}

void SqPushBack(struct SqList* in, int item)
{
    if (in != NULL && in->lengh + 1 <= in->maxSize)
    {
        in->data[in->lengh] = item;
        ++in->lengh;
    }
}

void FreeSqList(struct SqList* in)
{
    if (in != NULL)
    {
        free(in->data);
        free(in);
    }
}

int main()
{
    struct SqList* l1 = NewSqList(10);
    for (int i = 0; i < 10; ++i)
    {
        SqPushBack(l1, i);
    }
    PrintSqList(l1);
    FreeSqList(l1);
}

