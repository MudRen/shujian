// /d/xiangyang/cross2.c �϶���
// rebuild by Lklv 2001.9.24

#include <ansi.h>
//#include <mudlib.h>
inherit ROOM;

void reset_job();
void job_check(object ob);

// #include "xyjob.h"

void create()
{
        set("short", "�϶��ֽ�");
        set("long", @LONG
�����Ǿ���������������ͨ�����źͶ��ŵĶ���·�ڣ���ʱ���ж������
��ʿ��������ȥ�����ϳ��ǿ���ȥ���ϣ��򶫳��ǿ���ȥ���ա����ա����淽
����һ���ߴ����¥��
LONG
        );
        set("outdoors", "����");
        set("xyjob",1);
        set("exits", ([
                "east" : __DIR__"djie1",
                "north" : __DIR__"dpailou",
		"west" : __DIR__"njie1",
        ]));
        set("objects",([
		__DIR__"npc/wuxiuwen" : 1,
        ]));
        set("incity",1);
	setup();
}
/*
void init()
{
    object me = this_player();
        if(wizardp(me) && ( me->query("id")=="lsxk" ||  me->query("id")=="server" || me->query("id")=="spiderii")) {
            if(me->query("xyjob_force")){
                remove_call_out("reset_job");
                call_out("reset_job",300);
                set("pending",1);
                job_check(me);
                me->delete("xyjob_force");
                return;
            }
    }
        if (!query("pending"))
        {
                set("pending",1);
                job_check(me);
                return;
        }
}

void reset_job()
{
        delete("pending");
}

void job_check(object ob) //�ж������������
{
    if(query("xyjobing")) return;

    if (INTERJOB_D->job_check(ob))
	{
//            if (!random(2))
//                    call_out("gmdjob_1", 10);
//            else
		        call_out("xyjob_1", 10);
	}
        else
                call_out("reset_job", 300);
}

*/
