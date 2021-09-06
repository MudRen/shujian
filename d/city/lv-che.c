// Room: Lv-Che.c
// Creator : Numa@Sj 00-6-3

#include <ansi.h>
inherit ROOM;

#define OUT "/d/city/winmo"
#define FROOM "/d/city/winmo"

void create()
{
        set("short", HIC"������"NOR);
        set("long", @LONG
����¿���ĳ����ڣ�����ɸɾ��������᲻ס�����µ��������ǳ��ߵļ�
��Щ��
LONG
	);
	set("no_fight",1);
        setup();
}

void init()
{
        object me = this_player();
        object ob;

        if (!(ob = present("mao shiba",environment(me)))) {
                tell_object(me,HIR"
    ͻȻ������һ��������éʮ����ʱ������ȥ����Ҳ�漴���˳�ȥ��\n"NOR);
                me->move(OUT);
                tell_room(environment(me),"ֻ��"+me->name(1)+"��¿�������˳�����\n",({me}));
                tell_object(me,HIB"
    ���ǣ���ȴ��ôҲ�Ҳ���éʮ�ˣ�ֻ��ʧ�����뿪�ˣ�\n"NOR);
    		me->delete_temp("mao18");
    		return;
    	}
        call_out("do_arrive", 20, me, ob);
//      if (!me->query_temp("mao18/passed1")) return;
        add_action("do_no",({"no"}));
        add_action("do_yes",({"yes"}));
}

int do_arrive(object me, object ob)
{
	if (!me) return 1;
	if (!me->query_temp("mao18/passed4")) {
                tell_object(me,HIR"
    ͻȻ������һ��������éʮ����ʱ������ȥ����Ҳ�漴���˳�ȥ��\n"NOR);
                me->move(OUT);
                tell_room(environment(me),"ֻ��"+me->name(1)+"��¿�������˳�����\n",({me}));
                tell_object(me,HIB"
    ���ǣ���ȴ��ôҲ�Ҳ���éʮ�ˣ�ֻ��ʧ�����뿪�ˣ�\n"NOR);
    		me->delete_temp("mao18");
            return 1;
    	}
    	tell_object(me,HIY"
    ���Ӳ�һ��͵��˵�ʤɽ�����éʮ�����³�����ȴ����ɽֻ���߰��ɸߣ������Ǹ�

С��\n"NOR);
	me->move(FROOM);
	ob->move(FROOM);
	return 1;
}

int do_no()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed3"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("éʮ�˶������ˣ���\n");
        me->delete_temp("mao18/passed3");
        me->set_temp("mao18/passed4",1);
        tell_object(me,HIR"
    ���������������ֻ������������Ǯ�ơ�����Ԫ�����ң��������Ҳ������������ˣ�

�һ����԰�æ�����㡣��

    éʮ��һ���������Ц��˵�������ü����ü����е���˼������Ԫ�����뻳�С�\n"NOR);
        return 1;
}

int do_yes()
{
        object me = this_player();
        object ob;
        
        if (!me->query_temp("mao18/passed3"))
                return 0;
        if (!(ob = present("mao shiba",environment(me))))
                return notify_fail("éʮ�˶������ˣ���\n");
        tell_object(me,HIB"
    ����Ц�˼������������л��ү����С�˵Ļƽ�С�����ھ��ߣ���

    ���˹�����Ц��˵������������С�һ�Ҳûʲô�������Ͽ���ɣ���\n"NOR);
    	me->move(OUT);
        me->delete_temp("mao18/passed3");
        remove_call_out("do_arrive");
        ob->return_home();
        return 1;
}
