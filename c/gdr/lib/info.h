#include <stdio.h>

#define BUF 128

void world_info (void) {
    
    FILE *fp;
    fp = fopen("../assets/world_info/thato_kehinde.txt", "r");
    
    char buf[BUF];
    while (fgets(buf, BUF, fp) != NULL) {
        printf("%s", buf);
    }

    fclose(fp);

    return;
}

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
