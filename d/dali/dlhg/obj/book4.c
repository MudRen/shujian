// book1.c �����˲�4
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"Ǭ����ƪ"NOR, ({"qiandapo pian","shu","book"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������˲���֮��--Ǭ����ƪ��\n");
		set("unit", "��");
	     }
}
