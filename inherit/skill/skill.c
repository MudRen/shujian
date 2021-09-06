//      skill.c
//
// This is the standard skill daemon object. All objects defining a skill
// should inherit this as its skeleton.
// last modify by snowman@SJ 13/03/2000
// modified by tiantian@sj 5/24/2000
// Modified by snowman@SJ 05/06/2000
// Tiantian, �ҽ� exert_function ��� douzhuan ɾ���ˣ�ֻ���� perform_action ��ġ�
/* 
   Modified by snowman@SJ 08/12/2000
   �� exert_function() & perform_action() ������ֱ�ᵽ exert.c & perform.c
   �������Ƿ���Խ�ԼһЩ�ڴ棿 :-)
*/
// ����һ��skill�ĸ������� by augx@sj

#include <ansi.h>
inherit F_SSERVER;

void create()
{
        seteuid(getuid());
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill. 

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
        return 1;
}

// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )��
// Currently we have only 2 types of skill: "martial" and "knowledge".

string type() { return "martial"; }
string type2() { return "none"; } // add by augx@sj , addition type

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level. 
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

// The following two functions are used to modify the random function
// for shaolin wugong.


int sum(int n,int base,int d)
{
        return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{ 
        int i = 1;
        int randnum = random(sum(n,base,d));

        if (sum(6,base,d) < randnum)
        { 
                i = 7;
                while (sum(i,base,d) < randnum)
                        i++;
        }
        else {
                while (sum(i,base,d) < randnum)
                        i++;
        } 
        return (i-1);
}

// added by snowman@SJ 05/03/2000
int double_attack(object me) { return 0; }
