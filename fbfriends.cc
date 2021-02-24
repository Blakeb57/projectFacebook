#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include "fbfriends.h"
using namespace std;

FBFriends::FBFriends()
{
    data = new Friend[5];
    capacity = 5;
    used = 0;
    current_index = 0;
}

FBFriends::FBFriends(const FBFriends& other)
{
    capacity = other.capacity;
    used = other.used;
    data = new Friend[capacity];
    copy(other.data, other.data + used, data);
}

FBFriends::~FBFriends()
{
    delete [] data;
}

void FBFriends::operator = (const FBFriends& other)
{
    if(this == &other)
    {
        return;
    }

    delete [] data;
    used = other.used;
    capacity = other.capacity;
    data = new Friend[capacity];
    copy(other.data, other.data + used, data);
}

void FBFriends::start()
{
    current_index = 0;
}

void FBFriends::advance()
{
    current_index++;
}

bool FBFriends::is_item()
{
    return current_index < used;
}

Friend FBFriends::current()const
{
    return data[current_index];
}

void FBFriends::remove_current()
{
    if(is_item())
    {
        for(int i = current_index; i < used; ++i)
        {
            data[i] = data[i + 1];
        }
        used--;
    }
}

void FBFriends::insert(const Friend& f)
{

    if(used >= capacity)
    {
        this->resize();
        this->insert(f);
    }

    for(int i = used-1; i >= current_index; --i)
    {
        data[i+1] = data[i];
    }

    data[current_index].set_name(f.get_name());
    data[current_index].set_bday(f.get_bday());

    used++;
}

void FBFriends::attach(const Friend& f)
{
    if(used == capacity)
    {
        resize();
    }

    if(!is_item())
    {
        data[used] = f;
        used++;
    }else
    {   
        for(int i = used; i > current_index + 1; --i)
        {
            data[i] = data[i - 1];
        }
        data[current_index + 1] = f;
        current_index++;
    }
}

void FBFriends::show_all(std::ostream& outs)const
{
    Friend tmp;

    for(int i = 0; i < used; ++i)
    {
        outs << data[i].get_name() << endl;
    }
}

void FBFriends::bday_sort()
{
    bool done = false;
    Friend tmp;

    while(!done)
    {
        done = true;

        for(int i = used - 1; i > 0; --i)
        {
            if(data[i].get_bday() < data[i-1].get_bday())
            {
                done = false;
                tmp = data[i];
                data[i] = data[i-1];
                data[i-1] = tmp;
            }
        }
    }
}

Friend FBFriends::find_friend(const std::string& name)const
{
    int index = -1;
    
    for(int i = 0; i < used; ++i)
    {
        if(name == data[i].get_name())
        {
            index = i;
        }
    }

    if(index != -1)
    {
        return data[index];

    }else
    {
        cout << name << " could not be found in your friends list." << endl;
    }
}

bool FBFriends::is_friend(const Friend& f)const
{
    Friend tmp;

    for(int i = 0; i < used; i++)
    {
        if(data[i] == (f))
        {
            return true;
        }
    }
    return false;
}

void FBFriends::load(std::istream& ins)
{
    Friend *tmp;

    while(!ins.eof())
    {
        tmp = new Friend;
        tmp -> input(ins);
        data[used] = *tmp;
        used++;
    }
}

void FBFriends::save(std::ostream& outs)const
{
    for(int i = 0; i < used; ++i)
    {
        if(i == used - 1)
        {
            outs << data[i];
        }else
        {
            outs << data[i] << endl;
        }
    }
}

void FBFriends::resize()
{
    Friend *tmp = new Friend[capacity+5];
    copy(data, data + used, tmp);
    delete [] data;
    data = tmp;
    capacity += 5;
}