// daopao.c ��ɫ����
// By XiaoYao

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({"qingse daopao", "cloth", "dao pao"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǽ�ϴ�˷��׵���ɫ���ۡ�\n");
		set("material", "cloth");
                set("armor_prop/armor", 10);
	}
	setup();
}
