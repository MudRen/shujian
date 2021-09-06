#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"�ƽ�˫��"NOR,({ "huangjin nao", "nao" }) );
        set_weight(29000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 1000000);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 2);
                set("weapon_prop/dodge", -8);
                set("weapon_prop/parry", 8);        
                set("material", "gold");
                set("wield_neili", 300);
                set("wield_maxneili", 1100);
                set("wield_str", 25);
                set("wield_msg", HIY"ֻ������������һ������ħն����ֻ����Ի�������������⣬������أ�\n"NOR);
                set("long", HIY"\n����һ���ô������Ľ���ֱ��������������Ϊ��ħ��ն�����룬
������Է�(fen)��������ֱ�������ŷ�ħ���Ժ�ն��������\n"NOR);
                set("unwield_msg", HIY "�ƽ�˫�����շɳ����϶�Ϊһ���ַɻ���$N�����С�\n" NOR);               
        }
        init_blade(160);
        setup();
}

void init()
{
	if (environment()==this_player())
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
     new("/clone/weapon/jinnao1")->move(me, 1);
     new("/clone/weapon/jinnao2")->move(me, 1);  
     destruct(obj); 
     return 1;

}

