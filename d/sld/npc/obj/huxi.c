// huxi.c

#include <ansi.h>
#include <combat.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("��ϥ", ({"hu xi", "huxi"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ���������������е�������ϥ��\n");
                set("material", "steel");
                set("armor_prop/armor", 30);        
        }
        setup();
}

void init()
{
//          add_action("do_zhuiming","zhuiming");
}

int do_zhuiming()
{
        object me , target;
        int i,times ,hits,str;

        me = this_player();
        if ( !objectp(me->query_temp("zhuiming/target"))) return 0;

        target = me->query_temp("zhuiming/target");

        times = time()-(int)me->query_temp("zhuiming/time");

        if( times < 10) return notify_fail("�㻹�ھۼ������ء�\n");

        if( times >= 10 && me->is_fighting(target) && times < 60){
                if( times > 60) times = 60;
                me->delete_temp("zhuiming/time");
                me->delete_temp("zhuiming/target");
                hits = 2 + times/10;
                str = 40 + hits * 4;

                me->add_temp("apply/strength",str);
                me->add_temp("apply/attack", me->query_skill("leg")/6);

                if (wizardp(me) ) tell_object(me,sprintf("str:%d\n",str));
        
                target->start_busy(2);
                message_vision(HIY+"\n\n$N��Ȼ���һ�����Ծۼ������������Լ��Ľ�������Ȼ�����������������\n"+
                                   "������Ӱ��׷����ɨ��$n����ʱ��$n��û�����಻��������׷�����У�\n",me,target);
                for( i=1; i<=hits; i++){
                   message_vision(HIY+"\n����׷����"+CHINESE_D->chinese_number(i)+"�ȣ�"NOR,me);
                   COMBAT_D->do_attack(me, target, 0, TYPE_QUICK);
                }
                me->add_temp("apply/strength", -str);
                me->add_temp("apply/attack", -(me->query_skill("leg")/6) );
        }
        else {
                return notify_fail("ʹ�á�����׷���ȡ���Ҫ���Ⱦ�����\n");
        }
        return 1;       
}
