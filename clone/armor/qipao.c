// OBJ : /d/xiangyang/npc/obj/qipao.c ��������
// By Lklv 2001.9.26

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIM"����"NOR, ({"qi pao", "qipao", "pao"}) );
	set_weight(3500);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIC"һ����ɫ���ۣ��������Щ�黨��\n"NOR);
		set("value", 5000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}
