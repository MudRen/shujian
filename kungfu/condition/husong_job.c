// husong_job.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        object ob,ob1,ob2,ob_mubiao;
        if (duration < 1) return 0;
        if ( (me->query_temp("killed")<5) && (random(10)>4) ) {
        if (!(ob_mubiao = present("nv juan", environment(me)))){
        if (userp(me) && me->query_temp("mubiao",1)
           && !environment(me)->query("no_fight")){

                ob = new("/d/city/hubiao/shashou.c");
                ob->move(environment(me));
                me->add_temp("killed",1);
        }}}
        if ((duration < 5) && me->query_temp("mubiao")) {
                tell_object(me, HIY "����ô��ʱ�仹û������������ھֵ����Ӷ���������ˣ�\n" NOR);
                me->delete_temp("pass");
                me->delete_temp("mubiao");
                if (objectp(ob1 = present("biao qi", me)))
                        destruct(ob1);
		ob2 = me->query_temp("husongjob");
                me->delete_temp("husongjob");
                me->delete_temp("killed");
                if (!ob2) {} else destruct(ob2);
//              me->apply_condition("job_busy",5);
        }
        me->apply_condition("husong_job", duration - 1);
        return 1;
}
