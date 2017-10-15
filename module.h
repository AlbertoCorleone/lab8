#include <iostream>
using namespace std;

struct Element{
    double value;
    Element* next;
};

Element* enterList();
void writeList(Element* top, string description);
Element* sort(Element* top);
int size(Element* list);
Element* concatenate(Element *top1, Element *top2);
