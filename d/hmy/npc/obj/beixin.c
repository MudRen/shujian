// jinshe-beixin.c ���߱���

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("���߱���", ({ "jin shebeixin","jin","shebeixin","jinshebeixin" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����������ı��ģ�ͨ���ý�˿��֯���ؿڴ�
���ž������Ƶ��������ߣ��������ţ������ݶ�ɢ����һ��а����\n");
		set("material", "steel");
		set("unit", "��");
		set("value", 600000);
		set("wear_msg", HIY "ֻ����ɳɳ�����죬$N����һ���������ı����������ϡ�
˲������ˣ��Ǽ������߷·�ҡ��Ť���Ŷ�������\n" NOR);
		set("remove_msg", HIY "$N�����߱��Ĵ����������������۵���СС��һ�š�\n" NOR);
		set("armor_prop/armor", 100);
	}
	setup();
}
