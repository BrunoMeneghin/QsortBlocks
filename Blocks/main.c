//
//  main.c
//  Blocks
//
//  Created by Bruno Meneghin on 29/10/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
#pragma mark # Declaring & Using block literal
    int multplier = 3;
    
    int (^ onBlock)(int) = ^(int number) {
        return number * multplier;
    };
    
    printf("%d\n", onBlock(7));

#pragma mark # Block directly
    char *charCitys[3] = { "Uraí", "Londrina", "Curitiba" };
    
    qsort_b(charCitys, 3, sizeof(char *), ^(const void *l, const void *r) {
        char *onLeftSide = *(char **)l;
        char *onRightSide = *(char **)r;
        
        return strncmp(onLeftSide, onRightSide, 1);
    });
    
    for (int index=0; index<3; index++) {
        printf("sorted: %s ", charCitys[index]);
    }
    
    return 0;
}
