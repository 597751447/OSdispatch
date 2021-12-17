#include <iostream>
#include "common/utils.h"
#include "solve/srtf.h"
int main() {
    LinkList linkList;
    Create(linkList);
    Show(linkList);
    Sort(linkList);
    Srtf(linkList);
    return 0;
}
