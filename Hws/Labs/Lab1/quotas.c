#include <stdio.h>
#include <stdlib.h>





void pt1(){
    // used start at 200, quota start at 1000
    // used increment by 200, quota increment by 50
    // stop when usage hits 2000
    // calc percent of quota used

    /* 
Quota usage displayed as integers

  Used   Quota  percent

   200    1000      20%

   400    1050      38%

   600    1100      54%

   800    1150      69%

  1000    1200      83%

  1200    1250      96%

  1400    1300     107%

  1600    1350     118%

  1800    1400     128%

  2000    1450     137%
  */

  /* last digit of used is on col 6, last of quota on 14, last of percent on 23*/
  /* whenever a field hits another figure we remove a space*/

  /* for used 3 spaces normally
  for quota 4 spaces normally
  for percent 6 spaces normally
  */
    int used = 200;
    int quota = 1000;

    printf("Quota usage displayed as integers\n\n");
    printf("  Used   Quota  percent\n\n");


    while (used < 2000){
        int prcnt = used/quota*10;
        char usedfrm[] = {" ", " ", " ", " ", " ", " "};
        char quotafrm[] = {" ", " ", " ", " ", " ", " ", " ", " "};
        char percentfrm[] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

        int* ptrusd = &usedfrm;
        int* ptrqut = &quotafrm;
        int* ptrprc = &percentfrm;
        int tmp = 0;



        int* tmpptr = 0;
        if(tmp = (3 - snprintf(NULL, 0, "%d",used)) != 0){
            tmpptr = ptrusd;
            tmpptr += 3;
            tmpptr += tmp;
            for(;tmp < 6; tmp++){
                *tmpptr = 
                tmpptr += 1;
            }
        }
        if(0){}
        if(0){}


        printf("\n\n");
        used += 200;
        quota += 50;

    }
}

void pt2(){

}

int main(int argc, char* argv[]){
    pt1();
    pt2();
}