// book1.c �����˲�8
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"Ħ������ƪ"NOR, ({"mohuluojia pian","shu","book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������˲���֮��--Ħ������ƪ��\n");
		set("unit", "��");
	     }
}
