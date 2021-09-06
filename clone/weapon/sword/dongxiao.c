#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"����"NOR,({"dongxiao",  "xiao"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "֧");
                set("value", 9000);
                set("rigidity", 9);
                set("sharpness", 5);
                set("material", "starsteel");
                set("treasure",1);
                set("unique",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("weapon_prop/parry", 2);
                set("wield_msg",HIY"$N��������һ�У�һ֧$n" + HIY"�ѳ�����$N���С�\n"NOR);
                set("unwield_msg",HIY"$Nһ����Х����$n" + HIY"������䡣\n"NOR);
        }
        init_sword(45);
        setup();
}
int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 200){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

