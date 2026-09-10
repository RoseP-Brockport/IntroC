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
    printf("Quota usage displayed as integers\n");
    printf("  Used   Quota  percent\n");
    int used = 200;
    int quota = 1000;
    for(;used <= 2000; used += 200){
        printf("%6d", used);
        printf("%8d", quota);
        int percent = ((used*100)/(quota));
        printf("%8d", percent);
        printf("%%\n");
        quota += 50;
    }

}

void pt2(){
    printf("Quota usage displayed as floats\n");
    printf("    Used           Quota          percent\n");
    float used = 200.00;
    float quota = 1000.00;
    for(;used <= 2000; used += 200){
        printf("%8.2f", used);
        printf("%16.2f", quota);
        float percent = ((used*100)/(quota));
        printf("%16.2f", percent);
        printf("%%\n");
        quota += 50;
    }


}

int main(int argc, char* argv[]){
    pt1();
    pt2();
}