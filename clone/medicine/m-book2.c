inherit ITEM;

void create()
{
        set_name("Ԣ���", ({ "yuyi cao", "medicine book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ĩ������д�Ľ�������������顣\n");
                set("value", 5000);
                set("material", "paper");
                set("exp_required", 6000);
                set("jing_cost", 25);
                set("difficulty", 23);
                set("min_skill", 30);
                set("max_skill", 41);
        }
}
#include "m-book.h";
                