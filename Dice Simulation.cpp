#include <bits/stdc++.h>
using namespace std;

void execute(char i, vector<int> &faceValues)
{
    if (i == 'N')
    {
        int temp = faceValues[1];
        faceValues[1] = faceValues[2];
        faceValues[2] = faceValues[6];
        faceValues[6] = faceValues[5];
        faceValues[5] = temp;
    }
    else if (i == 'S')
    {
        int temp = faceValues[1];
        faceValues[1] = faceValues[5];
        faceValues[5] = faceValues[6];
        faceValues[6] = faceValues[2];
        faceValues[2] = temp;
    }
    else if (i == 'E')
    {
        int temp = faceValues[3];
        faceValues[3] = faceValues[1];
        faceValues[1] = faceValues[4];
        faceValues[4] = faceValues[6];
        faceValues[6] = temp;
    }
    else
    {
        int temp = faceValues[1];
        faceValues[1] = faceValues[3];
        faceValues[3] = faceValues[6];
        faceValues[6] = faceValues[4];
        faceValues[4] = temp;
    }
}

void runCases()
{
    vector<int> faceValues(7);
    for (int i = 1; i <= 6; i++)
    {
        int x;
        cin >> x;
        faceValues[i] = x;
    }
    string in;
    cin >> in;
    for (char i : in)
    {
        execute(i, faceValues);
    }
    cout << faceValues[1] << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        runCases();
    }
}