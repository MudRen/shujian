// zi-manao.c
// Created by Numa 19990911

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG"�����"NOR,({ "zi manao","manao" }));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else
        {
        	set("unit","��");
        	set("long","����һ��ҫ���۾�������解�һ����֪�����޼�֮����");
        	set("value",0);
        }
	setup();
}
