#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(WHT"ǧ����"NOR, ({ "qianjin yifang", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("unique", 1);
                set("treasure",1);
                set("long", "����һ���ɺ�����˼��������ҽѧ���䣬���롶����ǧ��Ҫ�����ϳ�����ǧ�𷽡���\n");
                set("value", 1000000);
                set("material", "paper");
                set("exp_required", 500000);
                set("jing_cost", 75);
                set("difficulty", 36);
                set("min_skill", 160);
                set("max_skill", 181);
        }
}
#include "m-book.h";
               