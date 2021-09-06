// Room: /d/city/winmo.c

#include <ansi.h>
inherit ROOM;

#define WU "/d/city/npc/wudapeng"
#define WANG "/d/city/npc/wangtan"
#define SHI "/d/city/npc/shisong"

void create()
{
        set("short", "��ʤɽ");
        set("long", @LONG
��ʤɽ�����ݳ�������ʮ��Ĵ����磬ɽֻ���߰��ɸߣ������Ǹ�С��
����������䣬���������ڴ˴����ƽ�������ɽ������ʤ����
LONG    );
        set("exits", ([
                "southeast" : __DIR__"wroad1",
                "west" : __DIR__"miao",
        ]));
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/wudapeng" : 1,
                __DIR__"npc/wangtan" : 1,
	]));
        set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",50);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}

void init()
{
	object me = this_player();
	
	if (!me->query_temp("mao18/passed4")) return;
	
	remove_call_out("do_start");
	call_out("do_start", 2, me);
}

int do_start(object me)
{
	object here = this_object();
	object ob, ob1, ob2;
	
	if (!me) return 1;
	if (!(ob = present("mao shiba",here))) {
		me->delete_temp("mao18");
		return 1;
	}
	if (!(ob1 = present("wu dapeng",here))) {
		ob1 = new(WU);
		ob1->move(here);
	}
    if (!(ob2 = present("wang tan",here))) {
		ob1 = new(WANG);
		ob1->move(here);
	}
	tell_object(me,HIY"
    ���Ǹ�������ʤɽ��ȴ��һ��ͺ�����Ӻ�һ�����������ѵȴ���ʱ�ˣ�ԭ�������˱�

�ǡ�Ħ���֡�������͡����ʿ�ɽ����̶��\n"NOR);
    	call_out("do_happen",2, me, ob);
    	return 1;
}

int do_happen(object me, object ob)
{
	object ob1;
	
	ob1 = new(SHI);
	ob1->move(this_object());
	tell_object(me,CYN"
    éʮ�˸���ȥ�����˴��˸����ѣ�ȴ������һ���������˹���������˵������

é���ѣ��������ݳ������������İ��ӣ��ú�һ������һ�˵����ԹԵĸ������߰գ���

    �������������̸������մ��������Ǿ���������һ��������������һ�ģ�˵����

������'������'ʷ�ɣ��������ٱ����������ػᷴ������\n"NOR);
	call_out("do_fight",2, me, ob, ob1);
}

int do_fight(object me, object ob, object ob1)
{
	tell_object(me,HIG"
    éʮ�����������иֵ�����ǰȥ����ʷ�ɴ���������\n"NOR);
    	ob->fight_ob(ob1);
    	ob1->fight_ob(ob);
//    	call_out("do_end",20, me, ob, ob1);
    	return 1;
}
/*
void do_end(object me, object ob, object ob1)
{
	if (!me)
		return;
	if (!ob || !ob1)
		call_out("do_fail",1, me);
	if (!ob1->query_temp("be_signed"))
		call_out("do_fail",1, me);
	
*/	
