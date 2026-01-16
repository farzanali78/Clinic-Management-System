#include <iostream>
#include <string>
using namespace std;


int token = 100;
#include <string>
using namespace std;


string cardiologyDrs[3] = {
    "1.Dr. Ahmed Khan",
    "2.Dr. Hassan Raza",
    "3.Dr. Salman Iqbal"};


string neurologyDrs[3] = {
    "1.Dr. Sara Malik",
    "2.Dr. Adeel Farooq",
    "3.Dr. Nimra Sheikh"};


string orthopedicsDrs[3] = {
    "1.Dr. Usman Ali",
    "2.Dr. Bilal Akram",
    "3.Dr. Faizan Noor"};


string pediatricsDrs[3] = {
    "1.Dr. Ayesha Noor",
    "2.Dr. Hina Javed",
    "3.Dr. Ali Hamza"};


string generalMedicineDrs[3] = {
    "1.Dr. Bilal Hassan",
    "2.Dr. Kamran Shah",
    "3.Dr. Taha Siddiqui"};


string emergencyDrs[3] = {
    "1.Dr. Fahad Qureshi",
    "2.Dr. Imran Aslam",
    "3.Dr. Saad Rehman"};

string departments[6] = {
    "1.Cardiology",
    "2.Neurology",
    "3.Orthopedics",
    "4.Pediatrics",
    "5.General Medicine",
    };

class Node
{
public:
    string name, doctorName, disease, gender;
    int age;
    int tokenNumber;
    bool emergencyLevel;
    Node *next;

    Node(string name, string doctorName, int tokenNumber, string gender, int age, string disease, bool isEmergency)
    {
        this->name = name;
        this->emergencyLevel = isEmergency;
        this->age = age;
        this->disease = disease;
        this->gender = gender;
        this->doctorName = doctorName;
        this->tokenNumber = tokenNumber;
        next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    void addPatient(string name, string doctorName, int tokenNumber, string gender, int age, string disease)
    {
        Node *new_node = new Node(name, doctorName, tokenNumber, gender, age, disease, false);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            token++;
            cout << "Token no: " << tokenNumber << endl;
            cout << "Patient Added Successfully!" << endl;
            cout<<endl;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        tail = new_node;
        token++;
        cout << "Token no: " << tokenNumber << endl;
        cout << "Patient Added Successfully!" << endl;
        cout<<endl;
    }

    void show_patients()
    {
        Node *curr = head;
        if(head==nullptr){
            cout<<"No patient available"<<endl;
            cout<<endl;
            return;
        }
        while (curr != nullptr)
        {
             cout<<endl;
             cout<<"==================================================================="<<endl;
            cout << "Name: " << curr->name << endl;
            cout << "Age: " << curr->age << endl;
            cout << "Disease: " << curr->disease << endl;
            cout << "Gender: " << curr->gender << endl;
            cout << "Doctor Name: " << curr->doctorName << endl;
            cout << "Token Number: " << curr->tokenNumber << endl;
            cout<<"Emergency Patient: "<<(curr->emergencyLevel?"Yes":"No")<<endl;
            cout<<"==================================================================="<<endl;
            cout<<endl;
            curr = curr->next;
        }
    }

    void dequeue()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->emergencyLevel == true)
            {
                cout<<endl;
                cout<<"==================================================================="<<endl;
                cout << "Emergency Patient" << endl;
                cout << "Name: " << curr->name << endl;
                cout << "Age: " << curr->age << endl;
                cout << "Disease: " << curr->disease << endl;
                cout << "Gender: " << curr->gender << endl;
                cout << "Doctor Name: " << curr->doctorName << endl;
                cout << "Token Number: " << curr->tokenNumber << endl;
                cout << "Patient Served!" << endl;
                cout<<"==================================================================="<<endl;
                cout<<endl;
                head=head->next;
                delete curr;
                break;
                curr->emergencyLevel = false;
            }
            else
            {
                cout<<endl;
                cout<<"==================================================================="<<endl;
                cout << "Normal Patient" << endl;
                cout << "Name: " << curr->name << endl;
                cout << "Age: " << curr->age << endl;
                cout << "Disease: " << curr->disease << endl;
                cout << "Gender: " << curr->gender << endl;
                cout << "Doctor Name: " << curr->doctorName << endl;
                cout << "Token Number: " << curr->tokenNumber << endl;
                cout << "Patient Served!" << endl;
                cout<<"==================================================================="<<endl;
                cout<<endl;
                head=head->next;
                delete curr;
                break;
                cout << endl;
            }
            curr = curr->next;
        }
    }

    void showNextPatient()
    {
        Node *curr = head->next;
        if (curr == nullptr)
        {
            cout << "No patient in queue" << endl;
            return;
        }
        cout << "Next patient info" << endl;
        cout << "Patient name: " << curr->name << endl;
        cout << "Doctor's name: " << curr->doctorName << endl;
        cout << "Token Number: " << curr->tokenNumber << endl;
        cout << endl;
    }

    void search_by_name()
    {
        Node *curr = head;
        string patientName;
        bool found = false;
        cin.ignore();
        cout << "Enter patient name: ";
        getline(cin, patientName);
        while (curr != nullptr)
        {
            if (curr->name == patientName)
            {
                found = true;
                cout << endl;
                cout << "====================================================================" << endl;
                cout << "Patient name: " << curr->name << endl;
                cout << "Doctor's name: " << curr->doctorName << endl;
                cout << "Token Number: " << curr->tokenNumber << endl;
                cout << "====================================================================" << endl;
                cout << endl;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Patient not found!" << endl;
        }
    }

    void search_by_token()
    {
        Node *curr = head;
        int tokenNum;
        bool found = false;
        cin.ignore();
        cout << "Enter Token number: ";
        cin >> tokenNum;
        while (curr != nullptr)
        {
            if (curr->tokenNumber == tokenNum)
            {
                found = true;
                cout << endl;
                cout << "====================================================================" << endl;
                cout << "Patient name: " << curr->name << endl;
                cout << "Doctor's name: " << curr->doctorName << endl;
                cout << "Token Number: " << curr->tokenNumber << endl;
                cout << "====================================================================" << endl;
                cout << endl;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Patient not found!" << endl;
        }
    }

    void search_by_doctors_name()
    {
        Node *curr = head;
        string doctorName;
        bool found = false;
        cin.ignore();
        cout << "Enter Doctor's name: ";
        getline(cin, doctorName);
        while (curr != nullptr)
        {
            if (curr->doctorName == doctorName)
            {
                found = true;
                cout << endl;
                cout << "====================================================================" << endl;
                cout << "Patient name: " << curr->name << endl;
                cout << "Token Number: " << curr->tokenNumber << endl;
                cout << "====================================================================" << endl;
                cout << endl;
            }
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Patient not found!" << endl;
        }
    }

    void delete_patient_by_name()
    {
        Node *curr = head;
        int token_num;
        bool found = false;
        cin.ignore();
        cout << "Enter token number: ";
        cin>>token_num;

        if (head->tokenNumber==token_num)
        {
            head = head->next;
            cout << "Patient discharged successfully!" << endl;
            cout<<endl;
            return;
            
        }
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            if (curr->tokenNumber == token_num)
            {
                found = true;
                prev->next = curr->next;
                delete curr;
                cout << "Patient discharged successfully!" << endl;
                cout << endl;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!found)
        {
            cout << "Patient not found!" << endl;
        }
    }

    void updatePatient()
    {
        Node *curr = head;
        int token_num;
        int updated_age;
        int drChoice;
        int drchoice3;
        bool found = false;
        string updated_name;
        string updated_Drname;
        string updated_gender;
        string updated_disease;

        cout << "Enter Patient Token no: ";
        cin >> token_num;

        if (head == nullptr)
        {
            cout << "Add Patient first" << endl;
            return;
        }

        while (curr != nullptr)
        {
            if (curr->tokenNumber == token_num)
            {
                found = true;
                cout << "=================================================" << endl;
                cout << "Update Form" << endl;
                cout << "=================================================" << endl;
                cin.ignore();
                cout << "Patient's name: ";
                getline(cin, updated_name);
                cout << "Choose from below available doctors" << endl;
                cout << "View Doctors by Category" << endl;
                for (int i = 0; i < 6; i++)
                {
                    cout << departments[i] << endl;
                }
                cout << "Enter Choice: ";
                cin >> drchoice3;
                switch (drchoice3)
                {
                case 1:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << cardiologyDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Ahmed Khan";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Hassan Raza";
                    }
                    else
                    {
                        updated_Drname = "Dr. Salman Iqbal";
                    }
                    break;
                case 2:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << neurologyDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Sara Malik";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Adeel Sheikh";
                    }
                    else
                    {
                        updated_Drname = "Dr. Nimra Iqbal";
                    }
                    break;
                case 3:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << orthopedicsDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Usman Ali";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Bilal Akram";
                    }
                    else
                    {
                        updated_Drname = "Dr. Faizan Noor";
                    }

                    break;
                case 4:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << pediatricsDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Ayesha Noor";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Hina Javed";
                    }
                    else
                    {
                        updated_Drname = "Dr. Ali Hamza";
                    }
                    break;
                case 5:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << generalMedicineDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Bilal Hassan";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Kamran Shah";
                    }
                    else
                    {
                        updated_Drname = "Dr. Taha Siddiqui";
                    }
                    break;
                case 6:
                    for (int i = 0; i < 3; i++)
                    {
                        cout << emergencyDrs[i] << endl;
                    }
                    cin >> drChoice;
                    if (drChoice == 1)
                    {
                        updated_Drname = "Dr. Fahad Qureshi";
                    }
                    else if (drChoice == 2)
                    {
                        updated_Drname = "Dr. Imran Aslam";
                    }
                    else
                    {
                        updated_Drname = "Dr. Saad Rehman";
                    }
                    break;

                default:
                    cout << "Enter correct choice." << endl;
                    break;
                }

                cout << "Age: ";
                cin >> updated_age;
                cin.ignore();
                cout << "Gender: ";
                getline(cin, updated_gender);
                cout << "Disease: ";
                getline(cin, updated_disease);
                curr->name = updated_name;
                curr->doctorName = updated_Drname;
                curr->disease = updated_disease;
                curr->gender = updated_gender;
                curr->age = updated_age;
                cout << "Updated Successfully" << endl;
            }

            curr = curr->next;
        }
        if (!found)
        {
            cout << "Patient Not Found!" << endl;
        }
    }

    void sortPatientName()
    {
        Node *curr = head;
    }
    void showAllDr()
    {
        cout << "Cardiology" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << cardiologyDrs[i] << endl;
        }
        cout << endl;
        cout << "Neurology" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << neurologyDrs[i] << endl;
        }
        cout << endl;
        cout << "Orthopedic" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << orthopedicsDrs[i] << endl;
        }
        cout << endl;
        cout << "Pediatrics" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << pediatricsDrs[i] << endl;
        }
        cout << endl;
        cout << "General Medicine" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << generalMedicineDrs[i] << endl;
        }
        cout << endl;
        cout << "Emergency" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << emergencyDrs[i] << endl;
        }
        cout << endl;
    }

    void emergencyList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->emergencyLevel == true)
            {
                cout << "Patient Name: " <<curr->name<<endl;
                cout << "Doctor Name: " <<curr->doctorName<<endl;
                cout << "Gender" <<curr->gender<<endl;
                cout << "Age: " <<curr->age<<endl;
                cout << "Disease: " <<curr->disease<<endl;
            }
            curr = curr->next;
        }
        cout<<endl;

    }

    void addEmergencyPatient(string name, string doctorName, int tokenNumber, string gender, int age, string disease){
         Node *new_node = new Node(name, doctorName, tokenNumber, gender, age, disease, true);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
            token++;
            cout << "Token no: " << tokenNumber << endl;
            cout << "Patient Added Successfully!" << endl;
            cout<<endl;
            return;
        }
    if (!head->emergencyLevel){
       new_node->next=head;
       head=new_node;
        cout << "Token no: " << tokenNumber << endl;
        cout << "Patient Added Successfully!" << endl;
        cout<<endl;
       return;
    }

    Node *curr =head;
    while(curr->next!=nullptr && curr->next->emergencyLevel){
       curr=curr->next;
    }

    new_node->next=curr->next;
    curr->next=new_node;
    cout<<"Patient Added Successfully!"<<endl;
    if(new_node->next==nullptr){
        tail=new_node;
    }
}
};



LinkedList *l = new LinkedList();
void enqueue()
{
    string patientname, doctorName, gender, disease;
    int drChoice;
    int drchoice2;
    int drchoice3;
    int age;
   
    cout << "Enter patient's name: ";
    cin.ignore();
    getline(cin, patientname);

    cout << "View Doctors by Category" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << departments[i] << endl;
    }
    cout << "Enter Choice: ";
    cin >> drchoice3;
    switch (drchoice3)
    {
    case 1:
        for (int i = 0; i < 3; i++)
        {
            cout << cardiologyDrs[i] << endl;
        }
        cout<<"Enter choice: ";
        cin >> drchoice2;
        cout<<endl;
        if (drchoice2 == 1)
        {
            doctorName = "Dr. Ahmed Khan";
        }
        else if (drchoice2 == 2)
        {
            doctorName = "Dr. Hassan Raza";
        }
        else
        {
            doctorName = "Dr. Salman Iqbal";
        }
        break;
    case 2:
        for (int i = 0; i < 3; i++)
        {
            cout << neurologyDrs[i] << endl;
        }
        cout<<"Enter choice: ";
        cin >> drchoice2;
        cout<<endl;
        if (drchoice2 == 1)
        {
            doctorName = "Dr. Sara Malik";
        }
        else if (drchoice2 == 2)
        {
            doctorName = "Dr. Adeel Sheikh";
        }
        else
        {
            doctorName = "Dr. Nimra Iqbal";
        }
        break;
    case 3:
        for (int i = 0; i < 3; i++)
        {
            cout << orthopedicsDrs[i] << endl;
        }
        cout<<"Enter choice: ";
        cin >> drchoice2;
        cout<<endl;
        if (drchoice2 == 1)
        {
            doctorName = "Dr. Usman Ali";
        }
        else if (drchoice2 == 2)
        {
            doctorName = "Dr. Bilal Akram";
        }
        else
        {
            doctorName = "Dr. Faizan Noor";
        }

        break;
    case 4:
        for (int i = 0; i < 3; i++)
        {
            cout << pediatricsDrs[i] << endl;
        }
        cout<<"Enter choice: ";
        cin >> drchoice2;
        cout<<endl;
        if (drchoice2 == 1)
        {
            doctorName = "Dr. Ayesha Noor";
        }
        else if (drchoice2 == 2)
        {
            doctorName = "Dr. Hina Javed";
        }
        else
        {
            doctorName = "Dr. Ali Hamza";
        }
        break;
    case 5:
        for (int i = 0; i < 3; i++)
        {
            cout << generalMedicineDrs[i] << endl;
        }
        cout<<"Enter choice: ";
        cin >> drchoice2;
        cout<<endl;
        if (drchoice2 == 1)
        {
            doctorName = "Dr. Bilal Hassan";
        }
        else if (drchoice2 == 2)
        {
            doctorName = "Dr. Kamran Shah";
        }
        else
        {
            doctorName = "Dr. Taha Siddiqui";
        }
        break;
    default:
        cout << "Enter correct choice." << endl;
        break;
    }
    cin.ignore();

    cout << "Enter patient's age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter patient's gender: ";
    getline(cin, gender);
    cout << "Enter patient's disease: ";
    getline(cin, disease);
    
l->addPatient(patientname, doctorName, token, gender, age, disease);
cout<<endl;
   

}



void enqueueEmergencyPatient(){
    string patientname, doctorName, gender, disease;
    int age;
    int choice;
     cin.ignore();
    cout << "Enter patient's name: ";
    getline(cin, patientname);
   
    cout<<"Enter Patient Age: ";
    cin>>age;
    cin.ignore();
    cout<<"Enter Patient gender: ";
    getline(cin,gender);
    
    cout<<"Enter Patient disease: ";
    getline(cin,disease);
    cout<<endl;
     cout << "View Emergency Doctors" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << emergencyDrs[i] << endl;
    }
    cout<<endl;
    cout << "Enter Choice: ";
    cin>>choice;

    if (choice == 1)
        {
            doctorName = "Dr. Fahad Qureshi";
        }
        else if (choice == 2)
        {
            doctorName = "Dr. Imran Aslam";
        }
        else
        {
            doctorName = "Dr. Saad Rehman";
        }

        l->addEmergencyPatient(patientname,doctorName,token,gender,age,disease);
        cout<<endl;
}

void displayAllPatients()
{
    l->show_patients();
}

void upcomingPatient()
{
    l->showNextPatient();
}

void moveToNextPatient()
{
    l->dequeue();
}

void search_patient_by_name()
{
    l->search_by_name();
}

void search_patient_by_token_number()
{
    l->search_by_token();
}

void search_patient_by_doctors_name()
{
    l->search_by_doctors_name();
}

void delete_by_patient_name()
{
    l->delete_patient_by_name();
}
void updatePatientInfo()
{
    l->updatePatient();
}
void allDoctors()
{
    l->showAllDr();
}
void emergencyPatientsList()
{
    l->emergencyList();
}
void emergencyPatients()
{
    enqueueEmergencyPatient();
}
int main()
{
    int choice;
     cout<<"\t\t\t\t\t\t\t==================== Clinic Management System ===================="<<endl;
    do
    {
       
        cout << "1. Add Patient" << endl;
        cout << "2. Add Emergency Patient" << endl;
        cout << "3. Show All Patients" << endl;
        cout << "4. Show Next Patient" << endl;
        cout << "5. Serve Next Patient" << endl;
        cout << "6. Search Patient by Name" << endl;
        cout << "7. Search Patient by Token" << endl;
        cout << "8. Search Patients By Doctor's Name" << endl;
        cout << "9. Update Patient Info" << endl;
        cout << "10. Discharge Patient" << endl;
        cout << "11. Show All Doctors" << endl;
        cout << "12. Show Emergency Patients" << endl;
        
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            enqueue();
        }
        else if (choice == 2)
        {
            emergencyPatients();
        }
        else if (choice == 3)
        {
            displayAllPatients();
        }
        else if (choice == 4)
        {
            upcomingPatient();
        }
        else if (choice == 5)
        {
            moveToNextPatient();
        }
        else if (choice == 6)
        {
            search_patient_by_name();
        }
        else if (choice == 7)
        {
            search_patient_by_token_number();
        }
        else if (choice == 8)
        {
            search_patient_by_doctors_name();
        }
        else if (choice == 9)
        {
            updatePatientInfo();
        }
        else if (choice == 10)
        {
            delete_by_patient_name();
        }
        else if (choice == 11)
        {
            allDoctors();
        }

         else if (choice == 12)
        {
            emergencyPatientsList();
        }
    } while (choice != 0);
}