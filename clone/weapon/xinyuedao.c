// xinyuedao.c 
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( HIW"ѩɽ���µ�"NOR , ({ "xinyue dao", "xueshan dao","dao","blade"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"��ѵ������ұ���������ɰ����Σ���״�Ź֣���������Ϊ�ټ���\n"NOR);
                set("value", 1000);
                set("material", "steel");
        }
        init_blade(30);
        setup();
}
