// hostage_2.c
// Created by Numa 19991101

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        object ob;
        
        if (duration < 1 ) {
                if((int)me->query_temp("hostage/passed_l")
                && objectp(ob = present("ling huchong",me))) {
                        tell_room(environment(me),"����岻�ͷ��ض�"+me->name()+"��ߴ������ô����������Ҫô��ﹰ�����ˣ�\n");
                        tell_room(environment(me),"�����첽�뿪�ˡ�\n");
                        me->delete_temp("hostage/passed_l");
                        if (me->query_temp("hostage/failed_l"))
                                me->add_temp("hostage/failed_l",1);
                        else
                        	me->set_temp("hostage/failed_l",1);
                        ob->move("/d/huashan/siguoya"); 
                }
                me->delete_temp("hostage");
                me->clear_condition("hostage11");
                return 0;
        }
        if( me->query_temp("hostage/killed") < (random(me->query_kar()/10 + 1) + 2)
          && random(me->query_kar()) < 10
          && (interactive(me))
          && !me->is_busy()
          && !environment(me)->query("no_fight")
//          && me->query_temp("hostage/passed_l")
          && !present("mojiao shashou",environment(me))
          && duration%4 == 1) {
               tell_object(me, HIY "�������Щ����ƺ����˸������ˣ�\n" NOR);
		me->add_busy(2+random(4));
               call_out("zuji",1, me);
        }
        me->apply_condition("hostage11", duration - 1);
        me->add_busy(1+random(2));
        return CND_CONTINUE;
}

void zuji(object me)
{
        object npc; 
        
        tell_object(me, RED "��⣡ħ��ɱ��׷�˹������ƺ���Ҫ��������!\n" NOR);
        npc = new("/d/hmy/npc/killer2");
        npc->set_temp("target",me->query("id"));
        npc->move(environment(me));
        return;
}

