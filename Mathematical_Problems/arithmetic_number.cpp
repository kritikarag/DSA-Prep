// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

int inSequence(int A, int B, int C)
{
    // code here
    if (A == B)
        return 1;
    if (C == 0)
        return 0;
    B -= A;
    if (B % C == 0 && B / C > 0)
        return 1;
    return 0;
}