#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)                                 //��VS�������к���ʹ��strcpy�������Ĵ���
using namespace std;
const int N = 100;
struct Date {                                                 //����ṹ�����
    int year;
    int month;
    int day;
};
struct employee {
    string Id;
    char Name[50];
    char Sex;
    char Title[20];
    char Major[20];
    Date birthday;
    char Telephone[12];
    char Address[50];
}; employee employeeinfo[N];

//----------------------------------------------------------------------------------------
//txt�ļ�д�뺯��
void write() {
    ofstream outfile("employeerecords.txt", ios::out);           //�����ļ�
    if (!outfile) {                                              //����ļ�����ʧ�ܣ�����ֹ��������
        cout << "�ļ�����ʧ��";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (strcmp(employeeinfo[i].Name, "0") == 0)              //�����ж�
            continue;
        outfile << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
        outfile << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
        outfile << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
        outfile << left << setw(8) << setfill(' ') << employeeinfo[i].Title;
        outfile << left << setw(10) << setfill(' ') << employeeinfo[i].Major;
        outfile << left << setw(6) << setfill(' ') << employeeinfo[i].birthday.year << left << setw(4) << employeeinfo[i].birthday.month << left << setw(4) << employeeinfo[i].birthday.day << "   ";
        outfile << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
        outfile << left << setw(15) << setfill(' ') << employeeinfo[i].Address << endl;
    }
    outfile.close();                                             //�ر��ļ�
}
//-----------------------------------------------------------------------------
//�ļ���ȡ����
void read() {
    ifstream infile("employeerecords.txt", ios::in);              //�����ļ������������ԡ�������ʽ���ļ�
    if (!infile)
        cout << "�ļ���ʧ�ܣ�";
    int i = 0;
    while (!infile.eof() && i < N) {                            //���ļ��������λ��ʱ��ֹѭ��
        infile >> employeeinfo[i].Id;
        infile >> employeeinfo[i].Name;                          //���ļ��е����ݸ�ֵ���ṹ�����
        infile >> employeeinfo[i].Sex;
        infile >> employeeinfo[i].Title;
        infile >> employeeinfo[i].Major;
        infile >> employeeinfo[i].birthday.year;
        infile >> employeeinfo[i].birthday.month;
        infile >> employeeinfo[i].birthday.day;
        infile >> employeeinfo[i].Telephone;
        infile >> employeeinfo[i].Address;
        i++;
    }
    infile.close();                                               //�ر��ļ�
}

//------------------------------------------------------------------------------------
//ְԱ��Ϣ��Ӻ���

//  ���Ա����Ϣʱ�Զ�����Ա��Id

//  Ա��IdΨһ�Ҳ����޸�
void infoaddition() {
    int p[1000];                                                  //����Id��
    for (int i = 1; i < 1000; i++) {
        p[i] = i;
    }
    for (int x = 0; x < N; x++) {
        if (strcmp(employeeinfo[x].Name, "0") == 0) {             //�����������ݣ������ĵ�һ��������Ԫ�ؿ�ʼ��ֵ
            cout << "Ҫ��ӵ�ְԱ��Ϣ:" << endl;
            cout << "����" << endl;
            cin >> employeeinfo[x].Name;
            cout << "�Ա�" << endl;
            cin >> employeeinfo[x].Sex;
            cout << "ְ��" << endl;
            cin >> employeeinfo[x].Title;
            cout << "רҵ" << endl;
            cin >> employeeinfo[x].Major;
            cout << "��������-��" << endl;
            cin >> employeeinfo[x].birthday.year;
            cout << "��������-��" << endl;
            cin >> employeeinfo[x].birthday.month;
            cout << "��������-��" << endl;
            cin >> employeeinfo[x].birthday.day;
            cout << "�绰" << endl;
            cin >> employeeinfo[x].Telephone;
            cout << "��ͥ��ַ" << endl;
            cin >> employeeinfo[x].Address;
            for (int a = 0; a < 100; a++) {
                if (!p[a] == 0) {
                    employeeinfo[x].Id = p[a];                 
                    p[a] = 0;
                }
                else
                    break;
            }
            cout << "��ӳɹ���" << endl;
            return;
        }
    }
}

//--------------------------------------------------------------------------------
//ְԱ��Ϣɾ������
void infodelete() {
    string a;
    cout << "����������Ա��Id: " << endl;
    cin >> a;
    cout <<"Id  "<< "����     " << "�Ա� " << "ְ��  " << " רҵ " << "     ��������  " << "  �绰����    " << " ��ַ          " << endl;
    int i,j=0;
    for (i = 0; i < N; i++) {                                             
        if (employeeinfo[i].Name==a||employeeinfo[i].Id==a) {                        //�������飬Ѱ����������Ϣ��ƥ������ݲ����
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "��" << left << setw(2) << employeeinfo[i].birthday.month << "��" << left << setw(2) << employeeinfo[i].birthday.day << "��   ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;                                                                      //��¼�Ƿ�����������
        }
    }
    if (i >= N)                                                            //���û����Ӧ��Ϣ��������Ļ�ϴ�ӡ�����޴��ˡ�
        cout << "���޴���\n" << endl;
    if (j == 1) {
        cout << "�Ƿ�ɾ���� ����    1--ȷ��  2--ȡ��" << endl;
        int b;
        cin >> b;
        if (b == 1) {
            for (; i < N; i++) {                                           //ɾ����Ϣ
                employeeinfo[i].Id = employeeinfo[i + 1].Id;                
                strcpy((char*)employeeinfo[i].Name ,(char*) employeeinfo[i + 1].Name);
                strcpy((char*)employeeinfo[i].Sex ,(char*) employeeinfo[i + 1].Sex );
                strcpy((char*)employeeinfo[i].Title, (char*)employeeinfo[i + 1].Title);
                strcpy((char*)employeeinfo[i].Major, (char*)employeeinfo[i + 1].Major);
                strcpy((char*)employeeinfo[i].Telephone, (char*)employeeinfo[i + 1].Telephone);
                employeeinfo[i].birthday.year = employeeinfo[i + 1].birthday.year;
                employeeinfo[i].birthday.month = employeeinfo[i + 1].birthday.month;
                employeeinfo[i].birthday.day = employeeinfo[i + 1].birthday.day;
                strcpy((char*)employeeinfo[i].Address, (char*)employeeinfo[i + 1].Address);
            }
            cout << "ɾ���ɹ���" << endl;
        }
        else if (b == 2)
            return;
    }
    else if (j > 1) {                                                      //��������������Ļ�ϵ��û�Idȷ��Ҫɾ������Ϣ
        cout << "�������Ա����Id��" << endl;
        string c;
        cin >> c;
        for (int d = 0; d < N; d++) {
            if (employeeinfo[d].Id == c) {
                for (; d < N; d++) {
                    employeeinfo[i].Id = employeeinfo[i + 1].Id;
                    strcpy((char*)employeeinfo[i].Name, (char*)employeeinfo[i + 1].Name);
                    employeeinfo[i].Sex = employeeinfo[i + 1].Sex;
                    strcpy((char*)employeeinfo[i].Title, (char*)employeeinfo[i + 1].Title);
                    strcpy((char*)employeeinfo[i].Major, (char*)employeeinfo[i + 1].Major);
                    strcpy((char*)employeeinfo[i].Telephone, (char*)employeeinfo[i + 1].Telephone);
                    employeeinfo[i].birthday.year = employeeinfo[i + 1].birthday.year;
                    employeeinfo[i].birthday.month = employeeinfo[i + 1].birthday.month;
                    employeeinfo[i].birthday.day = employeeinfo[i + 1].birthday.day;
                    strcpy((char*)employeeinfo[i].Address, (char*)employeeinfo[i + 1].Address);
                }
            }
        }
        cout << "ɾ���ɹ���" << endl;
        return;
    }
        
        
}

//---------------------------------------------------------------------------------------
//ְԱ��Ϣ�޸ĺ���
void employeemodify() {
    int i = 0;
    cout << "---�޸����µ���ְԱ��Ϣ---" << endl;
    string p;
    cout << "����������" << endl;
    cin >> p;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Name == p) {                                    //�Ա��������Ϣ
            cout << "\t ���ҵ����˵���Ϣ" << endl;
            cout << "\t ȷ��Ҫ�޸Ĵ��˵���Ϣ" << endl;
            cout << "�������޸ĺ������" << endl;
            cin >> employeeinfo[i].Name;
            cout << "���޸��Ա�" << endl;
            cin >> employeeinfo[i].Sex;
            while (strcmp((char*)(employeeinfo[i].Sex), "��") != 0 && strcmp((char*)(employeeinfo[i].Sex), "Ů") != 0) {
                cout << "��������Ա��������ʵ�������룺" << endl;
                cin >> employeeinfo[i].Sex;
            }
            cout << "���޸�ְ��:(���ڡ������ڡ���ʦ)" << endl;
            cin >> employeeinfo[i].Title;
            while ((string)employeeinfo[i].Title != "����" && (string)employeeinfo[i].Title != "������" && (string)employeeinfo[i].Title != "��ʦ") {
                cout << "�������ְԱְ���������ʵ��������:" << endl;
                cin >> employeeinfo[i].Title;
            }
            cout << "���޸�רҵ:" << endl;
            cin >> employeeinfo[i].Major;
            cout << "���޸�����-��:" << endl;
            cin >> employeeinfo[i].birthday.year;
            cout << "���޸�����-��:" << endl;
            cin >> employeeinfo[i].birthday.month;
            cout << "���޸�����-��:" << endl;
            cin >> employeeinfo[i].birthday.day;
            cout << "���޸ĵ绰:" << endl;
            cin >> employeeinfo[i].Telephone;
            cout << "���޸ĵ�ַ:" << endl;
            cin >> employeeinfo[i].Address;
        }
    }
    cout << "�޸ĳɹ���" << endl;
    return;
}

//----------------------------------------------------------------------------------------
//ְԱ��Ϣ��ѯ����������������
void employeequery() {
    int i;
    int j = 0;
    string p;
    cout << "������Ҫ���ҵ�ְԱ������:" << endl;
    cin >> p;
    cout <<"Id  "<< " ����   " << "�Ա�" << "ְ��   " << " רҵ " << "     ��������    " << " �绰����   " << "      ��ַ     " << endl;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Name == p) {                                    //�����ṹ�����飬Ѱ�Ҷ�Ӧ��Ϣ
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(7) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "��"
                << left << setw(2) << employeeinfo[i].birthday.month << "��"
                << left << setw(2) << employeeinfo[i].birthday.day << "�� ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;                                                            //��j��¼��ѯ������Ϣ����
        }
    }
    if (j == 0)                                                             //jΪ0����û�ж�Ӧ��Ϣ
        cout << "���޴���\n" << endl;
}
//��ѯ����������ְ�ƣ�
void enquire() {
    int i;
    int j = 0;
    string p;
    cout << "������Ҫ���ҵ�Ա����ְ��:" << endl;
    cin >> p;
    cout <<"Id  "<< "����    " << "�Ա� " << "ְ��  " << " רҵ " << "    ��������    " << "�绰����    " << "     ��ַ      " << endl;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Title == p) {
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(7) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "��"
                << left << setw(2) << employeeinfo[i].birthday.month << "��"
                << left << setw(2) << employeeinfo[i].birthday.day << "�� ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;
        }
    }
    if (j == 0)
        cout << "û���������\n" << endl;
}
//ְԱ��Ϣͳ�ƺ���������ְ�ƣ�
void Titlesum() {
    int i = 0, a = 0, b = 0, c = 0;                                  //����������ֱ��¼��Ӧ��Ϣ������
    cout << "---���µ���ְԱ��Ϣͳ��---" << endl;
    for (i; i < N; i++) {                                            //ѭ���ṹ������Ϣ
        if (strcmp(employeeinfo[i].Title, "����") == 0)
            a++;
        else if (strcmp(employeeinfo[i].Title, "������") == 0)
            b++;
        else if (strcmp(employeeinfo[i].Title, "��ʦ") == 0)
            c++;
    }
    cout << "��������Ϊ" << a << endl;
    cout << "����������Ϊ" << b << endl;
    cout << "��ʦ����Ϊ" << c << endl;
}

/// ---------------------------------------------------------------------
//  ͨ���û�Id��ѯ�û���Ϣ

//1.���벢��ȡ����ѯ�û�Id

//2.����Id��ѯ��Ϣ

//3.�Բ�ѯ������Ϣ���и�ʽ������

//4.���������û���Ϣ��ӡ���

//5.���ܽ������������˵�
void FindById() {
    string p;
    int j;
    cout << "�������û�Id��";
    cin >> p;
    cout << "Id  " << "����    " << "�Ա� " << "ְ��  " << " רҵ " << "    ��������    " << "�绰����    " << "     ��ַ      " << endl;
    for (int i = 0; i < N; i++) {
        if (employeeinfo[i].Id == p) {
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "��" << left << setw(2) << employeeinfo[i].birthday.month << "��" << left << setw(2) << employeeinfo[i].birthday.day << "��   ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;
        }
    }
    if (j == 0)
        cout << "û���������\n" << endl;
}

int main() {
    for (; 1;) {                                                     //ѭ���ṹʹ���˵��ظ���ʾ
        for (int i = 0; i < N; i++)
            strcpy(employeeinfo[i].Name, "0");                       //��ʼ���ṹ��
        read();                                                      //���ļ�
        system("cls");                                               //��������
        cout << "\t********���ϴ�ѧ���¹���ϵͳ��ģ��汾2020��*******\n";
        cout << "\t01------ְԱ��Ϣ���           02------ְԱ��Ϣɾ��\n";
        cout << "\t03------ְԱ��Ϣ�޸�           04------ְԱ��Ϣ��ѯ\n";
        cout << "\t05------ְԱ��Ϣͳ��           06----���ݱ�����ָ�\n";
        cout << "\t07------�˳�����\n";
        cout << "\t---------------------------------------------------\n";
        cout << "��������ţ�";
        int order;
        cin >> order;
        switch (order) {
            case 01 :{
                infoaddition();                                       //���ְԱ��Ϣ
                while (1) {
                    int a;
                    cout << "�Ƿ�������ְԱ��Ϣ�� 1---����  2---�˳�" << endl;
                    cin >> a;
                    if (a == 1)
                        infoaddition();
                    else if (a == 2)
                        break;
                }
                write();
                system("pause");
                continue;
            }
            case 02: {
                infodelete();                                         //ɾ��ְԱ��Ϣ
                while (1) {
                    int a;
                    cout << "�Ƿ����ɾ��ְԱ��Ϣ�� 1---����  2---�˳�"<<endl;
                    cin >> a;
                    if (a == 1)
                        infodelete();
                    else if (a == 2)
                        break;
                }
                write();
                system("pause");
                continue;
            }
            case 03:{
                employeemodify();                                    //�޸�ְԱ��Ϣ
                while (1) {
                    int a;
                    cout << "�Ƿ�����޸ĳ�ְԱ��Ϣ�� 1---����  2---�˳�"<<endl;
                    cin >> a;
                    if (a == 1)
                        employeemodify();
                    else if (a == 2)
                        break;
                }
                write();
                system("pause");
                continue;
            }
            case 04: {
                int a;
                cout << "������Ҫ��ѯ�����ݣ�1--����   2--ְ��    3--Id"<<endl;
                cin >> a;
                if (a == 1)
                    employeequery();                                 //����������ѯ
                else if (a == 2)
                    enquire();                                       //����ְ�Ʋ�ѯ
                else if (a == 3)
                    FindById();                                      //����Id��ѯ
                while (1) {
                    int b;
                    cout << "�Ƿ������ѯְԱ��Ϣ�� 1--����  2--�˳�" << endl;
                    cin >> b;
                    if (b == 1) {
                        int c;
                        cout << "������Ҫ��ѯ�����ݣ�1--����   2--ְ��   3--Id" << endl;
                        cin >> c;
                        if (c == 1)
                            employeequery();
                        else if (c == 2)
                            enquire();
                        else if (c == 3)
                            FindById();
                    }
                    else if (b == 2)
                        break;
                }
                write();
                system("pause");
                continue;
            }
            case 05: {
                Titlesum();                                        //ͳ��ְԱ��Ϣ
                system("pause");
                continue;
            }
            case 06: {                                             //�¹��ܿ���
                cout << "--�˹�������ά����--��" << endl;
                system("pause");
                continue;
            }
            case 07: {
                write();                                           //д���ļ����˳�
                cout << "�˳��ɹ���" << endl;
                system("pause");
                return 0;
                break;
            }
            default: {
                cout << " ��Ч���� !" << endl;
                continue;
            }
        }
    }
    return 0;
}