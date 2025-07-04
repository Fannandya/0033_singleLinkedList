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
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        node *previous = START;
        node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMha tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodeBaru->next = current;
        previous->next = nodeBaru;
    }
    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        node *current, *previous;
        if (!search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nLis Kosong\n";
        }
        else
        {
            cout << "\nData didalam lis adalah:\\n";
            node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    linkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "Menu" << endl;
        cout << "1. menambahkan data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl;
        cout << "masukkan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
        {
            mhs.addNode();
            break;
        }

        case '2':
        {
            if (mhs.listEmpty())
            {
                cout << endl;
                cout << "list kosong" << endl;
                break;
            }
            cout << endl;
            cout << "\nmasukkan no mahasiswa yang akan dihapus: ";
            cin >> nim;
            if (mhs.delNode(nim) == false)
                cout << endl;
            cout << "data tidak ditemukan" << endl;
            else
            {
                cout << endl;
                cout << "data dengan nomor mahasiswa " << nim << "berhasil dihapus" << endl;
            }
        }
        break;
        case '3':
        {
            mhs.traverse();
        }
        break;

        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << "\nlist kosong\n";
                break;
            }

            node *previous, *current;
            cout << endl;
            cout << "masukkan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.search(nim, &previous, &current) == false)
            {
                cout << endl;
                cout << "data ditemukan" << endl;
            }
            else
            {
                cout << endl;
                cout << "data ditemukan" << endl;
                cout << "\nno mahasiswa: " << current->noMhs << endl;
                cout << "\n";
            }
        }

        case 5:
        {

            break;
        default:
        {
            cout << "pilihan salah !." << endl;
        }
        break;
        }
        }
        while (ch != '5')
            ;
    }
}