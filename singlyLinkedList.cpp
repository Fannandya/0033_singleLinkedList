#include <iostream>
#include <string.h>
using namespace std;

class node
{
public:
    int noMhs;
    node *next;
};

class linkedList
{
    node *START;

public:
    linkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan nomor mahasiswa: ";
        cin >> nim;

        node *nodeBaru = new node;
        nodeBaru->noMhs = nim
    }
}