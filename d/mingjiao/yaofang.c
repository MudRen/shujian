// yafang.c ҩ��
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"ҩ��"NOR);
    set("long",@LONG
���������̵Ĳ�ҩ�ҡ������鵤��ҩӦ�о��У��и������ɸ����Ž�����
�����ģ���֮�Ž�����ͨҽ���������β�������Ϊ�������鵤Ʈ�㣬һ������
�����㾫��һչ��������һ��ͨ������õ����ȡ�
LONG);
    set("exits",([
           "west" :  __DIR__"wu1",
    ]));
	set("indoors", "����");
    set("objects", ([
        __DIR__"npc/xtong" : 1,
        __DIR__"npc/yaoshi" : 1,
    ]));
    set("coor/x",-280);
  set("coor/y",200);
   set("coor/z",120);
   set("coor/x",-280);
 set("coor/y",200);
   set("coor/z",120);
   setup();

}
void init()
{
       	object me = this_player();
        if(me->query_temp("mj/xunluo") && !me->query_temp("yaofang"))
           me->set_temp("yaofang",1);
}
