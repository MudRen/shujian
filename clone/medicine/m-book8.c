#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"���ݾ���ע"NOR, ({ "bencao jizhu", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("treasure",1);
                set("unique", 1);
                set("long", "����һ���պ뾰�������йر���������顣\n");
                set("value", 200000);
                set("material", "paper");
                set("exp_required", 150000);
                set("jing_cost", 60);
                set("difficulty", 30);
                set("min_skill", 100);
                set("max_skill", 121);
        }
}
#include "m-book.h";
               