// shanpo1.c 
// By River 98.08.29
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"ɽ��"NOR);
        set("long",@long
�˴���ɽ·�Ե����ж��ͣ������Ӳݴ���������ȥΣ���ķ������ڽ�����
���Ź�Ĺ��ǰ��������ǰ��͵ȡ��Ĺ�ؼ������Թ�Ĺ���Ӽ�ǿ��Ѳ����һЩ��
Ĺ��������ɽ�¸���Ѳ�ߡ�
long);

        set("outdoors","��Ĺ");

        set("exits",([
          "southwest" : __DIR__"shanpo",                
        ]));

        setup();
}

void init()
{
        object ob, me, name1;
        me = this_player();
        name1 = me->query("id");
        if(/* ! (present("mengmian nuzi", environment(me))) && */
        (int)me->query_temp("gm/job")
         && !(int)me->query_temp("meet_nuzi")
         &&  me->query_condition("gm_job")){
		ob=new(__DIR__"npc/mmnz");
		ob->move(environment(me));
		me->set_temp("meet_nuzi", 1);
		ob->set_temp("mmnz", name1);
        }
}
