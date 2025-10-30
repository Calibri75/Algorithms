#include <iostream>
#include <cctype>
class node;
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = this;//указание на текущий элемент
        prev = this;

    }

    ~Node() {
        cout << "Удалён узел: " << data << endl;
    }
};

void create(Node*& head) {
    int value;
    cout << "Введите значение: ";
    cin >> value;
    head = new Node(value);
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "Список пуст!\n";
        return;
    }
    Node* temp = head;
    do {
        cout << "[" << temp->data <<"|"<< temp->next<<"] ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


void deleteAll(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        Node* temp1 = temp->next;
        delete temp;
        temp = temp1;
    } while (temp != head);
    head = nullptr;
}

void add_el_sorted(Node*& head, int value) {
    Node* temp = new Node(value);

    if (head == nullptr) {
        head = temp;
        return;
    }

    if (value < head->data) {
        Node* temp1 = head->prev;
        temp->next = head;
        temp->prev = temp1;
        head->prev = temp;
        temp1->next = temp;
        head = temp;
        return;
    }

    Node* temp1 = head;
    do {
        if (value >= temp1->data && value <= temp1->next->data) {
            Node* temp2 = temp1->next;
            temp1->next = temp;
            temp->prev = temp1;
            temp->next = temp2;
            temp2->prev = temp;
            return;
        }
        temp1 = temp1->next;
    } while (temp1 != head);

    Node* temp2 = head->prev;
    temp2->next = temp;
    temp->prev = temp2;
    temp->next = head;
    head->prev = temp;
}


/*void deleteValue(Node*& head, int value) {
    if (head == nullptr) return;
    Node* temp = head;
    Node* temp1 = nullptr;
    do {
        if (temp->data == value) {

            if (temp == head) {
                   head = head->next;
            }

            temp1 = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = temp->next;
            delete temp1;
        }
        else{
            temp = temp -> next;
        }
    } while (temp != head);
}*/

void deleteValue(Node*& head, int value) {
    if (head == nullptr) return;

    while (head->data == value) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* toDelete = head;
        head = head->next;
        toDelete->prev->next = head;
        head->prev = toDelete->prev;
        delete toDelete;
    }


    Node* temp = head->next;
    while (temp != head) {
        Node* temp1 = temp->next;
        if (temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        temp = temp1;
    }
}





void delete_el_sled(Node*& head, int value) {
    if (head == nullptr) return;
    Node* temp = head;
    do {
        if (temp->data == value && temp->next != temp) {
            Node* temp1 = temp->next;

            if (temp1 == head) {
                head = head->next;
            }

            temp->next = temp1->next;
            temp1->next->prev = temp;
            delete temp1;
        }
        temp = temp->next;
    } while (temp != head);

}

void search(Node* head, int value) {
    if (head == nullptr) {
        cout << "Список пуст!\n";
        return;
    }
    Node* temp = head;
    do {

        if (temp->data == value) {
            cout << "Найден элемент: " << temp->data << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Элемент " << value << " не найден!\n";
}
void create_list2(Node*& new_head) {
    int el, value;
    cout << "Введите количество элементов:\n";
    cin >> el;


    if (el <= 0) {
        cout << "Список не создан: количество элементов должно быть больше 0.\n";
        new_head = nullptr;
        return;
    }

    cout << "Введите значение элемента:\n";
    cin >> value;
    new_head = new Node(value);
    Node* new_temp = new_head;

    for (int i = 2; i <= el; i++) {
        cout << "Введите значение " << i << " элемента:\n";
        cin >> value;
        new_temp->next = new Node(value);
        new_temp->next->prev = new_temp;
        new_temp = new_temp->next;
    }

    new_temp->next = new_head;
    new_head->prev = new_temp;
}
/*
void difference(Node*& head, Node* new_head) {
    int work = 0;
    Node* temp = head;
    Node* new_temp=nullptr;
    Node* temp1=nullptr;
    if (head==nullptr) {
        cout << "Список пуст!\n";
        return;
    }
    do {
        new_temp=new_head;
        work=0;
        do {
            if (head->data==new_temp->data) {
                temp1=head;
                head->prev->next=head -> next;
                head->next->prev=head->prev;
                head=head->next;
                delete temp1;
                work=1;
            }

            else if (temp->next->data==new_temp->data) {
                temp1=temp->next;
                temp->next=temp->next->next;
                temp->next->prev=temp;
                delete temp1;
                work=1;

            }
            else {
                new_temp=new_temp->next;
            }

        }while (new_temp!=new_head);
        if (work==0) {
            temp=temp->next;
        }

    }while (temp!=head and temp!=nullptr);



}
*/

void difference(Node*& head, Node* new_head) {
    if (head == nullptr) {
        cout << "Список пуст!\n";
        return;
    }

    Node* new_temp = nullptr;

    while (true) {
        int work = 0;
        new_temp = new_head;
        do {
            if (head->data == new_temp->data) {
                Node* toDelete = head;

                if (head->next == head) {
                    delete head;
                    head = nullptr;
                    return;
                }

                head->prev->next = head->next;
                head->next->prev = head->prev;

                head = head->next;
                delete toDelete;

                work = 1;
                break;
            }
            new_temp = new_temp->next;
        } while (new_temp != new_head);

        if (work == 0){
            break;
        }
    }


    Node* temp = head->next;
    while (temp != head) {
        Node* temp1 = temp->next;
        new_temp = new_head;

        do {
            if (temp->data == new_temp->data) {
                // перенастраиваем ссылки
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            new_temp = new_temp->next;
        } while (new_temp != new_head);
        temp = temp1;
    }
}




int main() {
    system("chcp 65001");
    Node* head = nullptr;
    Node* new_head = nullptr;
    int ch, value;


        while (true) {
            cout << "\nМеню:\n";
            cout << "1. Создать список\n";
            cout << "2. Очистить память\n";
            cout << "3. Добавить элемент (по возрастанию)\n";
            cout << "4. Удалить элемент по значению\n";
            cout << "5. Поиск элемента\n";
            cout << "6. Печать списка\n";
            cout << "7. Удалить элемент после каждого вхождения\n";
            cout << "8. Разность двух списков\n";
            cout<<"9.Выход\n";
            cout << "Ваш выбор: \n";
            if (!(cin >> ch)) {
                cout << "Неверный выбор! Введите число!\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }


            switch (ch) {
                case 1:
                    if (head!=nullptr) {
                        cout<<"Список создан!Выберете другое действие или очистите список.\n";
                        break;
                    };

                    create(head);
                    print(head);
                    break;
                case 2:
                    deleteAll(head);
                    cout << "Список очищен!\n";
                    break;
                case 3:
                    cout << "Введите значение: ";
                    cin >> value;
                    add_el_sorted(head, value);
                    print(head);
                    break;
                case 4:
                    cout << "Введите значение: ";
                    cin >> value;
                    deleteValue(head, value);
                    print(head);
                    break;
                case 5:
                    cout << "Введите значение: ";
                    cin >> value;
                    search(head, value);
                    break;
                case 6:
                    print(head);
                    break;
                case 7:
                    cout << "Введите значение: ";
                    cin >> value;
                    delete_el_sled(head, value);
                    print(head);
                    break;
                case 8:
                    cout << "Функция: Разность двух списков\n";
                    cout << "Создайте 2 список:\n";
                    create_list2(new_head);
                    print(new_head);
                    print(head);
                    difference(head, new_head);
                    cout << "Результат:\n";
                    print(head);
                    break;
                case 9:
                    deleteAll(head);
                    cout<<"Выход\n";
                    break;


                default:
                    cout << "Неверный выбор! Введите число, соответствующее пункту меню!\n";
            }
        }
}
