// ɽ�� shanbi.c
 
#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create() 
{ 
        set("short", "ɽ��");
        set("long", @LONG
�����̺���ϣ���ɽ��Ұ�����ʻ������������Ѽ���ת�˼����䣬ȴ��ӭ
��һ��ɽ�ڣ�·;�Ѿ����Ա���һ�Ż���(huacong)��
LONG
        );

        set("item_desc", ([
                "huacong" : "����һ��Ư���Ļ��ԣ���ֻ�����ӻ��������˽�ȥ��\n",
        ]));

        set("outdoors", "������");

        set("exits", ([ 
            "south" : "/d/city/wroad3",
        ]));

        set("coor/x",80);
  set("coor/y",-170);
   set("coor/z",0);
   setup();
}

void init()
{
        add_action("do_bo", "bo");
}

int do_bo(string arg)
{
        object room, me;
        mapping fam;

        me = this_player();
        fam = me->query("family");

        if(!living(me) ) return 0;

        if ( me->is_busy() || me->is_fighting())
              return notify_fail("����æ���ģ�\n");

        if( !arg || arg != "huacong" ) return 0;

        if( arg == "huacong" ){
            if ((!fam || fam["family_name"] != "����") && (!me->query_temp("hdq")))
                return notify_fail("�㲦�˲����ԣ���û��ʲô���֣�������Щ��Ȼ��\n");
            message_vision(HIC"$N���˲���Χ�Ļ��ԣ�ͻȻ�����ұ�"HIY"(Right)"HIC"������һ��С·��\n"NOR, me);
            if(!(room = find_object(__DIR__"shanbi")))
              room = load_object(__DIR__"shanbi");
              set("exits/right", __DIR__"huacong1");
              call_out("delete_exit", 5, room);
              return 1; 
        }
}

void delete_exit(object room)
{       
        message("vision",HIW"һ��΢�紵�������Զ�����������ס��С·��\n"NOR, room);
        delete("exits/right");
}

int valid_leave(object me, string dir)
{
	if (dir == "right" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
