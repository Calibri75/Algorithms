#include <iostream>
#include <cctype>

using namespace std;

struct node{
    int data;
    node* next;

    node(int value, node* ptr = nullptr){
        data = value;
        next = ptr;
    }
};

class list{
private:
    node* head;
public:
    list(){
        head = nullptr;
    }

    ~list(){
        node* temp = head;
        while(head != nullptr){
            temp = head;
            head = temp -> next;
            delete temp;
        }
    }

    bool is_exhead(){
        if (head == nullptr) {
            return true;
        }
        else{
            return false;
        }
    }


    void print_list(){
        node* temp = head;
        while(temp != nullptr){
            cout << temp -> data ;
            if(temp -> next != nullptr){
                cout << "->";
            }
            else{
                cout << "\n";
            }
            temp = temp -> next;
        }
        if(is_exhead()){
            cout << "Список пуст!\n";
        }
    }

    void add_el(int value){
        node* temp = new node(value, head);
        head = temp;
    }

    void delete_el_value(int value) {
        int was_delete = 0;
        node *link = nullptr;
        while (head != nullptr && value == head->data) {
            link = head;
            head = head->next;
            delete link;
            was_delete = 1;
        }

        node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (value == temp->next->data) {
                link = temp->next;
                temp->next = temp->next->next;
                delete link;
                was_delete = 1;
            } else {
                temp = temp->next;
            }
        }
        if(was_delete == 0){
            cout << "Значений не найдено!\n";
        }
    }

    void delete_el_infront(int value) {

        while (head != nullptr && head->next && head->next->data == value) {
            node* link = head;
            head = head->next;
            delete link;
        }

        if (head == nullptr){
            return;
        }
        /*
         * while (temp->next != nullptr){
         *
         * }*/
        node* temp = head;
        while (temp->next != nullptr && temp->next->next) {
            if (temp->next->next->data == value) {
                node* link = temp->next;
                temp->next = temp->next->next;
                delete link;
            } else {
                temp = temp->next;
            }
        }


    }

    void delete_el_after(int value){

        if(head && head -> next && head -> data == value){
                node* link = head -> next;
                head -> next = head -> next -> next;
                delete link;
            }

        if(head == nullptr){
            return;
        }

        node* temp = head -> next;
        while(temp -> next && temp -> next -> next){
            if(temp -> data == value){
                node* link = temp -> next;
                temp -> next = temp -> next -> next;
                delete link;
                temp = temp -> next;
            }
            else{
                temp = temp -> next;
            }
        }
        if(temp -> next -> next == nullptr && temp -> data == value){
            node* link = temp -> next;
            temp -> next = nullptr;
            delete link;
        }


    }



    void find_el(int value){
        node* temp = head;
        int work = 0;
        cout << "Совпадения: \n";
        while(temp != nullptr){
            if(value == temp -> data){
                work = 1;
                cout << "[" << temp -> next << "]\n";
            }
            temp = temp -> next;

        }
        if(work == 0){
            cout << "Совпадений не найдено\n";
        }
    }

    void difference(const list& list2){
        int work = 0;
        node* temp1 = nullptr;
        node* link = nullptr;
        while(head != nullptr){
            temp1 = list2.head;
            work = 0;
            while(temp1 != nullptr){
                if(head -> data == temp1 -> data){
                    link = head;
                    head = head -> next;
                    delete link;
                    work = 1;
                    break;
                }
                temp1 = temp1 -> next;
            }
            if(work == 0){
                break;
            }
        }

        node* temp = head;
        while(temp != nullptr && temp -> next != nullptr){
            temp1 = list2.head;
            work = 0;
            while(temp1 != nullptr){
                if(temp -> next -> data == temp1 -> data){
                    link = temp -> next;
                    temp -> next = temp -> next -> next;
                    work = 1;
                    delete link;
                    break;
                }
                temp1 = temp1 -> next;
            }
            if(work == 0){
                temp = temp -> next;
            }

        }
    }

  


};

/*void difference2(const List& list2) {
        if (!head || !list2.head) return;

        Node* temp = head;
        Node* temp1= list2.head;

        do {
            if (temp->data < temp1->data) {
                temp = temp->next;
            } else if (temp->data > temp1->data) {
                temp1 = temp1->next;
                if (temp1 == list2.head) break; // дошли до конца list2
            } else {
                Node* temp2 = temp;
                temp = temp->next;

                if (temp2 == head)
                    head = head->next;

                // если удаляем последний узел
                if (temp2->next == temp2) {
                    delete temp2;
                    head = nullptr;
                    return;
                }
                temp2->prev->next = temp2->next;
                temp2->next->prev = temp2->prev;
                delete temp2;

                temp1 = temp1->next;
                if (temp1 == list2.head) break;
            }
        } while (temp != head);
    }


};*/





int main() {
    system("chcp 65001");
    list list1;
    list list2;
    for (int i{}; i < 10; ++i){
        list1.add_el(i % 2);
    }
//    list1.add_el(5);
//    list1.add_el(4);
//    list1.add_el(3);
//    list1.add_el(2);
//    list1.add_el(1);
    list1.print_list();
    for (int i{}; i < 10; ++i){
        list2.add_el(0);
    }
//    list2.add_el(6);
//    list2.add_el(7);
//    list2.add_el(3);
//    list2.add_el(2);
//    list2.add_el(1);
    list2.print_list();

    list2.difference(list2);
    list2.print_list();

    /* list1.delete_el_after(0);
     list1.print_list();
     for (int i{}; i < 10; ++i){
         list1.add_el(i % 2);
     }
     list1.print_list();
     list1.delete_el_infront(1);
     list1.print_list();
     list1.delete_el_value(1);
     list1.print_list();
     list1.delete_el_value(0);
     list1.print_list();

     list list2;
     list1.add_el(1);
     list1.add_el(2);
     list1.add_el(3);
     list1.add_el(4);
     list1.print_list();
     list1.delete_el_value(1);*/
}
