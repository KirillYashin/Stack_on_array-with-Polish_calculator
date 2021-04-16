#include "Polish.h"
#include <math.h>

const int MaxLen = 255;

void Polish::infix_to_postfix(char Formula[], char* Result)
{
    TStack<char> s(MaxLen);
    char x, token;
    int j = 0;
    TStack<char> Buf(MaxLen);
    for (int i = 0; Formula[i] != '\0'; i++)
    {
        token = Formula[i];
        if (isalnum(token)) {
            Buf.Push(token);
        }
        else {
            if (!Buf.IsEmpty()) {
                int k = 0;
                char Helper[MaxLen];
                while (!Buf.IsEmpty()) {
                    Helper[k] = Buf.Top();
                    ++k;
                    Buf.Pop();
                }
                for (int t = k - 1; t >= 0; t--) {
                    Result[j++] = Helper[t];
                }
                Result[j++] = ' ';
            }
            if (token == '(') {
                s.Push('(');
            }
            else {
                if (token == ')') {
                    while ((x = s.Pop()) != '(') {
                        Result[j++] = x;
                        Result[j++] = ' ';
                    }

                }
                else
                {
                    while (!s.IsEmpty() && precedence(token) <= precedence(s.Top()))
                    {
                        x = s.Pop();
                        Result[j++] = x;
                        Result[j++] = ' ';
                    }
                    s.Push(token);
                }
            }
        }
    }

    if (!Buf.IsEmpty()) {
        int k = 0;
        char Helper[MaxLen];
        while (!Buf.IsEmpty()) {
            Helper[k++] = Buf.Top();
            Buf.Pop();
        }
        for (int t = k - 1; t >= 0; t--) {
            Result[j++] = Helper[t];
        }
        Result[j++] = ' ';
    }

    while (!s.IsEmpty())
    {
        x = s.Pop();
        Result[j++] = x;
    }

    Result[j] = '\0';
    std::cout << Result << std::endl;
}

int Polish::precedence(char x)
{
    if (x == '(')
        return(0);
    if (x == '+' || x == '-')
        return(1);
    if (x == '*' || x == '/' || x == '%')
        return(2);

    return(3);
}

int Polish::checker(char Formula[]) {
    int left = 0, right = 0;
    for (int i = 0; Formula[i] != '\0'; i++)
    {
        if (Formula[i] == '(') {
            left++;
        }
        if (Formula[i] == ')') {
            right++;
        }
    }
    if (left == right) {
        return 0;
    }
    return abs(left - right);
}

double Polish::Calculator(char* Result) {
    int j = 0;
    double ans = 0, temp = 0;
    char mode;
    TStack<double> Buf(MaxLen);
    while (Result[j] != '\0') {
        if (std::isspace(Result[j])) {
            j++;
            continue;
        }
        if (!std::ispunct(Result[j])) {
            temp = atof(&Result[j]);
            int k = temp;
            while (k /= 10) {
                j++;
            }
            Buf.Push(temp);
        }
        mode = Result[j];
        j++;
        switch (mode)
        {
        case ' ':
            continue;
        case '+':
            ans = Buf.Pop() + Buf.Pop();
            Buf.Push(ans);
            break;
        case '-':
            ans = Buf.Pop();
            ans = Buf.Pop() - ans;
            Buf.Push(ans);
            break;
        case '*':
            ans = Buf.Pop() * Buf.Pop();
            Buf.Push(ans);
            break;
        case '/':
            ans = Buf.Pop();
            ans = Buf.Pop() / ans;
            Buf.Push(ans);
            break;
        default:
            break;
        }
    }
    ans = Buf.Pop();
    return ans;
}