// da-shitou.c
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIY"��ʯͷ"NOR,({ "da shitou", "shitou","stone" }) );
         set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "stone");
                set("long", "����һ����ʯͷ��\n");
                set("wield_msg", "$N�ó�һ��$n���������������������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(10);
        setup();
}
