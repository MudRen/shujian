//nianzhu.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( "����", ({ "nian zhu", "nianzhu" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�����飬�ڳ����Ĳ�֪����ʲô�Ƴɵģ��������ǳ�Բ����ؾ���������������\n");
		set("value", 0);
		set("material", "hand");
		set("armor_prop/armor", 5);
			}
	setup();
}
