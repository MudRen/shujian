// /clone/weapon/feiyan.c
// by leontt 2000/10/26

inherit COMBINED_ITEM;
#include <ansi.h>
#include "/inherit/item/embed.h"

void create()
{
	set_name(CYN"����"NOR, ({ "fei yan","yan"}) );
	set_weight(200);
	if( clonep() )
		 set_default_object(__FILE__);
	else {
		set("long", CYN"����һ������������״��������������β�ϳ����˵��̡�\n"NOR);
		set("unit", "��");
		set("damage", 12);
		set("base_value",400);
		set("base_unit", "��");
		set("base_weight", 100);
		set("throw_msg", HIR"$N���ְ������У�ʳָһ�������໮��һ����ɫ�Ļ�������$n��\n"NOR);
		set("material", "steel");
		set("embed", 1);
	}
	set_amount(1);
}
