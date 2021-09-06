#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"��ħ����"NOR,({ "fumo nao", "nao","fumo" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_neili", 100);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"ֻ������ৡ���һ������ħ����ɳ�$N���У�����������⣬�������죡\n"NOR);
                set("long", HIY"\n�����ô�������һ��������Ұ븱��ֱ���������������������ħ���ԡ�
����ҵ���븱��Ӧ�ÿ��Խ����������(��)������\n"NOR);               
                set("unwield_msg", HIY "��ħ�������շɳ����ַɻ���$N�����С�\n"NOR);               
        }
        init_blade(80);
        setup();
}

void init()
{
	if (environment()==this_player()) {
		add_action("do_add", "��");
		add_action("do_add", "he");
	}
}

int do_add()
{
     object me,ob, obj, nao;
     me = this_player();
     ob = this_object();
     obj = present("zhanyao nao", me);
     if(!objectp(obj))
           return notify_fail("������ֻ��һֻ��ħ�������ҵ���һֻ��˵�ɡ�\n");
     if((int)me->query("neili") < 500)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫��ϲ���\n");
     if((int)me->query_str() < 28)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷���˫��ϲ���\n");
     me->add("neili", -300);
     message_vision(HIY"\nֻ������һ�����죬��ֻ�������շɳ���Ȼ��϶�Ϊһ���ַɻ���$N�����С�\n"NOR, me);
     destruct(obj);   
     nao = new("/clone/weapon/jinnao")->move(me, 1);     
     destruct(ob);
     return 1;
}
