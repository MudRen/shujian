
#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(YEL"�Ÿ�����"NOR, ({ "bu dai", "budai", "dai", "bag" }));
	set_weight(900);
	set_max_encumbrance(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"��ֻ�ô��鲼֯�ɵĴ��ӣ��������������Ķ��٣���ؤ����ӽ�����λ�ı�־��\n"NOR);
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
		set("remove_msg", "$N�����ϵĲ�������������\n");
		set("wear_msg", "$N������С�ĵر������\n");
		set("armor_prop/armor", 9);
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
