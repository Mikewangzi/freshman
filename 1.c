// #include <stdio.h>

// typedef struct 
// {
//     int elem[100];
//     int last;
// }seqlist;
// int main()
// {
//     seqlist *la,*lb,*lc;
//     int i=0,j=0,k=0;
//     while(i<=la->last&&j<=lb->last)
//     {
//         if (la->elem[i]<=lb->elem[j])
//         {
//             lc->elem[k]=la->elem[i];
//             i++;
//             k++;
//         }
//         else    
//         {
//             lc->elem[k]=lb->elem[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<=la->last)
//     {
//         lc->elem[k]=la->elem[i];
//         i++;
//         k++;
//     }
//     while(j<=lb->last)
//     {
//         lc->elem[k]=lb->elem[j];
//         j++;
//         k++;
//     }
//     lc->last=la->last+lb->last+1;
// }
// #include <stdio.h>
// int main()
// {
//     int letter[26]={0};
//     char ch;
//     int i;
//     while((ch=getchar())!='\n')
//     {
//         if(ch>='a'&&ch<='z')
//         {
//             i=ch-'a';
//             letter[i]++;
//         }
//         else
//             continue;
//     }
//     for(int i=0;i<26;i++)
//     {
//         printf("%c ",'a'+i);
//     }
//     printf("\n");
//     for(int i=0;i<26;i++)
//     {
//         printf("%d ",letter[i]);
//     }
//     return 0;
// }
