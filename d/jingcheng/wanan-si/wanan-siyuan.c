#include <ansi.h>
inherit ROOM;

int do_leave(string arg);
void create()
{
        set("short", "������Ժ");
        set("long","���������µ���Ժ����ǰ��һ������������䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("no_save", 1);
        set("no_quit", 1);
        set("exits", ([
                "enter" : __DIR__"baota-1",
        ]));
        setup();
}
void init()
{
        object me = this_player();
        add_action("do_leave", "leave");
        if (!me->query_temp("was_job") && userp(me) && !wizardp(me))
        {
                message_vision("ʲô�˾�Ȼ�ô����£���ż���\n");
                message_vision("һ���Ҽ�������$N������������Ķ��ӡ�\n", me);
                me->move("/d/nanyang/kedian1");
                me->unconcious();
        }
}

int do_leave(string arg)
{
        object me = this_player();
        int num = me->query_temp("was_job/floor") - me->query_temp("was_job/num");
        
        if (!me->query_temp("was_job/asked"))
                return 0;
        if (!me->query_temp("was_job/floor"))
                return notify_fail("��û���˾����ߣ��������ӣ�\n");
//        me->apply_condition("job_busy", 5);
//        me->apply_condition("was_job", 90);
        if (num < 1)
                num = 1;
  //      TASK_D->job_reward(me, "was_job", num, 1);
  //      me->delete_temp("was_job");
        me->move("/d/nanyang/kedian1");
        return 1;
}

void check_death(object ob)
{
        ob->delete_temp("was_job");
}
