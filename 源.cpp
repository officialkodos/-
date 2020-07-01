#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)                                 //在VS编译器中忽略使用strcpy语句产生的错误
using namespace std;
const int N = 100;
struct Date {                                                 //定义结构体变量
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
//txt文件写入函数
void write() {
    ofstream outfile("employeerecords.txt", ios::out);           //创建文件
    if (!outfile) {                                              //如果文件创建失败，就中止后续操作
        cout << "文件创建失败";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (strcmp(employeeinfo[i].Name, "0") == 0)              //条件判定
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
    outfile.close();                                             //关闭文件
}
//-----------------------------------------------------------------------------
//文件读取函数
void read() {
    ifstream infile("employeerecords.txt", ios::in);              //定义文件输入流对象，以“读”方式打开文件
    if (!infile)
        cout << "文件打开失败！";
    int i = 0;
    while (!infile.eof() && i < N) {                            //在文件到达结束位置时中止循环
        infile >> employeeinfo[i].Id;
        infile >> employeeinfo[i].Name;                          //将文件中的内容赋值给结构体变量
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
    infile.close();                                               //关闭文件
}

//------------------------------------------------------------------------------------
//职员信息添加函数

//  添加员工信息时自动生成员工Id

//  员工Id唯一且不可修改
void infoaddition() {
    int p[1000];                                                  //生成Id库
    for (int i = 1; i < 1000; i++) {
        p[i] = i;
    }
    for (int x = 0; x < N; x++) {
        if (strcmp(employeeinfo[x].Name, "0") == 0) {             //跳过已有数据，从其后的第一个空数组元素开始赋值
            cout << "要添加的职员信息:" << endl;
            cout << "姓名" << endl;
            cin >> employeeinfo[x].Name;
            cout << "性别" << endl;
            cin >> employeeinfo[x].Sex;
            cout << "职称" << endl;
            cin >> employeeinfo[x].Title;
            cout << "专业" << endl;
            cin >> employeeinfo[x].Major;
            cout << "出生日期-年" << endl;
            cin >> employeeinfo[x].birthday.year;
            cout << "出生日期-月" << endl;
            cin >> employeeinfo[x].birthday.month;
            cout << "出生日期-日" << endl;
            cin >> employeeinfo[x].birthday.day;
            cout << "电话" << endl;
            cin >> employeeinfo[x].Telephone;
            cout << "家庭地址" << endl;
            cin >> employeeinfo[x].Address;
            for (int a = 0; a < 100; a++) {
                if (!p[a] == 0) {
                    employeeinfo[x].Id = p[a];                 
                    p[a] = 0;
                }
                else
                    break;
            }
            cout << "添加成功！" << endl;
            return;
        }
    }
}

//--------------------------------------------------------------------------------
//职员信息删除函数
void infodelete() {
    string a;
    cout << "输入姓名或员工Id: " << endl;
    cin >> a;
    cout <<"Id  "<< "姓名     " << "性别 " << "职称  " << " 专业 " << "     出生日期  " << "  电话号码    " << " 地址          " << endl;
    int i,j=0;
    for (i = 0; i < N; i++) {                                             
        if (employeeinfo[i].Name==a||employeeinfo[i].Id==a) {                        //遍历数组，寻找与输入信息相匹配的数据并输出
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "年" << left << setw(2) << employeeinfo[i].birthday.month << "月" << left << setw(2) << employeeinfo[i].birthday.day << "日   ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;                                                                      //记录是否有重名出现
        }
    }
    if (i >= N)                                                            //如果没有相应信息，则在屏幕上打印“查无此人”
        cout << "查无此人\n" << endl;
    if (j == 1) {
        cout << "是否删除？ 输入    1--确认  2--取消" << endl;
        int b;
        cin >> b;
        if (b == 1) {
            for (; i < N; i++) {                                           //删除信息
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
            cout << "删除成功！" << endl;
        }
        else if (b == 2)
            return;
    }
    else if (j > 1) {                                                      //有重名，根据屏幕上的用户Id确定要删除的信息
        cout << "请输入该员工的Id：" << endl;
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
        cout << "删除成功！" << endl;
        return;
    }
        
        
}

//---------------------------------------------------------------------------------------
//职员信息修改函数
void employeemodify() {
    int i = 0;
    cout << "---修改人事档案职员信息---" << endl;
    string p;
    cout << "请输入姓名" << endl;
    cin >> p;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Name == p) {                                    //对比输入的信息
            cout << "\t 已找到此人的信息" << endl;
            cout << "\t 确认要修改此人的信息" << endl;
            cout << "请输入修改后的姓名" << endl;
            cin >> employeeinfo[i].Name;
            cout << "请修改性别" << endl;
            cin >> employeeinfo[i].Sex;
            while (strcmp((char*)(employeeinfo[i].Sex), "男") != 0 && strcmp((char*)(employeeinfo[i].Sex), "女") != 0) {
                cout << "您输入的性别有误，请核实后再输入：" << endl;
                cin >> employeeinfo[i].Sex;
            }
            cout << "请修改职称:(教授、副教授、讲师)" << endl;
            cin >> employeeinfo[i].Title;
            while ((string)employeeinfo[i].Title != "教授" && (string)employeeinfo[i].Title != "副教授" && (string)employeeinfo[i].Title != "讲师") {
                cout << "您输入的职员职称有误，请核实后再输入:" << endl;
                cin >> employeeinfo[i].Title;
            }
            cout << "请修改专业:" << endl;
            cin >> employeeinfo[i].Major;
            cout << "请修改生日-年:" << endl;
            cin >> employeeinfo[i].birthday.year;
            cout << "请修改生日-月:" << endl;
            cin >> employeeinfo[i].birthday.month;
            cout << "请修改生日-日:" << endl;
            cin >> employeeinfo[i].birthday.day;
            cout << "请修改电话:" << endl;
            cin >> employeeinfo[i].Telephone;
            cout << "请修改地址:" << endl;
            cin >> employeeinfo[i].Address;
        }
    }
    cout << "修改成功！" << endl;
    return;
}

//----------------------------------------------------------------------------------------
//职员信息查询函数（根据姓名）
void employeequery() {
    int i;
    int j = 0;
    string p;
    cout << "请输入要查找的职员的姓名:" << endl;
    cin >> p;
    cout <<"Id  "<< " 姓名   " << "性别" << "职称   " << " 专业 " << "     出生日期    " << " 电话号码   " << "      地址     " << endl;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Name == p) {                                    //遍历结构体数组，寻找对应信息
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(7) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "年"
                << left << setw(2) << employeeinfo[i].birthday.month << "月"
                << left << setw(2) << employeeinfo[i].birthday.day << "日 ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;                                                            //用j记录查询到的信息数量
        }
    }
    if (j == 0)                                                             //j为0，则没有对应信息
        cout << "查无此人\n" << endl;
}
//查询函数（根据职称）
void enquire() {
    int i;
    int j = 0;
    string p;
    cout << "请输入要查找的员工的职称:" << endl;
    cin >> p;
    cout <<"Id  "<< "姓名    " << "性别 " << "职称  " << " 专业 " << "    出生日期    " << "电话号码    " << "     地址      " << endl;
    for (i = 0; i < N; i++) {
        if (employeeinfo[i].Title == p) {
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(7) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "年"
                << left << setw(2) << employeeinfo[i].birthday.month << "月"
                << left << setw(2) << employeeinfo[i].birthday.day << "日 ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;
        }
    }
    if (j == 0)
        cout << "没有相关数据\n" << endl;
}
//职员信息统计函数（根据职称）
void Titlesum() {
    int i = 0, a = 0, b = 0, c = 0;                                  //定义变量，分别记录对应信息的数量
    cout << "---人事档案职员信息统计---" << endl;
    for (i; i < N; i++) {                                            //循环结构查找信息
        if (strcmp(employeeinfo[i].Title, "教授") == 0)
            a++;
        else if (strcmp(employeeinfo[i].Title, "副教授") == 0)
            b++;
        else if (strcmp(employeeinfo[i].Title, "讲师") == 0)
            c++;
    }
    cout << "教授人数为" << a << endl;
    cout << "副教授人数为" << b << endl;
    cout << "讲师人数为" << c << endl;
}

/// ---------------------------------------------------------------------
//  通过用户Id查询用户信息

//1.输入并获取待查询用户Id

//2.根据Id查询信息

//3.对查询到的信息进行格式化处理

//4.将处理后的用户信息打印输出

//5.功能结束，返回主菜单
void FindById() {
    string p;
    int j;
    cout << "请输入用户Id：";
    cin >> p;
    cout << "Id  " << "姓名    " << "性别 " << "职称  " << " 专业 " << "    出生日期    " << "电话号码    " << "     地址      " << endl;
    for (int i = 0; i < N; i++) {
        if (employeeinfo[i].Id == p) {
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Id;
            cout << left << setw(8) << setfill(' ') << employeeinfo[i].Name;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].Sex;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Title;
            cout << left << setw(6) << setfill(' ') << employeeinfo[i].Major;
            cout << left << setw(4) << setfill(' ') << employeeinfo[i].birthday.year << "年" << left << setw(2) << employeeinfo[i].birthday.month << "月" << left << setw(2) << employeeinfo[i].birthday.day << "日   ";
            cout << left << setw(12) << setfill(' ') << employeeinfo[i].Telephone;
            cout << left << setw(15) << setfill(' ') << employeeinfo[i].Address;
            j++;
        }
    }
    if (j == 0)
        cout << "没有相关数据\n" << endl;
}

int main() {
    for (; 1;) {                                                     //循环结构使主菜单重复显示
        for (int i = 0; i < N; i++)
            strcpy(employeeinfo[i].Name, "0");                       //初始化结构体
        read();                                                      //读文件
        system("cls");                                               //清屏命令
        cout << "\t********中南大学人事管理系统（模拟版本2020）*******\n";
        cout << "\t01------职员信息添加           02------职员信息删除\n";
        cout << "\t03------职员信息修改           04------职员信息查询\n";
        cout << "\t05------职员信息统计           06----数据备份与恢复\n";
        cout << "\t07------退出程序\n";
        cout << "\t---------------------------------------------------\n";
        cout << "请输入序号：";
        int order;
        cin >> order;
        switch (order) {
            case 01 :{
                infoaddition();                                       //添加职员信息
                while (1) {
                    int a;
                    cout << "是否继续添加职员信息？ 1---继续  2---退出" << endl;
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
                infodelete();                                         //删除职员信息
                while (1) {
                    int a;
                    cout << "是否继续删除职员信息？ 1---继续  2---退出"<<endl;
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
                employeemodify();                                    //修改职员信息
                while (1) {
                    int a;
                    cout << "是否继续修改除职员信息？ 1---继续  2---退出"<<endl;
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
                cout << "请输入要查询的依据：1--姓名   2--职称    3--Id"<<endl;
                cin >> a;
                if (a == 1)
                    employeequery();                                 //根据姓名查询
                else if (a == 2)
                    enquire();                                       //根据职称查询
                else if (a == 3)
                    FindById();                                      //根据Id查询
                while (1) {
                    int b;
                    cout << "是否继续查询职员信息？ 1--继续  2--退出" << endl;
                    cin >> b;
                    if (b == 1) {
                        int c;
                        cout << "请输入要查询的依据：1--姓名   2--职称   3--Id" << endl;
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
                Titlesum();                                        //统计职员信息
                system("pause");
                continue;
            }
            case 06: {                                             //新功能开发
                cout << "--此功能正在维护中--！" << endl;
                system("pause");
                continue;
            }
            case 07: {
                write();                                           //写入文件后退出
                cout << "退出成功！" << endl;
                system("pause");
                return 0;
                break;
            }
            default: {
                cout << " 无效输入 !" << endl;
                continue;
            }
        }
    }
    return 0;
}