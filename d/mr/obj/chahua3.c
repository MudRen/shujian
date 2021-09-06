// /u/beyond/obj/chahua3.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIW"������"NOR,({ "flower", "hua" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "plant");
                set("long", "����һ�������š�\n");
                set("wear_msg", "");
                set("no_get",1);
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}

void init()
{
        add_action("do_jiao", "jiaoshui");
        add_action("do_chu",  "chucao");
}

int wear()
{
        object me = environment();
        int ret;

        message_vision("$N�ó�һ��" + this_object()->query("name") + "��������ǰ��", me);
        if (ret=::wear()) {
                if (me->query("gender") == "����")
                        message_vision("��һ�����������ɣ�\n", me);
                else if (me->query("gender") == "Ů��")
                        message_vision("��һ�������μ��ޣ�\n", me);
                else
                        message_vision("��һ���������ĵļһ\n", me);
        }
        return ret;
}

int do_jiao()
{
        object me = this_player();
        object weapon;
        object haoke;
        object piao;
        
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->query_temp("mark/ok")) return notify_fail("���Ѿ������ˣ��������������ѻ�����ѽ��\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר�ĸɻ\n");
        if (me->query_temp("yanpopo")!= 2) return notify_fail("�㻹û��ȥҪ���ߣ���ô�ɻ�ѽ��\n");
        
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("id")!= "piao")
                return notify_fail("������ʲô��������������\n");
        if((int)me->query("combat_exp")  > 30000 )
        {
                if(!me->query_temp("killke"))
                {
                        if((int)me->query_temp("mark/��") > (5 + random(5)) )
                        {
                            haoke = new("/d/mr/npc/haoke");
                            if(!haoke)
                                return notify_fail("ϵͳ������֪ͨ��ʦ��\n");
                            haoke->set_temp("target",me->query("id"));
                            haoke->move(environment(me));
                            
                            tell_object(me,"���������Ľ�������Ȼһ���������ʹ��˽�����һ���������ˮư����ݺݵ��ʵ���Ľ�ݼҵ����أ�����������\n");
                            piao = present("piao", me);
                            piao->move(haoke);
                            haoke->kill_ob(me);
                            me->kill_ob(haoke);
                            me->set_temp("killke",1);                   
                        }
                }
        }
        if((int)me->query_temp("mark/��") > (10 + random(10)) )
        {
	    message_vision(RED"$N����ˮ�Ѿ����Ĳ���ˣ����Ի�ȥ�����ˡ�\n"NOR, me);
            me->delete_temp("mark/��");
            me->delete_temp("yanpopo");     
            me->set_temp("mark/ok",1);
            return 1;
        }
        else
        {
            me->start_busy(1);
            me->receive_damage("jingli",random(5)+2);
            me->receive_damage("qi",random(5)+2);       
            me->add_temp("mark/��",1);
            message_vision("$N��ˮ����Ҩ��ưˮ��С������İ�ˮ���ڡ������š��ϡ�\n", me);
        }
        
        return 1;
}
