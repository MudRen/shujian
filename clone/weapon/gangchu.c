#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIW"����"NOR,({"gang chu","chu"}));
        set_weight(100000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","��");
                set("value",100);
                set("material","black_steel");
                set("long",HIW"����һ�����������Ľ�ħ�ƣ�ǧ������������������ĺ��⡣\n"NOR);
               set("unwield_msg","$Nһ����Х�������ƷŻر���\n");
        }
        init_staff(20);
}
