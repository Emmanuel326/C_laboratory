int find_max(int *arr, int n)
{
        int max=arr[0];
        for(int i=1;i<n;i++)
        {
                if(arr[i]>max)max=arr[i];
        }
        return max;
}

int running_sum(int *arr, int n)
{
        int sum=0;
        for(int i=0;i<n;i++) sum += arr[i];
        return sum;

}
