// lv-feicui.c
// Created by Numa 19990911

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"�����"NOR,({ "lv feicui","feicui" }));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else
        {
        	set("unit","��");
        	set("long","����һ������ͨ�������䣬һ����֪�����޼�֮����");
        	set("value",0);
        }
	setup();
}
