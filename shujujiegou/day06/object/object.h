#ifndef _OBJECT_H
#define _OBJECT_H
struct user
{
    int id;
    char user_name[15];
    char user_pass[15];
};
struct user_Node;
{
	 struct user data;
    struct user_info*next;
};
typedef struct user user ;
typedef struct user_info user_Node;
#endif
