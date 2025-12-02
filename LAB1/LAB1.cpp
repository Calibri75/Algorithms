#include <iostream>
#include <cctype>

using namespace std;

class node{
public:
    int data;
    node* next;

    node(int value, node* ptr = nullptr){
        data = value;
        next = ptr;
        cout << "узел [" << data << "|" << next << "] создан\n";
    }

    ~node(){
        cout << "узел [" << data << "|" << next << "] удален\n";
    }
};

bool is_exhead(node* head){
    if (head == nullptr) {
        return true;
    }
    else{
        return false;
    }
}

node* create(int value){
    node* head = new node(value);
    return head;
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
    cout << "Список: ";
    while(temp != nullptr){
        cout << "[" << temp -> data << "|" << temp -> next << "]";
        if(temp -> next != nullptr){
            cout << "->";
        }
        else{
            cout << "\n";
        }
        temp = temp -> next;
    }
    if(is_exhead(head)){
        cout << "Список пуст!\n";
    }
}

void add_el(node*& head, int value){
     node* temp = new node(value, head);
     head = temp;
}

void delete_el_value(node*& head, int value) {
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

void delete_el_infront(node*& head, int value) {

    while (head != nullptr && head->next && head->next->data == value) {
        node* link = head;
        head = head->next;
        delete link;
    }

    if (head == nullptr){
        return;
    }

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




void find_el(node* head, int value){
    node* temp = head;
    int work = 0;
    cout << "Совпадения: \n";
    while(temp != nullptr){
        if(value == temp -> data){
            work = 1;
            cout << "[" << temp -> data << "|" << temp -> next << "]\n";
        }
        temp = temp -> next;

    }
    if(work == 0){
        cout << "Совпадений не найдено\n";
    }
}

void difference(node*& head, node* head1){
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

void create_list_2(node*& head1){
    int elements, value;
    cout << "Введите количество элементов: ";
    cin >> elements;
    while(elements < 0){
        cout << "Неправильное значение";
        cin >> elements;
    }
    if(elements == 0){
        head1 = nullptr;
        return;
    }
    cout << "Введите 1 элемент: ";
    cin >> value;
    head1 = new node(value);
    node* temp1 = head1;

    for(int i = 2; i <= elements; i++) {
        cout << "Введите значение " << i << " элемента:";
        cin >> value;
        temp1->next = new node(value, nullptr);
        temp1 = temp1->next;
    }
}

int main() {
    system("chcp 65001");
    int choice = 0, value;
    node* head = nullptr;
    node* head1 = nullptr;


    while(true){
        cout << "Меню:\n";
        cout << "1. Создать список\n";
        cout << "2. Очистить пямять\n";
        cout << "3. Добавить элемент\n";
        cout << "4. Удалить элемент по значению\n";
        cout << "5. Удалить элемент перед каждым вхождением\n";
        cout << "6. Поиск элемента по его значению\n";
        cout << "7. Вывести список\n";
        cout << "8. Разность двух списков\n";
        cout << "9. Выход\n";
        cout << "\n";
        cout << "Введите номер операции: ";

        if (!(cin >> choice)) {
            cout << "Неверный выбор!\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice){
            case 1:
                cout << "Выбранная функция: Создать список\n";
                if(head != nullptr){
                    cout << "Список уже создан\n";
                    break;
                }
                cout << "Введите значение 1 элемента:";
                if (!(cin >> value)) {
                    cout << "Введите целое число!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                head = create(value);
                print_list(head);
                cout << "\n";
                break;
            case 2:
                cout << "Выбранная функция: Очистить пямять\n";
                delete_list(head);
                cout << "Память очищена\n";
                cout << "\n";
                break;
            case 3:
                cout << "Выбранная функция: Добавить элемент\n";
                if(is_exhead(head)){
                       cout << "Список пуст!\n";
                       break;
                }
                cout << "Введите значение элемента:";
                if (!(cin >> value)) {
                    cout << "Введите целое число!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                add_el(head, value);
                print_list(head);
                cout << "\n";
                break;
            case 4:
                cout << "Выбранная функция: Удалить элемент по значению\n";
                if(is_exhead(head)){
                    cout << "Список пуст!\n";
                    break;
                }
                cout << "Введите значение элемента, который хотите удалить: ";
                if (!(cin >> value)) {
                    cout << "Введите целое число!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                delete_el_value(head, value);
                print_list(head);
                cout << "\n";
                break;
            case 5:
                cout << "Выбранная функция: Удалить элемент перед каждым вхождением\n";
                if(is_exhead(head)){
                    cout << "Список пуст!\n";
                    break;
                }
                cout << "Введите значение: ";
                if (!(cin >> value)) {
                    cout << "Введите целое число!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                delete_el_infront(head, value);
                print_list(head);
                cout << "\n";
                break;
            case 6:
                cout << "Выбранная функция: Поиск элемента по значению\n";
                if(is_exhead(head)){
                    cout << "Список пуст!\n";
                    break;
                }
                cout << "Введите значение: ";
                if (!(cin >> value)) {
                    cout << "Введите целое число!\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
                find_el(head, value);
                break;
            case 7:
                cout << "Выбранная функция: Вывести список\n";
                if(is_exhead(head)){
                    cout << "Список пуст!\n";
                    break;
                }
                print_list(head);
                cout << "\n";
                break;
            case 8:
                cout << "Выбранная функция: Разность двух списков\n";
                if(is_exhead(head)){
                    cout << "Первый список пуст!\n";
                    break;
                }
                cout << "Создайте 2 список\n";
                create_list_2(head1);
                print_list(head1);
                print_list(head);
                difference(head, head1);
                cout << "Результат разности: \n";
                print_list(head);
                cout << "\n";
                break;
            case 9:
                cout << "Выход";
                return 0;
            default:
                cout << "Введите число соответсвующее меню\n";
                break;
        }
    }

}