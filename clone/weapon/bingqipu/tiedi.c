// tiedi.c ����

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����",({"tie di","di"}));
 set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "֧");
                set("value", 600);
                set("material", "steel");
                set("long","����һ֧���ӣ�����ʮ�־�ϸ�������������ź�⣬�ƺ��Ǿ�����������������\n");
                set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
                set("rigidity", 3);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 22);   
                set("weapon_prop/parry", 2);
                set("unique", 1);
                set("unwield_msg","$Nһ����Х����$n������䡣\n");
        }
        init_sword(48);
        setup();
}
