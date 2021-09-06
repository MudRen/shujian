#include <ansi.h>

inherit COMBINED_ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("��ɳ��Ӱ", ({ "hansha sheying", "hansha" }));
	if (clonep()) set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ��С��ϻ�ӣ�������������ŷ�ɥ���ĺ�ɳ��Ӱ��\n");
                set("value", 1);
                set("unique", 1);
		set("unit", "��");
                set("material", "steel");
                set("treasure",1);
		set("base_value", 10000);
		set("base_unit", "��");
		set("base_weight", 5000);
	}
	set_amount(1);
}

void init()
{
	if (environment() == this_player())
		add_action("do_shoot", "shoot");
}

int do_shoot(string arg)
{
	//object me = this_object();
	object ob = this_player();
	object victim;

	if (!arg) return 0;
	victim = present(arg, environment(ob));
	if (!victim || !living(victim)) return notify_fail("��Ҫ��˭���֣�\n");
	if (victim->query_condition("man_poison"))
		return notify_fail(victim->name()+"�Ѿ��ж��ˡ�\n");
	write("�������ƶ�"+name()+"�Ļ��أ�һ���ϸ���뼱���������������"+victim->name()+"���ϡ�\n");
	tell_room(environment(ob), ob->name()+"�����ƶ�"+name()
		+"�Ļ��أ�һ���ϸ���뼱���������������"+victim->name()+"���ϡ�\n", ({ ob, victim }));
	victim->set_temp("last_damage_from", "�к�ɳ��Ӱ");
        victim->die();
	add_amount(-1);
	return 1;
}
