// ryyaodai.c ��������
// creat by Lklv 2001.9.28

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name( HIC"��������"NOR, ({ "yao dai", "yaodai", "dai" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ���Ϻõ������������ɵ�������\n");
		set("value", 5000);
		set("material", "waist");
		set("wear_msg", "$N���˿���Χû�ˣ���ͷ��һ��"HIC"��������"NOR"ϵ�����ϡ�\n");
		set("remove_msg", "$N�����ؽ�"HIC"��������"NOR"��������£��������\n");
		set("armor_prop/armor", 5);
	}
	setup();
}
