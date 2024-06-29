#include "employees.h"

employees::employees() {
        name = "";
        age = 0;
        pol = "";
        experience = 0;
        salary = 0;
        hoursweek = 0;
    }
employees::employees(std::string name, int age, string pol, double experience, int salary, int hoursweek) {
        this->name = name;
        this->age = age;
        this->pol = pol;
        this->experience = experience;
        this->salary = salary;
        this->hoursweek = hoursweek;
    }

    bool employees::operator<(const employees& other) const {
        return name < other.name;
    }

    void employees::edit_data() {
        std::string tmp = "";
        cout << "Что хотите изменить? (Name, Age, Pol, Experience, Salary, Hoursweek)" << endl;
        cin >> tmp;

        if (tmp == "Name" || tmp == "name") {
            cout << "Ââåäèòå íîâîå èìÿ: ";
            cin >> name;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else if (tmp == "Age" || tmp == "age") {
            cout << "Ââåäèòå íîâûé âîçðàñò: ";
            cin >> age;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else if (tmp == "Pol" || tmp == "pol") {
            cout << "Ââåäèòå íîâûé ïîë: ";
            cin >> pol;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else if (tmp == "Experience" || tmp == "experience") {
            cout << "Ââåäèòå íîâûé ñòàæ: ";
            cin >> experience;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else if (tmp == "Salary" || tmp == "salary") {
            cout << "Ââåäèòå íîâóþ çàðïëàòó: ";
            cin >> salary;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else if (tmp == "Hoursweek" || tmp == "hoursweek") {
            cout << "Ââåäèòå íîâîå êîëè÷åñòâî ÷àñîâ â íåäåëþ: ";
            cin >> hoursweek;
            cout << "Äàííûå ñîòðóäíèêà îáíîâëåíû!\n";
        }
        else {
            cout << "Âû ââåëè íåâåðíûå äàííûå, êîòîðûå íå îáíîâëåíû ó ñîòðóäíèêà!\n";
        }
    }

    void employees::addemployee(std::set<employees>& employees_list) {
        string tmp5="";
        int employee_count = 0;
        cout << "Ââåäèòå, ñêîëüêî ñîòðóäíèêîâ âû õîòèòå äîáàâèòü? ";
        cin >> tmp5;
        if (all_of(tmp5.begin(), tmp5.end(), ::isdigit)) {
            employee_count = stoi(tmp5);
            cin.ignore();
            for (int i = 0; i < employee_count; ++i) {
                string name = "", pol = "";
                int age = 0, salary = 0, hoursweek = 0;
                double experience = 0;
                
                string tmp1 = "", tmp2 = "", tmp3 = "", tmp4 = "";

                cout << "Ââåäèòå èìÿ ñîòðóäíèêà: " << i + 1 << ": ";
                if (i > 0) {
                    cin.ignore();
                }
                getline(cin, name);
                do {
                    
                    cout << "Ââåäèòå âîçðàñò ñîòðóäíèêà: ";
                    cin >> tmp1;
                    if (all_of(tmp1.begin(), tmp1.end(), ::isdigit)) {
                        age = stoi(tmp1);
                        if (age <= 15 || age >= 120) {
                            cout << "Âîçðàñò íåâîçìîæåí! Ïîæàëóéñòà, ââåäèòå âîçðàñò îò 16 äî 119" << endl;

                        }
                    }
                    else {
                        cout << "Âîçðàñò òàêèì áûòü íå ìîæåò, ââåäèòå êîððåêòíî!\n";
                    } 
                } while (age <= 15 || age >= 120);

                cout << "Ââåäèòå ïîë ñîòðóäíèêà(m/j): ";
                cin >> pol;


                do {
                    cout << "Ââåäèòå ñòàæ(îïûò) ñîòðóäíèêà: ";
                    cin >> tmp2;
                    if (all_of(tmp2.begin(), tmp2.end(), ::isdigit)) {
                        experience = stoi(tmp2);
                        if (experience <= 0 || experience >= 80) {
                            cout << "Ñòàæ(îïûò) òàêèì áûòü íå ìîæåò!" << endl;
                        }
                    }
                    else {
                        cout << "Îïûò òàêèì áûòü íå ìîæåò, ââåäèòå êîððåêòíî!\n";
                    }
                } while (experience <= 0 || experience >= 80);

                do {

                    cout << "Ââåäèòå çàðïëàòó ñîòðóäíèêà: ";
                    cin >> tmp3;
                    if (all_of(tmp3.begin(), tmp3.end(), ::isdigit)) {
                        salary = stoi(tmp3);
                        if (salary <= 0 || salary >= 4000000) {
                            cout << "Çàðïëàòà òàêîé áûòü íå ìîæåò!" << endl;
                        }
                    }
                    else {
                        cout << "Çàðïëàòà òàêîé áûòü íå ìîæåò, ââåäèòå êîððåêòíî!\n";
                    } 
                } while (salary <= 0 || salary >= 4000000);

                do {
                    cout << "Ââåäèòå ÷àñû ðàáîòû â íåäåëþ ñîòðóäíèêà: ";
                    cin >> tmp4;
                    if (all_of(tmp4.begin(), tmp4.end(), ::isdigit)) {
                        hoursweek = stoi(tmp4);
                        if (hoursweek > 40) {
                            cout << "×åëîâåê íå ìîæåò ðàáîòàòü áîëåå 40 ÷àñîâ â íåäåëþ ïî çàêîíó!" << endl;
                        }
                    }
                    else {
                        cout << "Ââîäèòå ÷àñû ðàáîòû êîððåêòíî!\n";
                    } 
                } while (hoursweek <= 0 || hoursweek > 40);
                employees new_employee(name, age, pol, experience, salary, hoursweek);
                employees_list.insert(new_employee);
            }
            cout << "Ñîòðóäíèêè äîáàâëåíû!\n";
        }
        else {
            cout << "Ââåäèòå êîððåêòíîå ÷èñëî!\n";
        }
    }



    void employees::delete_employee(std::set<employees>& employees_set) {
        try {
            if (!employees_set.empty()) {

                cout << "Ââåäèòå íîìåð ñîòðóäíèêà äëÿ óäàëåíèÿ: ";
                int index;
                cin >> index;
                if (index >= 1 && index <= employees_set.size()) {
                    auto it = employees_set.begin();
                    std::advance(it, index - 1); // Ïåðåìåùàåì èòåðàòîð íà íóæíóþ ïîçèöèþ
                    employees_set.erase(it); // Óäàëÿåì ñîòðóäíèêà èç set
                    std::cout << "Ñîòðóäíèê ¹" << index << " óäàëåí!\n";
                }
                else {
                    throw std::out_of_range("Íåâåðíûé íîìåð ñîòðóäíèêà! Äîïóñòèìûé äèàïàçîí: 1-" + std::to_string(employees_set.size()));
                }
            }
            else {
                throw std::runtime_error("Ñïèñîê ñîòðóäíèêîâ ïóñò!");
            }
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Îøèáêà: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Îøèáêà: " << e.what() << std::endl;
        }
    }


    void employees::print() const {
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Pol: " << this->pol << endl;
        cout << "Experience: " << this->experience << endl;
        cout << "Salary: " << this->salary << endl;
        cout << "Hoursweek: " << this->hoursweek << endl;
        cout << endl;
    }
 
