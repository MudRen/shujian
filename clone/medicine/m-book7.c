#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(GRN"���ݸ�Ŀ"NOR, ({ "bencao gangmu", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("treasure",1);
                set("unique", 1);
                set("long", "����һ��������ʱ���������йر���������顣������ҩ��֮��ɡ�\n");
                set("value", 300000);
                set("material", "paper");
                set("exp_required", 100000);
                set("jing_cost", 50);
                set("difficulty", 29);
                set("min_skill", 80);
                set("max_skill", 101);
        }
}
#include "m-book.h";
               
