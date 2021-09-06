#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�ƽ�˫��"NOR,({ "huangjin nao", "nao" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 1000);
                set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 4);
                set("weapon_prop/parry", 4);        
                set("material", "gold");
                set("wield_neili", 900);
                set("wield_maxneili", 1400);
                set("wield_str", 25);
                set("wield_msg", HIY"ֻ������������һ������ħն����ֻ����Ի�������������⣬������أ�\n"NOR);
                set("long", HIY"\n����һ���ô������Ľ���ֱ��������������Ϊ��ħ��ն�����룬\n"+
                               "������Է�(fen)��������ֱ�������ŷ�ħ���Ժ�ն��������\n"NOR);
                set("unwield_msg", HIY "�ƽ�˫�����շɳ����϶�Ϊһ���ַɻ���$N�����С�\n" NOR);               
        }
        init_blade(80);
        setup();
}

void init()
{
    add_action("do_sub",({"fen", "��"}));
}

int do_sub()
{
     object me, obj;
     me = this_player();
     obj = this_object();
     if((int)me->query("neili") < 500)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ����ƽ�˫��\n");
     if((int)me->query_str() < 28)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ����ƽ�˫��\n");

     message_vision(HIY"\nֻ������һ�����죬$N���ƽ�˫�����������������ڿ���һ��Ϊ������Ϊ��������ַɻ���$N�����У�\n"NOR, me);
     me->add("neili", -300);
     new(BINGQI_D("blade/jinnao1"))->move(me, 1);
     new(BINGQI_D("blade/jinnao2"))->move(me, 1);  
     destruct(obj); 
     return 1;
}
