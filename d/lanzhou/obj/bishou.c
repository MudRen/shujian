#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"ذ��"NOR,({"bishou", "dagger"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "��");
                set("value", 7000);
                set("material", "steal");
                set("unique",1);
                set("long",HIY"����һ�Ѿ���ذ�ף������Ͽ��š������������֡�\n"NOR);
	}
	init_sword(20);
	setup();
}
