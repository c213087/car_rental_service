#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include "show_rent.h"

#include <unistd.h>
using namespace std;
void main_menu();
long long int cntrcar = 0;
long long int cntrday = 0;
long long int cntr = 0;
long long int car_num;
vector<string> v1, v2;

string customer_name;
void car_list_booked_list_update(int carup)
{
    ofstream out("car_list.txt");
    for (int i = 0; i != v1.size(); i++)
    {
        if (i != carup - 1)
        {
            out << v1[i] << endl;
            out << v2[i] << endl;
        }
    }
    out.close();
    vector<string> bv1, bv2;
    ifstream inb("booked.txt");
    string str;

    while (getline(inb, str))
    {
        bv1.push_back(str);

        string str1;

        getline(inb, str1);
        bv2.push_back(str1);
    }
    inb.close();
    ofstream outb("booked.txt");
    for (int i = 0; i != bv1.size(); i++)
    {
        outb << bv1[i] << endl;
        outb << bv2[i] << endl;
    }
    outb << v1[carup - 1] << endl;
    outb << v2[carup - 1] << endl;
    outb.close();
}
class rent_car
{
public:
    void rent_car1(string cus_name)
    {
        customer_name = cus_name;
        ifstream in("car_list.txt");
        string str;

        while (getline(in, str))
        {
            v1.push_back(str);

            string str1;

            getline(in, str1);
            v2.push_back(str1);
            cntr++;
        }
        in.close();
    }

    void rent_car_num()
    {

        string car_str;
        cout << "\nEnter the number of the car that you are willing to rent : ";
        cin >> car_str;

        car_num = stoi(car_str);
        // cout<< car_num<<"\n";
        cin.ignore();
        cout << endl
             << endl;

        if (car_num > cntr || car_num < 1)
        {
            cout << "\t\t Invalid car Number sir \n\n";
            rent_car_num();
        }
    }

    void rent_car_days()
    {
        string num_str;
        int num_days;
        cout << "\nEnter the number of days that you are willing to rent : ";
        cin >> num_str;
        num_days = stoi(num_str);
        cin.ignore();
        cout << endl
             << endl;

        if (num_days <= 10 && num_days >= 1)
        {
            int cc = stoi(v2[car_num - 1]);

            bool flag = Showing_rent_info(customer_name, car_num, v1[car_num - 1], v2[car_num - 1], cc, num_days);
            if (flag == true)
            {
                car_list_booked_list_update(car_num);
            }
        }
        else
        {
            cout << "                                Invalid\n\n";
            cout << "                         Any one can rent a car for\n\n"
                 << "                            Maximum of 10 days\n\n"
                 << "                            Minimum of 1 days\n\n";
            rent_car_days();
        }
    }
};
