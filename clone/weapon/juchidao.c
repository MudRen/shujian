// juchidao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( "��ݵ�", ({  "juchi dao" , "blade" , "dao"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѳ�����������������һ������ľ�ݣ��������ͨ�ֵ�����������\n");
                set("value", 1000);
                set("material", "steel");
              }
        init_blade(40);
        setup();
}
