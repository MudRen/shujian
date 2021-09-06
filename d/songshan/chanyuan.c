// Room: /d/songshan/chanyuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
��������ɽ������֮������Ժ��Ҳ������ɽ�ɵľݵ㡣��ǰ������
Ժ������Ժ��ȴ���йŰ�ɭɭ�����ϲ��޷��񣬴����Ҳ���󣬿ɱ�֮
�����µĴ��۱���ȴ���в��磬�������ɽ�ǧ�ˡ�������ɽ�ɵ�������
��Ѳ�ߡ�
LONG);
        set("exits", ([ 
             "north" : __DIR__"shidao1",
            "south" : __DIR__"damen",
//              "east" : __DIR__"csshi",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/ding" : 1,
            CLASS_D("songshan") + "/fei" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("coor/x",40);
  set("coor/y",280);
   set("coor/z",110);
   setup();
        "/clone/board/songshan_b"->foo();
}

int valid_leave(object me, string dir)
{
       object ob;       
       mapping fam;

       fam = me->query("family");
       if(me->query_temp("songshan_job"))
               return ::valid_leave(me, dir);
               
        if( fam && fam["family_name"] =="��ɽ��")
                return ::valid_leave(me, dir);
       else if( me->query("shen") > 0
           && objectp(ob = present("ding mian", environment(me)))
           && living(ob) 
           && dir != "south") {
                        message_vision(CYN"\n$N����һ����ס$n"CYN"��ȥ·����ɽ����������ҹ�ĵط��𣿣�\n"NOR,ob, me);
                        return notify_fail(" ");
                 }
       return ::valid_leave(me, dir);
}
