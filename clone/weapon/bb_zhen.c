inherit ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name(HIW "��������" NOR, ({ "bingpo yinzhen", "zhen", "needle", "yinzhen" }));
        //bingbo->bingpo ע������ caiji@SJ 
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("damage", 3);
                set("poison", "bing_poison");
                set("embed", 1);
                set("unit", "ö");
                set("throw_msg", HIW"$N����һ�ӣ�һö������������׷ɳ�ֱ��$n�����ȥ��\n"NOR);
                set("long", "һö������ϸ�룬�����ο̻��ƣ�����ü��Ǿ��¡�\n");
                set("unique", 20);
                set("value", 20000);
        }
        setup();
}


