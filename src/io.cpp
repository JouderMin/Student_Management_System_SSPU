//
// Created by zjy on 2021/5/5.
//
#include "io.h"
#include "FileOperation.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void menu() {
    cout << "���������ʵ������ҵ" << endl;
    cout << "ѧ����Ϣ����ϵͳ" << endl;
    cout << "������ ���� ������ �ż���" << endl;
    cout << "-------------------------" << endl;
    cout << "��ӭʹ��ѧ����Ϣ����ϵͳ�����������±���Է��ʶ�Ӧ����" << endl;
    cout << "1���½�ѧ����Ϣ" << endl;
    cout << "2���޸�ѧ����Ϣ" << endl;
    cout << "3��ɾ��ѧ����Ϣ" << endl;
    cout << "4����ʾ����ѧ����Ϣ" << endl;
    cout << "5����ѯѧ����Ϣ" << endl;
    cout << "0���˳�����" << endl;
}
void addLog() {
    StudentData temp{};
    auto * operations = new FileOperation;
    cout << "������༶" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.classCode;
    }
    cout << "������ѧ��" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.number;
    }
    cout << "����������" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.name;
    }
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    operations->addLog(temp);
    delete operations;
}
void modifyLog() {
    StudentData temp{};
    FileOperation operations;
    int numberToChange;
    cout << "��������Ҫ�޸ĵ�ѧ�����" << endl;
    cin >> numberToChange;
    cout << "�������µ�ѧ����Ϣ" << endl;
    cout << "������༶" << endl;
    cin.sync();
    cin >> temp.classCode;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.classCode;
    }
    cout << "������ѧ��" << endl;
    cin.sync();
    cin >> temp.number;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.number;
    }
    cout << "����������" << endl;
    cin.sync();
    cin.getline(temp.name, 20);
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.name;
    }
    cout << "�������һ�ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_1;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_1;
    }
    cout << "������ڶ��ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_2;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_2;
    }
    cout << "����������ŷ���" << endl;
    cin.sync();
    cin >> temp.result_course_3;
    if (cin.fail()) {
        cin.clear();
        cin.sync();
        cout << "���������" << endl;
        cin >> temp.result_course_3;
    }
    operations.modifyLog(numberToChange, temp);
}
void showLog() {
    StudentData temp{};
    FileOperation operation;
    int numberToLook;
    cout << "�������ѯѧ����Ϣ" << endl;
    cin >> numberToLook;
    if (operation.getLog(numberToLook, temp)) {
        cout << temp.number;
        cout << temp.name;
        cout << temp.classCode;
        cout << temp.result_course_1;
        cout << temp.result_course_2;
        cout << temp.result_course_3;
    } else {
        cout << "��ѯ��������ѧ���Ƿ��������";
        showLog();
    }
}
void deleteLog() {
    FileOperation operation;
    int numberToDelete;
    cout << "��������Ҫɾ��ѧ���ı��" << endl;
    cin >> numberToDelete;
    operation.deleteLog(numberToDelete);
}
void showAll() {
    FileOperation operations;
    std::vector<StudentData> temp;
    operations.allLog(temp);
    int todo = 0;
    cout << "���ܷ������밴1�����༶�����밴2����ѧ�������밴3�������������밴4,�������밴5" << endl;
    cin >> todo;
    StudentData switchtemp;
    bool risefall = 0;
    switch (todo) {
    case 1: {
        cout << "����0���������У�����1�Խ�������" << endl;
        cin >> risefall;
        int sum1 = 0;
        int sum2 = 0;
        for (auto i : temp) {
            sum1 = i.result_course_1 + i.result_course_2 + i.result_course_3;
            for (auto j : temp) {
                sum2 = j.result_course_1 + j.result_course_2 + j.result_course_3;
                if (risefall) {
                    if (sum2 > sum1) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (sum2 < sum1) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                sum2       = 0;
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
            sum1 = 0;
        }
        risefall = 0;
        cout << "����������ѧ������" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
    } break;
    case 2: {
        cout << "����0���������У�����1�Խ�������" << endl;
        cin >> risefall;
        for (auto i : temp) {
            for (auto j : temp) {
                if (risefall) {
                    if (i.classCode > j.classCode) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (i.classCode < j.classCode) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
        }
        risefall = 0;
        cout << "����������ѧ������" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
        break;
    }
    case 3: {
        cout << "����0���������У�����1�Խ�������" << endl;
        cin >> risefall;
        for (auto i : temp) {
            for (auto j : temp) {
                if (risefall) {
                    if (i.number > j.number) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                } else {
                    if (i.number < j.number) {
                        switchtemp = j;
                        j          = i;
                        i          = switchtemp;
                    }
                }
                switchtemp = {0, 0, 0, 0, 0, 0};
            }
        }
        risefall = 0;
        cout << "����������ѧ������" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
        break;
    }
    case 4: {
        int course = 0;
        cout << "����Ŀһ�ɼ������밴1������Ŀ���ɼ������밴2������Ŀ���ɼ������밴3" << endl;
        cin >> course;
        switch (course) {
        case 1: {
            cout << "����0���������У�����1�Խ�������" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_1 > j.result_course_1) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_1 < j.result_course_1) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "����������ѧ������" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        case 2: {
            cout << "����0���������У�����1�Խ�������" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_2 > j.result_course_2) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_2 < j.result_course_2) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "����������ѧ������" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        case 3: {
            cout << "����0���������У�����1�Խ�������" << endl;
            cin >> risefall;
            for (auto i : temp) {
                for (auto j : temp) {
                    if (risefall) {
                        if (i.result_course_3 > j.result_course_3) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    } else {
                        if (i.result_course_3 < j.result_course_3) {
                            switchtemp = j;
                            j          = i;
                            i          = switchtemp;
                        }
                    }
                    switchtemp = {0, 0, 0, 0, 0, 0};
                }
            }
            risefall = 0;
            cout << "����������ѧ������" << endl;
            for (auto i : temp) {
                cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " "
                     << i.result_course_3 << endl;
            }
            break;
        }
        }
    }
    case 5: {
        cout << "����������ѧ������" << endl;
        for (auto i : temp) {
            cout << i.classCode << " " << i.name << " " << i.result_course_1 << " " << i.result_course_2 << " " << i.result_course_3
                 << endl;
        }
    }
    }
}

void functionSwitch() {
    int switcher;

    while (true) {
        system("cls");
        menu();
        cin.sync();
        cin >> switcher;
        if (cin.fail()) {
            cin.clear();
            cin.sync();
            cout << "���������" << endl;
            continue;
        }
        switch (switcher) {
        case 0:
            exit(0);
        case 1:
            addLog();
            break;
        case 2:
            modifyLog();
            break;
        case 3:
            deleteLog();
            break;
        case 4:
            showAll();
            break;
        case 5:
            showLog();
            break;
        default:
            cout << "���������" << endl;
            break;
        }
    }
}
