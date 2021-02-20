/*****************************************************
   This class is a container that holds Friends of the
   class Friend. It uses an internal iterator to give the
   application the ability to order the container as well
   as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.
     John Dolan		Spring 2021	Ohio University
*********************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

class FBFriends
{
    public:
		FBFriends();

		//The functions known as the Big 3
		~FBFriends();																//Deconstructor, done
		FBFriends(const FBFriends& other);											//Copy constructor, done
		void operator = (const FBFriends& other);									//Assignment operator, done

		// Functions for the internal iterator
		void start();
		void advance();
		bool is_item()const;
		Friend current()const;
		void remove_current();
		void insert(const Friend& f);
		void attach(const Friend& f);
		void show_all(std::ostream& outs)const;
		void bday_sort();
		Friend find_friend(const std::string& name)const;
		bool is_friend(const Friend& f) const;
		void load(std::istream& ins);
		void save(std::ostream& outs)const;

    private:
		void resize(); // increases the capacity of the container by 5
		Friend *data;
		int used;
		int capacity;
		int current_index;
};

#endif
