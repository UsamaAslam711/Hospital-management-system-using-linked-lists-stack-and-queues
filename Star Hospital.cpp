//~~~~~~~~~~~~~~~~~~~~~~~~Header files (LIBRARIES)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include"string"
#include<cstring>
#include<string.h>
#include<windows.h>

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PATIENT CLASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class patient
{
public:
    long long ID;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender[20];
    string disease;
    double medamount;
    double surgeryamount;
    double registrationamount;
    double leftamount;
    double advance;
    double totalamount;
    patient* next;
};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LINKED LIST OF PATIENT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USING QUEUE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//



class linkedqueue
{
    patient* head, * last;
public:
    linkedqueue() //constructor
    {
        head = NULL;
        last = NULL;
    }
    patient input();
    void insertatend();
    void insertatbeg();
    void deletepatient();
    void getpatientout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DOCTOR CLASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class doctor
{
public:
    long long num;
    string firstname;
    string lastname;
    int exp;
    char gender[10];
    double pmdcnum;
    string specialist;
    string degrees;
    doctor* next;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LINKED LIST OF DOCTOR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USING QUEUE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

class linkedqueue2
{
    doctor* last;
public:
    doctor* head;
    linkedqueue2()
    {
        head = NULL;
        last = NULL;
    }
    doctor input();
    int readnumber2();
    void insertatend();
    void insertatstart();
    void getdoctorsout();
    void listofdoctors();
    int search2(int);
    char departmentname[50];
    void deletedoctor(int deta);
    //linkedqueue2* gethead();
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBERS OF PATIENT CLASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ================   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

int linkedqueue::search(int item)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        int flag = 0;
        patient* p = new patient();
        p = head;

        while (p->next != NULL && p->ID != item)
        {
            p = p->next;
        }
        if (p->ID == item)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
    //return;
}

int readnumber()
{
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

patient linkedqueue::input()
{
    int f1 = 0;
    int flag = 0;
    patient* p = new patient();
    cout << "\n  Please enter data for patient\n\n\n";
    cout << "\n   First name     : ";
    cin >> p->firstname;
    cout << "   Last name      : ";
    cin >> p->lastname;
again:
    cout << "   Blood Group    : ";
    cin >> p->blood;
    if ((strcmp(p->blood, "A+") == 0) || (strcmp(p->blood, "a+") == 0) || (strcmp(p->blood, "A-") == 0) || (strcmp(p->blood, "a-") == 0) ||
        (strcmp(p->blood, "B+") == 0) || (strcmp(p->blood, "b+") == 0) || (strcmp(p->blood, "B-") == 0) || (strcmp(p->blood, "b-") == 0) ||
        (strcmp(p->blood, "O+") == 0) || (strcmp(p->blood, "o+") == 0) || (strcmp(p->blood, "O-") == 0) || (strcmp(p->blood, "o-") == 0) ||
        (strcmp(p->blood, "AB+") == 0) || (strcmp(p->blood, "ab+") == 0) || (strcmp(p->blood, "AB-") == 0) || (strcmp(p->blood, "ab-") == 0))
        flag = 1;
    if (flag == 0)
    {
        Beep(523, 500);
        cin.get();
        cout << "\n   Invalid Blood Group Try Again..\n\n";

        goto again;

    }
x:
    cout << "   Gender(m/f/t)          : ";
    cin >> p->gender;
    if (strcmp(p->gender, "M") || strcmp(p->gender, "F") || strcmp(p->gender, "m") || strcmp(p->gender, "f") || strcmp(p->gender, "male") ||
        strcmp(p->gender, "female") || strcmp(p->gender, "Male") || strcmp(p->gender, "MALE") || strcmp(p->gender, "Female") ||
        strcmp(p->gender, "FEMALE") || strcmp(p->gender, "Transgender") || strcmp(p->gender, "T") || strcmp(p->gender, "TRANSGENDER") ||
        strcmp(p->gender, "transgender"))
    {
        f1 = 1;
    }
    if (f1 == 0)
    {
        cout << "\nYou have entered an invalid gender type...!!!\n";
        Beep(523, 500);
        cin.get();
        goto x;
    }
    cout << "   Age                  : ";
    cin >> p->age;
    cout << "   Mobile number        : ";
    cin >> p->ID;


    if (search(p->ID))
    {
        p->ID = 0;
        cout << "\n   Data not valid. Operation cancelled.";
    }
    cout << "   Disease              : ";
    cin >> p->disease;

    //~~~~~~~~~~~~~~~~~~~~~~~BILL INFORMATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    cout << "\n\n\n~~~~~~~~~~BILL INFROMATION~~~~~~~~~\n\n";
    cout << "   Registration Bill    : ";
    cin >> p->registrationamount;
    cout << "   Medicine Bill        : ";
    cin >> p->medamount;
    cout << "   Surgery Bill         : ";
    cin >> p->surgeryamount;
    p->totalamount = p->medamount + p->surgeryamount + p->registrationamount;
    cout << "   Advance              : ";
    cin >> p->advance;
    p->leftamount = p->totalamount - p->advance;
    return *p;
}

void output(patient* p)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Patient data:\n";
    cout << "\n   First Name         : " << p->firstname;
    cout << "\n   Last Name          : " << p->lastname;
    cout << "\n   Gender             : " << p->gender;
    cout << "\n   Age                : " << p->age;
    cout << "\n   Blood Group        : " << p->blood;
    cout << "\n   Mobile Number      : " << p->ID;

    cout << "\n\n\n~~~~~~~~~~~~~BILL INFORMATION~~~~~~~~~~~~~~~~~\n\n\n";

    cout << "\n   Medicine Bill     : " << p->medamount;
    cout << "\n   Registration Bill : " << p->registrationamount;
    cout << "\n   Surgery Amount    : " << p->surgeryamount;
    cout << "\n   Total amount      : " << p->totalamount;
    cout << "\n   Advance           :" << p->advance;
    cout << "\n   Yet to be paid    :" << p->leftamount;

    cout << "\n   ";
    cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}

void linkedqueue::insertatbeg()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)

    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

void linkedqueue::insertatend()
{
    patient* p = new patient();
    *p = input();
    if (p->ID == 0)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
        p->next = NULL;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n  ----------PATIENT ADDED-----------";
    output(p);
}

void linkedqueue2::deletedoctor(int deta)
{
    bool flag = 0;
    doctor* temp = head;
    double check = temp->pmdcnum;
    //doctor* temp2;
    if (check == deta)
    {
        flag = 1;
        if (temp != NULL)
        {
            cout << "\n Doctor found having PMDC Number = " << temp->pmdcnum << endl;
            if (temp == head)
            {
                head = head->next;
                delete temp;
                return;
            }
            else
            {
                delete temp;
                return;
            }

        }
    }
    else
    {
        temp = temp->next;
    }
    if (flag == 1)
    {
        cout << "Doctor deleted successfully " << endl;
    }
    else
    {
        cout << "You have entered wrong information " << endl;
    }
}

void linkedqueue::getpatientout()
{
    system("cls");
    if (head == NULL)
    {
        cout << "\n  No Patient to operate";
    }
    else
    {
        patient* p = new patient();
        p = head;
        head = head->next;
        cout << "\n  Patient to operate:";
        output(p);
    }
}

void linkedqueue::listofpatients()
{
    if (head == NULL)
    {
        cout << "\n  No patient";
    }
    system("cls");
    cout << "\n\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    patient* p = new patient;
    p = head;
    while (p != NULL)
    {
        cout << "\n   Patient data:\n";
        cout << "\n   First Name        : " << p->firstname;
        cout << "\n   Last Name         : " << p->lastname;
        cout << "\n   Gender            : " << p->gender;
        cout << "\n   Age               : " << p->age;
        cout << "\n   Blood Group       : " << p->blood;
        cout << "\n   Mobile Number     : " << p->ID;

        cout << "\n\n\n\t~~~~~~~~~~~~~BILL INFORMATION~~~~~~~~~~~~~~~~~\n\n\n";

        cout << "\n   Medicine Bill     : " << p->medamount;
        cout << "\n   Registration Bill : " << p->registrationamount;
        cout << "\n   Surgery Amount    : " << p->surgeryamount;
        cout << "\n   Total amount      : " << p->totalamount;
        cout << "\n   Advance           :" << p->advance;
        cout << "\n   Yet to be paid    :" << p->leftamount;
        cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p = p->next;
    }
    cout << "\n";
}

void departmentmenu(linkedqueue* q)
{
    int choice = 0, success = 0;
    patient p;
    while (choice != 5)
    {
        system("cls");
        cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n   " << q->departmentname;
        cout << "\n   [1] Add normal patient\n";
        cout << "   [2] Add critically ill patient\n";
        cout << "   [3] Take patient to Doctor\n";
        cout << "   [4] Display list\n";
        cout << "   [5] Change department or exit\n\n\n";
        cout << "\n   Please enter your choice : ";
        choice = readnumber();
        cout << "  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

        switch (choice)
        {
        case 1: q->insertatend();
            cout << "\n   Press any key";
            _getch();
            break;

        case 2: q->insertatbeg();
            cout << "\n   Press any key";
            _getch();
            break;

        case 3: q->getpatientout();
            cout << "\n   Press any key";
            _getch();
            break;

        case 4: system("cls");
            q->listofpatients();
            cout << "\n   Press any key";
            _getch();
            break;
        }
    }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MEMBERS OF PATIENT CLASS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ================   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void departmentmenu2(linkedqueue2* q2)
{
    int choice = 0, success;
    doctor d;
    while (choice != 3)
    {
        system("cls");
        cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n   " << q2->departmentname;
        cout << "\n   [1] Add Doctor\n";
        cout << "   [2] Display Doctor's list.\n";
        cout << "   [3] Change department. \n";
        cout << "   [4] Fire a doctor. \n";
        cout << "   [5] Exit \n\n";
        cout << "\n   Please enter your choice : ";
        choice = readnumber();
        cout << "  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

        switch (choice)
        {
        case 1:
            q2->insertatend();
            cout << "\n   Press any key";
            _getch();
            break;

        case 2:
            q2->listofdoctors();
            cout << "\n   Press any key";
            _getch();
            break;

        case 4:
        {
            int deta;
            cout << "\nEnter PMDC number of the doctor : ";
            cin >> deta;
            q2->deletedoctor(deta);

            break;
        }


        case 5: system("cls");
            exit(0);
        }
    }
}

int linkedqueue2::search2(int item2)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        int flag = 0;
        doctor* d = new doctor();
        d = head;

        while (d->next != NULL && d->num != item2)
        {
            d = d->next;
        }
        if (d->num == item2)
        {
            flag = 1;
            return true;
        }
        if (flag == 0)
            return false;
    }
}

int readnumber2()
{
    char a[20];
    cin.getline(a, sizeof(a));
    return atoi(a);
}

doctor linkedqueue2::input()
{
    int f = 0;
    doctor* d = new doctor();
    cout << "\nEnter the informtion for new Doctor\n\n\n";
    cout << "\n   Doctor's First name            : ";
    cin >> d->firstname;
    cout << "\n   Doctor's Last name             : ";
    cin >> d->lastname;
    cout << "\n   Experience of the Doctor       : ";
    cin >> d->exp;
q:
    cout << "\n   Sex                            : ";
    cin >> d->gender;
    if (strcmp(d->gender, "M") || strcmp(d->gender, "F") || strcmp(d->gender, "m") || strcmp(d->gender, "f") || strcmp(d->gender, "male") ||
        strcmp(d->gender, "female") || strcmp(d->gender, "Male") || strcmp(d->gender, "MALE") || strcmp(d->gender, "Female") ||
        strcmp(d->gender, "FEMALE") || strcmp(d->gender, "Transgender") || strcmp(d->gender, "T") || strcmp(d->gender, "TRANSGENDER") ||
        strcmp(d->gender, "transgender"))
    {
        f = 1;
    }
    if (f == 0)
    {
        cout << "\nYou have entered an invalid gender type...!!!\n";
        Beep(523, 500);
        cin.get();
        goto q;
    }

    cout << "\n   Mobile Number                  : ";
    cin >> d->num;
    cout << "\n   Enter the registered PMDC num  : ";
    cin >> d->pmdcnum;
    cout << "\n   Specialization                 : ";
    cin >> d->specialist;
    cout << "\n   All degrees                    : ";
    cin >> d->degrees;

    return *d;
}

void output2(doctor* d)
{
    cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n   Doctor's data:\n";
    cout << "\n   First Name         : " << d->firstname;
    cout << "\n   Last Name          : " << d->lastname;
    cout << "\n   Gender             : " << d->gender;
    cout << "\n   Experience         : " << d->exp;
    cout << "\n   PMDC no.           : " << d->pmdcnum;
    cout << "\n   Mobile Number      : " << d->num;
    cout << "\n   Specialization     : " << d->specialist;
    cout << "\n   Degrees            : " << d->degrees;
    cout << "\n";
    cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}

void linkedqueue2::listofdoctors()
{
    if (head == NULL)
    {
        cout << "\n  No doctors available...!!!\n";
    }
    system("cls");
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    doctor* d = new doctor;
    d = head;
    while (d != NULL)
    {
        cout << "\n   Doctor's data:\n\n";
        cout << "\n   First Name       : " << d->firstname;
        cout << "\n   Last Name        : " << d->lastname;
        cout << "\n   Gender           : " << d->gender;
        cout << "\n   Experience       : " << d->exp;
        cout << "\n   Mobile no.       : " << d->num;
        cout << "\n   PMDC no.         : " << d->pmdcnum;
        cout << "\n   Specialization   : " << d->specialist;
        cout << "\n   Degrees          : " << d->degrees;

        cout << "\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        d = d->next;
    }
    cout << "\n";
}

void linkedqueue2::insertatstart()
{
    doctor* d = new doctor();
    *d = input();
    if (d->num == 0)
        return;

    if (head == NULL)
    {
        head = d;
        last = d;
        d->next = NULL;
    }
    else
    {
        d->next = head;
        head = d;
    }
    system("cls");
    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "    Doctor added:";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~\n";
    output2(d);
}

void linkedqueue2::insertatend()
{
    doctor* d = new doctor();
    *d = input();
    if (d->num == 0)
        return;

    if (head == NULL)
    {
        head = d;
        last = d;
        d->next = NULL;
    }
    else
    {
        d->next = NULL;
        last->next = d;
        last = d;
    }
    system("cls");
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n  ----------DOCTOR ADDED-----------";
    output2(d);
}
//  ||||||||||||||||||||||||||||||||||||||||||||||||       MAIN        ||||||||||||||||||||||||||||||||||||||||||||||||

int main()
{
    int i;
    int choice = 0;
    linkedqueue departments[4];
    linkedqueue2 docdata[4];
    system("cls");
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
    cout << "\n\n\n\n";
    int chk = 0;
    int chk2 = 0;
n:
ch:
    cout << "\n\n\n";
    cout << "Amdinistration username       :   ";
    char admin[100];
    char pass[10];
    cin >> admin;
    cout << "Password                      :   ";
    cin >> pass;



    if (strcmp(admin, "HMS@starhospital.com") != 0 && strcmp(admin, "HMS@latifhospital.com") != 0 && strcmp(admin, "HMS@alihospital.com") != 0)
    {
        Beep(530, 700);
        cin.get();
        cout << "\n\n\n";
        cout << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout << "Wrong Username\n";
        cout << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout << "\n\n\n";
        chk++;
        if (chk == 3)
        {
            Beep(530, 700);
            cin.get();
            cout << "\n\n\nYou have Entered the wrong username \"3\" times...!!!\n\n\n";
            _getch();
            exit(0);
        }
        goto n;
    }
    if (pass=="uetadmin")
    {
        Beep(530, 700);
        cin.get();
        cout << "\n\n\n";
        cout << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout << "Wrong Password\n";
        cout << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        cout << "\n\n\n";
        chk2++;
        if (chk2 == 3)
        {
            Beep(530, 700);
            cin.get();
            cout << "\n\n\nYou have Entered the wrong password \"3\" times...!!!\n\n\n";
            _getch();
            exit(0);
        }
        goto n;
    }

    system("cls");
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
    cout << "\n\n\n\n";

    cout << "1. Patient Menu.\n\n";
    cout << "2. Doctor Menu.\n\n";
    cout << "\n\n\n\n";
    cout << "Enter your choice : ";
    int choice2;
    cin >> choice2;
    if (choice2 == 1)
    {
        while (choice != 5)
        {
            strcpy_s(departments[0].departmentname, "GENERAL DEPARTMENT\n");
            strcpy_s(departments[1].departmentname, "HEART DEPARTMENT\n");
            strcpy_s(departments[2].departmentname, "LUNG DEPARTMENT\n");
            strcpy_s(departments[3].departmentname, "CANCER DEPARTMENT\n");
            system("cls");
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
            cout << "\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
            cout << "   Main Menu\n\n";
            for (i = 0; i < 4; i++)
            {
                cout << "   " << (i + 1) << ": " << departments[i].departmentname;
            }
            cout << "   5:Exit \n";
            cout << "   6:Change Hospital \n";
            cout << "\n\n   Please enter your choice : ";
            choice = readnumber();
            if (choice == 6)
            {
                system("cls");
                goto ch;
            }
            if (choice >= 1 && choice <= 4)
            {
                departmentmenu(&departments[choice - 1]);
            }

        }
        if (choice == 5)
        {
            cout << "\n\t\tThank you! \n";
            exit(0);
        }
    }

    else if (choice2 == 2)
    {
        while (choice != 5)
        {
            strcpy_s(docdata[0].departmentname, "GENERAL DEPARTMENT\n");
            strcpy_s(docdata[1].departmentname, "HEART DEPARTMENT\n");
            strcpy_s(docdata[2].departmentname, "LUNG DEPARTMENT\n");
            strcpy_s(docdata[3].departmentname, "CANCER DEPARTMENT\n");
            system("cls");
            cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
            cout << "\n\t\t  |-- HOSPITAL MANAGEMENT SYSTEM --|";
            cout << "\n\t\t  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
            cout << "\n\n \t\t  Main Menu\n\n";
            for (i = 0; i < 4; i++)
            {
                cout << "   " << (i + 1) << ": " << docdata[i].departmentname;
            }
            cout << "   5: Change Hospital";
            cout << "   6: Exit";
            cout << "\n\n   Please enter your choice : ";
            choice = readnumber();
            if (choice >= 1 && choice <= 4)
            {
                departmentmenu2(&docdata[choice - 1]);
            }

        }
        if (choice == 6)
        {
            cout << "\n\t\tThank you! \n";
            exit(0);
        }
        if (choice == 5)
        {
            system("cls");
            goto ch;
        }
    }
}