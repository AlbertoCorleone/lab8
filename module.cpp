#include <iostream>
#include "module.h"
#include <fstream>
using namespace std;

Element* enterList()
{
    Element *first, *current;
    double t_value=0;
    first=current=new Element;
    cout << "Enter value of the first element" << endl;
    cin>> current->value;
    while(true)
    {
        cout << "Enter value..."<<endl;
        cin >> t_value;
        if(t_value==-1) break;
        current->next=new Element;
        current = current->next;
        current->value=t_value;
    }
    current->next=nullptr;
    return first;
};
int size(Element* list)
{
    int result = 0;
    while(list)
    {
        result++;
        list=list->next;
    }
    return result;
}
void writeList(Element *top, string description)
{
    ofstream fout;
    fout.open(R"(C:\Users\admin\Desktop\output.txt)", ios_base::app | ios_base::ate);

    int i=0;
    Element *current;
    current = top;
    fout << description << "\r\n";
    while(current!=nullptr)
    {
        i++;
        fout << " element #"<<i<<": " << current->value << "\r\n";
        current=current->next;
    }
    fout.close();
}
Element* sort(Element *top)
{
    Element *current, *next;
    startSort:
        current = top;
        next = current->next;
        while(next!=nullptr)
        {
                if (current->value > next->value)
                {
                    double temp = current->value;
                    current->value = next->value;
                    next->value = temp;
                    goto startSort;
                }
                current = current->next;
                next = current->next;
        }
    return top;
}
Element* concatenate(Element *top1, Element *top2)
{
    Element *first, *current, *current1, *current2;
    current1 = top1;
    current2 = top2;
    first=current = new Element;
    current->value = current1->value;
    int sizel1 = size(top1);
    int sizel2 = size(top2);
    for(int i=0; i<sizel1-1; i++)
    {
        current->next = new Element;
        current = current->next;
        current1 = current1->next;
        current->value = current1->value;
    }
    current->next = new Element;
    current = current->next;
    current->value = current2->value;
    for(int i=0; i<sizel2-1; i++)
    {
        current->next = new Element;
        current = current->next;
        current2 = current2->next;
        current->value = current2->value;
    }
    current->next=nullptr;
    return first;
}

