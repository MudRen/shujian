// chuanliu-dao.c ���㴩����

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name( HIC"���㴩����"NOR , ({ "chuanliu dao", "dao", "blade" }));
	set_weight(12500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIC"����һ�ѱ��������������������ͣ�ɢ��������Ѥ�������⡣\n"NOR);
		set("value", 10000);
		set("unique", 1);
		set("rigidity", 3);
		set("weapon_prop/parry", 5);
		set("wield_neili", 100);
		set("wield_maxneili", 900);
		set("wield_str", 20);
		set("treasure",1);
		set("material", "steel");
		set("wield_msg", HIC"$N����һ��һ����˲�������Ѷ���һ������\n"NOR);
		set("unwield_msg",HIC" $N����һ�������㴩������ʱʧȥ����Ӱ��\n"NOR);
	}
	init_blade(40);
	setup();
}

int wield()
{
	object ob = environment();

	if( !ob || !living(ob) ) return 0;

	if( (int)ob->query_skill("yanxing-daofa", 1) > 60 ) {
		set("weapon_prop/damage" , 60 );
		set("weapon_prop/attack" , ob->query_skill("yanxing-daofa",1)/8 );
		if( query("weapon_prop/attack") > 60 )
			set("weapon_prop/attack" , 60 );
	}
	else {
		set("weapon_prop/damage" , 40 );
		set("weapon_prop/attack" , 0 );
	}
	if( !query("weapon_prop/damage")) return 0;
	return ::wield();
}
