// /d/dzd/obj/mujian.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
//inherit F_UNIQUE;

void create()
{
	set_name("̴��ľ��",({"tanxiang mujian","mujian","jian","sword"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",1000);
		set("meterial","wood");
             set("dzd",1);

		set("long","����һ����������ľ�Ƴɵ�ľ�������е��ƣ������ŵ�һ�ɵ�����������\n");
		set("wield_msg",HIY"$N��ƮƮ�ĳ��һ��̴��ľ�����漴һ�ɵ�������������������������\n"NOR);
		set("unwield_msg",HIY"$N����Ľ����������У�����Ҳ�����ĵ��ˡ�\n"NOR);
	}
	init_sword(100);
	setup();
}
