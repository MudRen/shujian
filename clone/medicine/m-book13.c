#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"������"NOR, ({ "longshu lun", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("unique", 1);
                set("long", "����һ���Ŵ�ҽѧ���䣬���߲��ꡣ\n");
                set("value", 1000000);
                set("treasure",1);
                set("material", "paper");
                set("exp_required", 800000);
                set("jing_cost", 100);
                set("difficulty", 40);
                set("min_skill", 190);
                set("max_skill", 200);
        }
}
#include "m-book.h";
                