#include <stdio.h>
void make_space(int space)
{
    while (space--)
        printf(" ");
}
void make_star(int i)
{
    while(i--)
        printf("*");
}
int main(void)
{
    int space;
    int num;
    int i;
    int memory;
    int memory_i;

    space = 0;
    num = 0;
    i = 0;
    scanf("%d", &num);
    memory = num - 1;
    memory_i = 3;
    i = (2 * num) - 1;
    while (num--)
    {
        make_space(space);
        make_star(i);
        // make_space(space);
        printf("\n");
        space++;
        i -= 2;
    }
    space -= 2;
    while (memory--)
    {
        make_space(space);
        make_star(memory_i);
        // make_space(space);
        space--;
        memory_i += 2;
        printf("\n");
    }
    return (0);
}
// without newline
// *********
//  *******
//   *****
//    ***
//     *
//    ***
//   *****
//  *******
// *********

// with newline
// *********
//  ******* 
//   *****  
//    ***   
//     *    
//    ***   
//   *****  
//  ******* 
// *********