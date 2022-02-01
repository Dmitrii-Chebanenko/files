#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class file
{
    private:
    string name;
    int value;
    string type;
    string datenew, datechange;
    string dostup;
    public:
    file(string name, double value, string type, string datenew, string datechange, string dostup)
    {
        this->name = name;
        this->value = value;
        this->type = type;
        this->datenew = datenew;
        this->datechange = datechange;
        this->dostup = dostup;
    }
    file ()
    {
        name = "";
        value = 0;
        type = "";
        datenew = "";
        datechange = "";
        dostup = "";
    }
    string Getname()
    {
        return name;
    }
    int Getvalue()
    {
        return value;
    }
     string Gettype()
    {
        return type;
    }
     string Getdatenew()
    {
        return datenew;
    }
     string Getdatechange()
    {
        return datechange;
    }
     string Getdostup()
    {
        return dostup;
    }
    void print()
    {
        cout<<name<<" "<<value<<" "<<type<<" "<<datenew<<" "<<datechange<<" "<<dostup<<endl;
    }
};

bool change(string s)
{
    auto q = s.find('.');
    s.erase(q, 1);
    auto q1 = s.find('.');
    string s1 = "";
    for (size_t i = q1+1; i < s.size(); i++)
    {
        s1+=s[i];
    }
    if(s1 == "2012")
    {
        return true;
    }
    else
    {
        return false;
    } 
}

bool change1(string s)
{
    auto q = s.find('.');
    string s2 = "";
    for (size_t i = q+1; i < q+2; i++)
    {
        s2+=s[i];
    }
    
    s.erase(q, 1);
    auto q1 = s.find('.');
    string s1 = "";
    for (size_t i = q1+1; i < s.size(); i++)
    {
        s1+=s[i];
    }
    if(s1 == "2011" && s2<="06")
    {
        return true;
    }
    else
    {
        return false;
    } 
}

int main()
{
    setlocale(LC_ALL, "RUS");
    ifstream fin;
    fin.open("D:/C++_school/files.csv");
    string name;
    int value;
    string type;
    string datenew, datechange;
    string dostup;
    char temp;
    size_t count = 280;
    vector<file> arr;
    map<string, int> num;
    for (size_t i = 0; i < count; i++)
    {
        getline(fin, name, ',');
        fin>>value;
        fin>>temp;
        getline(fin, type, ',');
        getline(fin, datenew, ',');
        getline(fin, datechange, ',');
        getline(fin, dostup);
        arr.push_back(file(name, value, type, datenew, datechange, dostup));
    }
    cout<<"-----------------------------\n";
    for (size_t i = 0; i < count; i++)
    {
        num[arr[i].Gettype()]++;
    }
    for (auto it = num.begin(); it != num.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"-----------------------------\n";
    vector<file> arr1(arr);
    sort(arr1.begin(),arr1.end(),[](file a, file b)
    {
        if(a.Getvalue()<b.Getvalue())
            return 1;
        else
            return 0;  
    }
    );
    arr1.erase(arr1.begin(), arr1.end()-10);
    sort(arr1.begin(), arr1.end(), [](file a, file b)
    {
        if(a.Getname()<b.Getname())
            return 1;
        else
            return 0;
    }
    );
    for (auto &l : arr1)
    {
        cout<<l.Getname()<<" "<<l.Getvalue()<<endl;
    }
    cout<<"-----------------------------\n";
    arr1.clear();
    vector <file> vec;
    for (size_t i = 0; i < arr.size(); i++)
    {
        string s = arr[i].Getdatechange();
        if(change(s) && arr[i].Gettype()=="презентация" && arr[i].Getdostup() == "ограничен")
        {
            vec.push_back(arr[i]);
        }
    }
    sort(vec.begin(), vec.end(), [](file a, file b)
    {
        if(a.Getname()<b.Getname())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    );
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout<<vec[i].Getname()<<" "<<vec[i].Gettype()<<" "<<vec[i].Getdostup()<<" "<<vec[i].Getdatechange()<<endl;
    }
    cout<<"-----------------------------------------------------------------------\n";
    vec.clear();
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(change1(arr[i].Getdatenew()) && arr[i].Getvalue()/1024>100)
        {
            vec.push_back(arr[i]);
        }
    }
    sort(vec.begin(), vec.end(), [](file a, file b)
    {
        if(a.Getvalue()>b.Getvalue())
            return true;
        else
            return false;
    }
    );
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout<<vec[i].Getname()<<" "<<vec[i].Gettype()<<" "<<vec[i].Getvalue()<<" "<<vec[i].Getdatenew()<<endl;
    }
}