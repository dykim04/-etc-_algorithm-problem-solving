#include <stdio.h>
int main(void)
{
    char s[101];
    int idx;
    int len;

    len = 0;
    idx = 0;
    scanf("%s", s);
    while (s[len] != '\0')
        len++;
    printf("%c", s[0]);
    while (idx++ < len && s[idx])
    {
        if (idx % 10 == 0)
            printf("\n");
        printf("%c", s[idx]);
    }
    return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     char s[101];
//     int idx;
//     int len;

//     len = 0;
//     idx = 0;
//     scanf("%s", s);
//     while (s[len] != '\0')
//     {
//         len++;
//     }
//     if (len == 1)
//     {
//         printf("%c", s[0]);
//         s[1] = '\0';
//     }
//     while(idx < len && len != 1)
//     {
//         if (idx == 0)
//         {
//             printf("%c", s[idx]);
//             // printf("%d", idx);
//             idx++;
//         }
//         if (idx % 10 != 0)
//         {
//             printf("%c", s[idx]);
//             // printf("%d", idx);
//             idx++;
//         }
//         if (idx % 10 == 0 && s[idx + 1] == '\0')
//         {
//             printf("\n");
//             printf("%c", s[idx]);
//             // printf("%d", idx);
//             // printf("%d", len);
//             idx++;
//         }
//         if (idx % 10 == 0 && s[idx + 1] != '\0')
//         {
//             printf("\n");
//             printf("%c", s[idx]);
//             // printf("%d", idx);
//             idx++;
//         }
//     }
//     return (0);
// }