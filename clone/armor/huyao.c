//Cracked by Kafei
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name( WHT"������"NOR, ({ "hu yao", "huyao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��Ƥ�ʵĻ����������������������Ա���������\n");
		set("value", 500);
		set("material", "iron");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
