// jingang-zhao.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;
//inherit F_UNIQUE;
void create()
{
        set_name(HIY"�ڽ���"NOR, ({ "wujin beixin", "wujin", "beixin" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�������һ�����ģ�������������ģ������ڽ�˿��ͷ�����ͽ�˿��ë��ͬ֯��,
�κ������ı��ж��������á�\n");
                set("material", "silk");
                set("unit", "��");
                //set("unique", 1);
		  //set("treasure", 1);
                set("value", 1000000);
                set("wear_msg", HIY "$N����һ��$n��\n" NOR);
                set("remove_msg", HIY "$N��$n����������\n" NOR);
        	set("armor_prop/armor", 200);
             set("dzd",1);

        }
        setup();
}

