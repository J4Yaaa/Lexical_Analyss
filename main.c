#include "lexical_analysis.h"

int main()
{
    char str[] = "#include <stdio.h> int main(){printf(\"hello world\")return 0;}";
    analysis(str);
    return 0;
}
