#include <iostream>
#include "point.h"
#include "double_sided_list.h"

#include <iostream>

int main() {

    int x=5;
    int &y=x;

    //point<int> pi(5,6);

//    ListNode<int> n2(n1);
//    ListNode<int> n3(4,&n2,&n1);

    double_sided_list<int> l;
    l.addNode(5);
    l.addNode(8);
    ListNode<int> *n1(l.get_current_node());
    //n1->print();
    l.add_node_after(n1,10);

//    printList(l);


    //l.printList();

    l.add_node_after(n1->get_next(),11);
    //l.printList();
    n1=n1->get_next();
    n1=n1->get_next();
    l.add_node_after(n1,100);
    l.printList();
//    printList(l);

//    double_sided_list<int> l(5);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
