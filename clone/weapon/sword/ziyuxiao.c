// ziyuxiao.c ������
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(MAG"������"NOR,({"ziyu xiao","xiao"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","֧");
                set("value",6000);
                set("material","gem");
                set("unique", 3);
                set("treasure", 1);       
                set("rigidity", 3);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("weapon_prop/parry", 2);
                set("long","����һ֧��Ө��͸���ú�����"MAG"����"NOR"�����������ʮ�����\n");
                set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
                set("unwield_msg","$Nһ����Х����$n������䡣\n");
        }
        init_sword(55);
        setup();
}
int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 100){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

