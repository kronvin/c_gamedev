
//1
void TranslateArray(int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > 0)
        {
            numbers[i] *= 2;
        }
        else if (numbers[i] < 0)
        {
            numbers[i] = 0;
        }
        else
        {
            
        }
    }
}


//2
void ToUppercase(char str[]) 
{
    Transformation = ('a' - 'A');

    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] = str[i] - Transformation;
        }
    }
}


//3
bool IsPalindrome(const char str[])
{
    int len = 0;
    
    while (str[len] != '\0') 
    { 
        len += 1;
    }

    for (int i = 0; i < len / 2; i++) 
    {
        if (str[i] != str[len - i - 1]) 
        { 
            return false;
        }
    }
    return true;
}


//4 
static bool IsVowel(char n, char Vowels[])
{
    for (int i = 0; Vowels[i] != '\0'; i++)
    {
        if (n == Vowels[i])
        {
            return true;
        }
    };
    return false;
};

void CountVowelsConsonants(const char string[], int& vowelscount, int& consoncount)
{
    char Vowels[] = "aeiouAEIOU";
    
    for (int i = 0; string[i] != '\0'; i++)
    {
        char n = string[i];

        if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
        {
            if (IsVowel(n, Vowels))
            {
                vowelscount++;
            }
            else
            {
                consoncount++;
            };
        };
    };
}

//5
bool IsEqual(const char str1[], const char str2[])
{
    char n = 0;
    char m = 0;

    int FirstStrLen = 0;
    int SecondStrLen = 0;

    while (str1[FirstStrLen] != '\0')
    {
        FirstStrLen += 1;
    };
    while (str1[SecondStrLen] != '\0')
    {
        SecondStrLen += 1;
    };

    if (FirstStrLen != SecondStrLen)
    {
        return false;
    }
    
    for (int i = 0; i < FirstStrLen; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        };
    };
    
    return true;
};