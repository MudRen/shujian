
#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(HIY"ʮ������"NOR, ({ "bu dai", "budai", "dai", "bag" }));
	set_weight(1000);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ʮֻ�ô��鲼֯�ɵĴ��ӣ��������������Ķ��٣���ؤ����ӽ�����λ�ı�־��\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 0);
		set("remove_msg", "$N�����ϵĲ�������������\n");
		set("wear_msg", "$N������С�ĵر������\n");
		set("armor_prop/armor", 10);
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
