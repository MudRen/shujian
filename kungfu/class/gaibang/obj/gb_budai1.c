
#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(YEL"һ������"NOR, ({ "bu dai", "budai", "dai", "bag" }));
	set_weight(100);
	set_max_encumbrance(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ô��鲼֯�ɵĴ��ӣ��������������Ķ��٣���ؤ����ӽ�����λ�ı�־��\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
		set("remove_msg", "$N�����ϵĲ���С�ĵس���������\n");
		set("wear_msg", "$N�������������\n");
		set("armor_prop/armor", 1);
		set("no_get","��Ϊؤ����ӣ��������ڣ�����������\n");
		set("no_drop", "��Ϊؤ����ӣ��������ڣ�����������\n");
		set("no_give", "��Ϊؤ����ӣ��������ڣ�����������\n");
        }
	set("armor_type", "gaibang");
        setup();
}

int unequip()
{
	object ob = environment();
	if (ob)
		return notify_fail("������ؤ�������ݵ��������㲻�ܰ������£�\n");
	return ::unequip();
}
