#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"����ǧ��Ҫ��"NOR, ({ "qianjin yaofang", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("unique", 1);
                set("treasure",1);
                set("long", "����һ���ɺ�����˼��������ҽѧ���䣬���롶ǧ�������ϳ�����ǧ�𷽡���\n");
                set("value", 300000);
                set("material", "paper");
                set("exp_required", 300000);
                set("jing_cost", 70);
                set("difficulty", 34);
                set("min_skill", 140);
                set("max_skill", 161);
        }
}
#include "m-book.h";
              