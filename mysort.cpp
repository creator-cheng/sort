#include<bits/stdc++.h>
using namespace std;
void maopao(vector<int> &array)
{
    cout<<"start maopao paixu!"<<endl<<endl;
    int n = array.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 2; j >= i; j--)
        {
            if(array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void xuanze(vector<int> &array)
{
    cout<<"start xuanze paixu!"<<endl<<endl;
    int n = array.size();
    for(int i = 0; i < n; i++)
    {
        int min_i = i;
        for(int j = i + 1; j < n; j++)
        {
            if(array[min_i] > array[j])
            {
                min_i = j;
            }
        }
        swap(array[min_i], array[i]);
    }
}

void charu(vector<int> &array)
{
    cout<<"start charu paixu!"<<endl<<endl;
    int n = array.size();
    for(int i = 1; i < n; i++)
    {
        if(array[i - 1] > array[i])
        {
            int cur = array[i];
            int j = i - 1;
            while(j >= 0 && array[j] > cur)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = cur;
        }
    }
}

void xier(vector<int> &array)
{
    cout<<"start xier paixu!"<<endl<<endl;
    int n = array.size();
    int gap = n / 2;
    while(gap > 0)
    {
        for(int i = gap; i < n; i += gap)
        {
            if(array[i - gap] > array[i])
            {
                int cur = array[i];
                int j = i - gap;
                while(j >= 0 && array[j] > cur)
                {
                    array[j + gap] = array[j];
                    j -= gap;
                }
                array[j + gap] = cur;
            }
        }
        gap /= 2;
    }
}

void heapAdjust(vector<int> &array, int s, int m)
{
    int j, temp;
    temp = array[s];
    for(j = 2 * s + 1; j <= m; j = 2 * s + 1)
    {
        if(j < m && array[j] < array[j + 1])j++;

        if(temp > array[j])break;

        array[s] = array[j];
        s = j;
    }
    array[s] = temp;
}
void dui(vector<int> &array)
{
    cout<<"start dui paixu!"<<endl<<endl;
    int n = array.size();
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapAdjust(array, i, n - 1);
    }

    for(int i = n - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapAdjust(array, 0, i - 1);
    }
}

int getStand(vector<int> &array, int i, int j)
{
    int key = array[i];
    while(i < j)
    {   
        while(i < j && array[j] >= key)
        {
            j--;
        }
        swap(array[i], array[j]);

        while(i < j && array[i] <= key)
        {
            i++;
        }
        swap(array[i], array[j]);
    }
    return i;
}
void quickSort(vector<int> &array, int i, int j)
{
    if(i < j)
    {
        int m = getStand(array, i, j);
        quickSort(array, i, m - 1);
        quickSort(array, m + 1, j);
    }
}
void kuaipai(vector<int> &array)
{
    cout<<"start kuaipai paixu!"<<endl<<endl;
    quickSort(array, 0, array.size() - 1);
}

void merge(vector<int> &array, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    vector<int>tem(right - left + 1);
    int p = 0;
    while(i <= mid && j <= right)
    {
        if(array[i] <= array[j])
        {
            tem[p++] = array[i++];
        }
        else
        {
            tem[p++] = array[j++];
        }
    }
    while(i <= mid)tem[p++] = array[i++];

    while(j <= right)tem[p++] = array[j++];

    for(int k = left; k <= right; k++)
    {
        array[k] = tem[k - left];
    }

}
void mergeSort(vector<int> &array, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}
void guibing(vector<int> &array)
{
    cout<<"start guibing paixu!"<<endl<<endl;
    mergeSort(array, 0, array.size() - 1);
}


int main()
{
    srand((int)time(0));
    vector<int> array(200);
    for (int i = 0; i < array.size(); i++)
    {
        array[i] = rand() % 100;
    }
    cout<<"before sort: "<<endl;
    for (int i = 0; i < array.size(); i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;

    // kuaipai(array);
    guibing(array);

    cout<<"after sort: "<<endl;
    for (int i = 0; i < array.size(); i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl<<endl;

    bool flag = true;
    for (int i = 0; i < array.size() - 1; i++)
    {
        if(array[i] > array[i + 1])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout<<"sort successfully!"<<endl<<endl;
    }
    else
    {
        cout<<"sort error!"<<endl<<endl;
    }
    
    return 0;
}