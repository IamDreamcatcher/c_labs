#include "main.h"
#include "enrollee.h"
#include <assert.h>
#include <string.h>

void test_processing() {
    processing();
    FILE* result = fopen("result.txt", "r");
    FILE* output = fopen("output.txt", "r");
    if (result == NULL || output == NULL) {exit(-1);}
    
    char res[100];
    char out[100];
    while (!feof(result) && !feof(output)) {
        fscanf(result, "%s", res); 
        fscanf(output, "%s", out);
        assert(strcmp(res, out) == 0);
    }
    
    fclose(result);
    fclose(output);
}

#undef main
int main() {
    test_processing();
}
