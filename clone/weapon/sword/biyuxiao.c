///u/jpei/thd/obj/biyuxiao.c ������
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(GRN"������"NOR,({"biyu xiao","xiao"}));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit","֧");
                set("value",2000);
                set("material","gem");
                set("unique", 1);
                set("treasure", 1);       
                set("rigidity", 6);
                set("weapon_prop/parry", 3);
                set("wield_neili", 500);
                set("wield_maxneili", 1000);
                set("long","����һ֧ͨ�徧Ө���ü�Ϊ������"GRN"����"NOR"��������������ʮ�־�Զ��\n");
                set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
                set("unwield_msg","$Nһ����Х����$n������䡣\n");
        }
        init_sword(75);
        setup();
}
int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 150){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

