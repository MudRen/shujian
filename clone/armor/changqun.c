// OBJ : /d/xiangyang/npc/obj/changqun.c �廨��ȹ
// By Lklv 2001.9.26

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIG"��ɫ��ȹ"NOR, ({"chang qun", "changqun", "qunzi"}) );
	set_weight(400);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIG"һ������ɫ���廨��ȹ��\n"NOR);
		set("material", "cloth");
		set("value", 4500);
		set("armor_prop/armor", 2);
	}
	setup();
}
