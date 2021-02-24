#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include "fbfriends.h"
using namespace std;

Friend::Friend(Date b, string n)
{
    bday = b;
    name = n;
}

void Friend::set_name(const std::string& sn)
{
    this -> name = sn;
}

void Friend::set_bday(const Date d)
{
    this -> bday = d;
}

void Friend::input(std::istream& ins)
{

    if(&ins == &cin)
    {
        cout << "Please enter the name of the friend you want to add: ";
        ins >> name;
        cout << endl;
        cout << "Please enter the birthday of your new friend: ";
        ins >> bday;
        cout << endl;

        //cout << get_name() << " " << get_bday() << " Is now added to your friends list." << endl;
    }else
    {
        ins >> name;
        ins >> bday;

        cout << get_name() << " " << get_bday() << endl;
        cout << "Is now added to your friends list." << endl;
    }
}

void Friend::output(std::ostream& outs)const
{
    if(&outs == &cout)
    {
        outs << "Friend Name: " << get_name() << endl;
        outs << "Friend's birthday: " << get_bday() << endl;
    }else
    {
        outs << get_name() << endl;
        outs << get_bday();
    }
}

ostream& operator << (ostream& outs, const Friend& f)
{
    f.output(outs);
    return outs;
}

istream& operator >> (istream& ins, Friend& f)
{
    string line;  
    f.input(ins);
    return ins;
}

bool Friend::operator == (const Friend& other)const
{
    if (this->name == other.get_name() && this->bday == other.get_bday()){
        return true;
    } else {
        return false;
    }
}

bool Friend::operator != (const Friend& other)const
{
    if (this->name != other.get_name() || this->bday != other.get_bday()){
        return true;
    } else {
        return false;
    }
}