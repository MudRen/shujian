// maotan.c ë̺

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"�廨��̺֯"NOR, ({"mao tan", "maotan"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "
            ����һ���ֹ���֯�Ĵ�ë̺��̺ëϸ�ܺ�ʵ������ȥ�ǳ�����\n
            ���Թ���ǽ�ڻ����ڵذ��ϡ�\n");
                set("unit", "��");
                set("value", 50000);
        }
}
