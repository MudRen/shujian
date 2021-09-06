// ���ս�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIR "���ս�" NOR, ({ "guanri jian", "guanri", "jian" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("long", HIR "���ս���˵�ڹ��շ�ʮ�����ɣ���â�������֮���գ�����ħ���֡�\n" NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 3);
                set("sharpness", 3);
                set("unique", 1);
                set("weapon_prop/parry", 2);
                set("wield_neili", 500);
                set("wield_maxneili", 900);
                set("wield_str", 23);
                set("wield_msg", HIR "$N���ְν�һת��һ�ֺ������ӽ��������𣬽�����˸ҫ�ۡ�\n" NOR);
                set("unwield_msg", HIR "ֻ��$N��ָ΢��������û�ڽ���֮�С�\n" NOR);
        }
        init_sword(45);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

if(me->query("family/family_name")!="��ɽ��" ) return 0;              
if( victim->query_condition("no_fight") &&  victim->query_condition("no_perform")) return 0;
if(random(10)>5) return 0;

        switch (random(3))
        {
        case 0:
                victim->start_busy(me->query_skill("sword",1) / 200 + 1);
                 n = me->query_skill("sword");
                 victim->add_condition("no_fight", 1);

                return HBYEL HIY"$N" HBYEL HIY"��ǰһ�������е�" NOR + HIR"���ս�" NOR
                       + HBYEL HIY"����һ������������$n" HBYEL HIY"��ȥ����������֮������ͬ���ɺ��գ����ɱ��ӡ�\n"
                       "$n" HBYEL HIY"���һ������֪��εֵ���ֻ���������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sword",1);
                victim->receive_damage("qi", n*2, me);
                victim->receive_wound("qi", n, me);
                victim->receive_damage("neili", n, me);
                victim->add_busy(1+random(2));
                victim->add_condition("no_perform", 1+random(2));

                
                return random(2) ? HBYEL HIY"$N" HIY "һ������������"HIR"���ս�"HBYEL HIY"�����һ"
                                   "��Ϭ���ޱȵĽ����������ǻ𣬳�$n" HBYEL HIY"�����ȥ��\n" NOR:
                                   HBYEL HIY"$N" HBYEL HIY"ͻȻ�����ȵ��������У������к���"
                                   "����"HIR"���ս�"HBYEL HIY"�û������������⣬�����֮������\n" HIY "ϼ�������$n"
                                   HBYEL HIY"��ʱ����ͷ��Ŀѣ�ۻ����ң�\n" NOR;
        case 2:
                n = me->query_skill("sword",1);
                victim->receive_damage("qi", n*2, me);
                victim->receive_wound("qi", n, me);
                victim->receive_damage("neili", n, me);
                victim->add_busy(1+random(2));
                victim->add_condition("no_perform", 1+random(2));

                
                return random(2) ? HBYEL HIY"$N" HIY "һ������������"HIR"���ս�"HBYEL HIY"�����һ"
                                   "��Ϭ���ޱȵĽ����������ǻ𣬳�$n" HBYEL HIY"�����ȥ��\n" NOR:
                                   HBYEL HIY"$N" HBYEL HIY"ͻȻ�����ȵ��������У������к���"
                                   "����"HIR"���ս�"HBYEL HIY"�û������������⣬�����֮������" HIY "ϼ�������$n"
                                   HBYEL HIY"��ʱ�����ۻ����ң�\n" NOR;


        }

       
}


 
