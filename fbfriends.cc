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

bool FBFriends::is_item()const
{
    current_index < used;
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

}

void FBFriends::attach(const Friend& f)
{

}

void FBFriends::show_all(std::ostream& outs)const
{

}

void FBFriends::bday_sort()
{

}

Friend FBFriends::find_friend(const std::string& name)const
{

}

bool FBFriends::is_friend(const Friend& f)const
{

}

void FBFriends::load(std::istream& ins)
{

}

void FBFriends::save(std::ostream& outs)const
{

}