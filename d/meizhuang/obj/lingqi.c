// /d/meizhuang/obj/lingqi.c ��������

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"��������"NOR, ({ "wuyue lingqi","wuse lingqi", "lingqi" }));
        set_weight(1000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���ϵȳ�����ɵ����ģ�������ҫ���������������鱦ʯ��\n");
                set("value", 100000000);
        }
        setup();
}
