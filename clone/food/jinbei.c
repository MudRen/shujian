// Write by Yanyang@SJ 2000.9.23
// jinbei.c  С��

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
        set_name(HIY"С��"NOR, ({"xiao jinbei", "jinbei", "bei"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�ý��Ӵ���ľƱ�������������������ˡ�\n");
                set("unit", "ֻ");
                set("value", 3000);
                set("max_liquid", 1);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "Ů����",
                "remaining": 1,
                "drunk_apply": 50,
        ]));
}
