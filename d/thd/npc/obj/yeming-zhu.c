// yeming-zhu.c
// Created by Numa 19990911

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ҹ����"NOR,({ "yeming zhu","zhu" }));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else
        {
        	set("unit","��");
        	set("long","����һ�����������ҹ���飬һ����֪�����޼�֮����");
        	set("value",0);
        }
	setup();
}
