// tieluohan.c ���޺�

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIY"���޺�"NOR,({"tie luohan","tieluohan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "steel");
                set("long", "����һ���������ɵ�˫�����޺����������أ����Ǿͻ�����һ���޺�ȭ!\n");
                set("wield_msg", "$N˫��ץ��һ��$n��Ц�����ذ����š�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_hammer(5);
        setup();
}                                                   
