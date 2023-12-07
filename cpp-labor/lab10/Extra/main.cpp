#include <iostream>
#include "BST.h"
#include "NodeBST.h"

using namespace std;

int main() {
    BST * tree = new NodeBST();

    for (int i = 0; i < 10; ++i) {
        int r = rand() % 10;
        cout << "\n"<<i<<". Insert random number " << r << endl;
        tree->insert(r);
        cout << "Inorder: ";
        tree->print_inorder();
    }
    cout<<"\n***********************"<<endl;

    std::cout << "Test case 1: Insert 1 ";
    tree->insert( 1 );
    if (tree->find(1))
        cout << "Passed!\n";
    else
        cout << "Failed! Tree should contain 1.\n";
    tree->print_inorder();
    cout<<endl;



    cout << "Test case 2: Insert 7 ";
    tree->insert(7);
    if (tree->find(1) && tree->find(7))
        cout << "Passed!\n";
    else
        cout << "Failed! Tree should contain 1, 7.\n";
    tree->print_inorder();
    cout<<endl;

    // Test case 3: insert 18
    cout << "Test case 3: Insert 18 ";
    tree->insert(18);
    if (tree->find(18) && tree->find(7) && tree->find(1))
        cout << "Passed!\n";
    else
        cout << "Failed! Tree should contain -1, 1, 7.\n";
    tree->print_inorder();cout<<endl;

    cout<<"\nINORDER: "; tree->print_inorder();
    cout<<"\nPREORDER: "; tree->print_preorder();
    cout<<"\nPOSTORDER: "; tree->print_postorder();
    return 0;
}
