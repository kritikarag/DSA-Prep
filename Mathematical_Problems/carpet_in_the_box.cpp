// https://practice.geeksforgeeks.org/problems/230d87552a332a2970b2092451334a007f2b0eec/1

int carpetBox(int a, int b, int c, int d)
{
    // code here
    int count = 0;
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);

    while (a > c || b > d)
    {
        if (a > b)
            swap(a, b);

        if (b > d)
        {
            b /= 2;
            count++;
        }
        else if (a > c)
        {
            a /= 2;
            count++;
        }
    }
    
    return count;
}