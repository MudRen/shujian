inherit ITEM;
#include "/inherit/item/embed.h"
void create()
{
        set_name(HIY "����׶" NOR, ({ "jinshe zhui", "zhui" }));

        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("damage", 3);
                set("embed", 1);
                set("unit", "ö");
             //   set("throw_msg", HIW"$N����һ�ӣ�һö������������׷ɳ�ֱ��$n�����ȥ��\n"NOR);
                set("long", "����һö���������������εİ�����\n");
                set("unique", 20);
                set("value", 20000);
        }
        setup();
}



