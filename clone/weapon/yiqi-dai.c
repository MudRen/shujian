#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"Ǭ��һ����"NOR, ({"yiqi dai", "dai" }) );
        set_weight(1000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("unique", 1);
        set("long", "����һ���������Ĵ��ӡ��ǳ�Ǹ�����쳣������ȥ\n"
"������Ȼ�����Ǵֲ����ƣ���˺��ȥȴ�����ޱȡ�\n");
        set("value", 10000);
        set("material","silk");
        set("treasure",1);
        set("no_unique", 1);
        }        
        setup();
}
