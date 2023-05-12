#ifndef INFO_H
#define INFO_H

#include "data.h"
#include <stdio.h>

void save_data (Character * character, const char *const filename);
#define BUF 128

void world_info (void);

void print_character_info (Character *);
/*    WIP ------------ WIP 
 *
void class_info (void) {
    
    FILE *fp;
    fp = fopen("../assets/class_info/...", "r");
    
    char buf[BUF];
    while (fgets(buf, BUF, fp) != NULL) {
        printf("%s", buf);
    }

    fclose(fp);

    return;
}
*
*/
#endif // !INFO_H
