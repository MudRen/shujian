// Room: /d/city/dongxiangfang.c

#define CAR_ROOM "/d/city/lv-che"

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"���᷿"NOR);
	set("long", @LONG
��������Ժ�Ķ��᷿�������������Ժ���ﰲ����һЩ, ��������һλ��
��, �������˵ú�������
LONG
	);

	set("exits", ([
                "west" : __DIR__"lichunyuan",
	]));

        set("objects", ([
                __DIR__"npc/mao" : 1,
        ]));

	set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

void init()
{
//      object me = this_player();

//      if (!me->query_temp("mao18/passed1")) return;
        add_action("do_no",({"no"}));
        add_action("do_yes",({"yes"}));
}

int do_yes()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed1"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("éʮ�˶������ˣ���\n");
        me->delete_temp("mao18/passed1");
        me->set_temp("mao18/passed2",1);
        tell_object(me,HIR"
    ������˵��������ô��ȥ���������и�ͬ������ͬ������

    ���˹�����Ц��˵�����������仰˵�úá������ڽ���������˵���˼�ǧ�飬�и���

��ļһ���ö��ˣ�����ͬ������ȴ�����������������߰գ���\n"NOR);
        call_out("do_go", 1, me, ob);
        return 1;
}

int do_no()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed1"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("éʮ�˶������ˣ���\n");
        tell_object(me,HIB"
    ��ս���Ĵ������С�˼��С��������л���Щ�£����ү���ͷŹ�С���Ұɣ���

    ���˹�����Ц��˵������������С�һ�Ҳûʲô�������Ͽ���ɣ���\n"NOR);
        me->delete_temp("mao18/passed1");
        return 1;
}

int do_go(object me, object ob)
{
	if (!me->query_temp("mao18/passed2"))
		return 1;
	tell_object(me,HIR"
    ������߳�����Ժ����Զ��ӭ�����һ��¿�������˺ȵ������ͳ�������������ʤɽ����
    
    �Ǹϳ��ĵ���ͣ��������̤�壬����������ϳ���¿������ǰ������\n"NOR);
	ob->move(CAR_ROOM);
	me->move(CAR_ROOM);
	call_out("do_going", 5, me, ob);
        return 1;
}

int do_going(object me, object ob)
{
	if (!me->query_temp("mao18/passed2"))
		return 1;
	tell_object(me,CYN"
    ֻ��éʮ�˴ӻ�������һ��ʮ���صĻƽ𣬽����㣬˵������С���ѣ��⶧���Ӹ��㡣��
    
    ������⶧���ӣ��������˿���ĭ��������ԥ�����������ջ��ǲ���("RED"yes"CYN"|"RED"no"CYN")��\n"NOR);
	me->delete_temp("mao18/passed2");
    me->set_temp("mao18/passed3",1);
	return 1;
}    	
