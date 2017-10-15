#include <iostream>
#include <fstream>
#include "module.h"
using namespace std;

void cc_file(){
    ofstream fout;
    try {
        fout.open(R"(C:\Users\admin\Desktop\output.txt)");
    }catch(...){
        cout << "Can't create file" << endl;
    }
    fout.close();
}
int main()
{
    cc_file();
    cout << "Entering 1 List..." << endl;
    Element* l1 = enterList();

    cout << "Entering 2 List..." << endl;
    Element* l2 = enterList();

    writeList(l1, "Not sorted 1 List: ");
    sort(l1);
    writeList(l2, "Not sorted 2 List: ");
    sort(l2);

    Element *l3 = concatenate(l1, l2);
    writeList(sort(l3), "Concatenated list: ");

    return 0;
}