#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
 set_name(HIR"ɱ����"NOR, ({ "shawei bang","bang" }));
       set_weight(8000);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("unit", "��");
               set("long", "һ���ִ��ֳ���ľ��ɱ��������ͷ��ɫ��\n");
               set("value", 10000000);
		set("unique", 1);
               set("sharpness",1);
		set("wield_str",26);
		set("rigidity",3);
               set("material", "wood");
               set("wield_msg", "$N�ó�һ����ͷ��ɫ��$n�������С�\n");
               set("unwield_msg", "$N�����е�$n���¡�\n");
       }
 	init_stick(60);
       setup();
}
