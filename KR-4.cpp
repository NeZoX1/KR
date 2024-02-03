#include <iostream>
#include <string>
using namespace std;
class Task { //класс задача
public:
    string name = ""; //название
    string description = ""; //описание
    Task() : name(""), description("") {}
    Task(string name, string description) : name(name), description(description) {}
};
const int MAX_TASKS = 99; //максимальное кол-во
Task tasks[MAX_TASKS];
int numTasks = 0; //номер
void addTask() { //добавление задачи
    if (numTasks < MAX_TASKS) {
        string name = "", description = "";
        cout << "Введите название задачи: ";
        cin >> name;
        cout << "Введите описание задачи: ";
        cin >> description;
        Task newTask(name, description);
        tasks[numTasks] = newTask;
        numTasks++;
        cout << "Задача добавлена." << endl;
    } else {
        cout << "Достигнуто максимальное количество задач. Невозможно добавить еще одну." << endl;
    }
}
void deleteTask() { //удаление задачи
    if (numTasks == 0) { //проверка
        cout << "Список задач пуст." << endl;
        return;
    }
    int index;
    cout << "Введите индекс задачи для удаления: ";
    cin >> index;
    if (index < 0 || index >= numTasks) { //проверка
        cout << "Недопустимый индекс задачи." << endl;
        return;
    }
    for (int i = index; i < numTasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    numTasks--;
    cout << "Задача удалена." << endl;
}
void updateTask() { //обновление задачи
    if (numTasks == 0) { //проверка
        cout << "Список задач пуст." << endl;
        return;
    }
    int index;
    cout << "Введите индекс задачи для обновления: ";
    cin >> index;
    if (index < 0 || index >= numTasks) { //проверка
        cout << "Недопустимый индекс задачи." << endl;
        return;
    }
    string name = "", description = "";
    cout << "Введите новое название задачи: ";
    cin >> name;
    cout << "Введите новое описание задачи: ";
    cin >> description;
    tasks[index].name = name;
    tasks[index].description = description;
    cout << "Информация о задаче обновлена." << endl;
}
void displayTasks() { //отображение задач
    if (numTasks == 0) {
        cout << "Список задач пуст." << endl;
        return;
    }
    cout << "Список задач:" << endl;
    for (int i = 0; i < numTasks; i++) {
        cout << i << ". " << tasks[i].name << " - " << tasks[i].description << endl; //(нумерация задач начинается с нуля)
    }
}
int main() {
    setlocale (LC_ALL, "Russian");
    int choice = 0;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить задачу" << endl;
        cout << "2. Удалить задачу" << endl;
        cout << "3. Обновить информацию о задаче" << endl;
        cout << "4. Отобразить список задач" << endl;
        cout << "5. Выйти" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                displayTasks();
                break;
            case 5:
                cout << "Выход из программы." << endl;
                return 0;
            default:
                cout << "Недопустимый выбор." << endl;
        }
    }
    return 0;
}