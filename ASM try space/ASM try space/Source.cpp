
#include <iostream>
using namespace std;
class String_Operations
{
public:
    void length(char* str)
    {
        cout << "Enter the String: ";
        cin.getline(str, 100);
        int i = 0;
        while (str[i])
            i++;
        cout << "The length of the String is: " << i << endl;
    }
    void copy(char* s1, char* s2)
    {
        int j;
        cout << "Enter the Original String: ";
        cin.getline(s1, 100);
        for (j = 0; s1[j] != '\0'; j++)
        {
            s2[j] = s1[j];
        }
        s2[j] = '\0';

        cout << "Original String = " << s1 << endl;
        cout << "Copied String = " << s2 << endl;
    }
    void concatenate(char* str1, char* str2)
    {
        int n, m = 0;
        cout << "Enter the First String: ";
        cin.getline(str1, 100);
        cout << "Enter the Second String: ";
        cin.getline(str2, 100);
        for (m = 0; str1[m] != '\0'; m++)
            ;
        for (n = 0; str2[n] != '\0'; n++)
        {
            str1[m] = str2[n];
            m++;
        }
        str1[m] = '\0';
        cout << "The Concatenated String is: " << str1 << endl;
    }
    int compare(char* a, char* b)
    {
        int flag = 0, i = 0;
        cout << "Enter the First String: ";
        getchar();
        cin.getline(a, 100);
        cout << "Enter the Second String: ";
        getchar();
        cin.getline(b, 100);
        while (a[i] != '\0' && b[i] != '\0')
        {
            if (a[i] != b[i])
            {
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 0)
        {
            cout << "Strings are same..!" << endl;
            return 0;
        }
        else
        {
            cout << "Strings are not same..!" << endl;
            return 1;
        }
    }
    void reverse(char* s)
    {
        cout << "Enter the String: ";
        cin.getline(s, 100);
        int len = 0;
        while (s[len])
        {
            len++;
        }
        cout << "The Reversed String is: ";
        for (int i = len - 1; i >= 0; i--)
            cout << s[i];
    }
};
int main()
{
    int a;
    cin >> a;
    int* arr;
    arr = (int*)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < a; i++)
    {
        cout << arr[i];
    }

}