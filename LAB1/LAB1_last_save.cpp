#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* next;

    node(int value, node* ptr){
        data = value;
        ptr = next;
    }

    ~node(){
        cout << "узел удален\n";
    }
};

void create_list(node*& head, int value, int elements){
    head = new node{value, nullptr};
    node* temp = head;
    for(int i = 2; i <= elements; i++){
        cout << "Введите значение " << i << " элемента:";
        cin >> value;
        temp -> next = new node(value, nullptr);
        temp = temp -> next;
    }
}

void delete_list(node*& head){
    node* temp = head;
    while(head != nullptr){
        temp = head;
        head = temp -> next;
        delete temp;
    }
}

void print_list(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout << "[" << temp -> data << "|" << temp -> next << "]";
        if(temp -> next != nullptr){
            cout << "->";
        }
        temp = temp -> next;
    }
}

void add_el(node*& head, int value){
    node* temp = new node{value, head};
    head = temp;
}

void delete_el_value(node*& head, int value){
    node* temp = head;
    while(temp != nullptr){
        if(temp -> data = value){

        }
    }
}

void diff(node* head, node* head1){
    int work = 0;
    node* temp1 = head1;
    node* link = nullptr;
    while(head != nullptr){
        temp1 = head1;
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
        temp1 = head1;
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

void difference(node*& head, node* head1){
    int is_work; //счетчик сдвига
    node* temp = head;
    node* link = nullptr;
    node* temp1 = head1;
    while(temp != nullptr && temp -> next != nullptr){
        is_work = 0;
        temp1 = head1;
        while(temp1 != nullptr){
            if(head -> data == temp1 -> data){
                link = head;
                head = head -> next;
                delete link;
                temp = head;
                is_work = 1;
                break;
            }

            else if(temp -> next -> data == temp1 -> data){
                link = temp -> next;
                temp -> next = temp -> next -> next;
                delete link;
                is_work = 1;
                break;
            }

            else{
                temp1 = temp1 -> next;
            }
        }
        if(is_work == 0){
            temp = temp -> next;
        }
    }
}


int main() {
    system("chcp 65001");
    typedef node* link;
    int choise = 0, value, n, el, c = 1;
    link head = nullptr;
    while(true){
        cout << "Меню:\n";
        cout << "1. Создать список\n";
        cout << "2. Очистить пямять\n";
        cout << "3. Добавить элемент\n";
        cout << "4. Удалить элемент по значению\n";
        cout << "Введите операцию: \n";
        cin >> choise;
        switch (choise){
            case 1:
                cout << "Введите количество элементов:";
                cin >> el;
                cout << "Введите значение 1 элемента:";
                cin >> value;
                create_list(head, value, el);
                print_list(head);
                break;
            case 2:
                delete_list(head);
                cout << "Память очищена";
                return 0;
            case 3:
                cout << "Введите значение элемента:";
                cin >> value;
                add_el(head, value);
            case 4:
                cout << "Введите значение элемента, который хотите удалить: ";
                cin >> value;

            case 7:
                print_list(head);

        }
    }

}

/*while(value == head -> data){
           link = head -> next;
           delete head;
           head = link;
       }
       if(value == temp -> data){
           link = temp -> next;
           delete temp;
           temp = link;
       }
       else{
           temp = temp -> next;
       }
   }*/