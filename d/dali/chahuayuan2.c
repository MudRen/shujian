// Room: /dali/chahuayuan2.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"�軨԰"NOR);
      	set("long", @LONG
������һ��Сɽ���ϣ����ﵽ������ʢ�����ʻ������е��ۻ������ˣ���
�������⻨԰�У������泩��ࡣ 
LONG
       );
        set("exits", ([ 
              "northup" : __DIR__"chahuayuan3",
              "southdown" : __DIR__"chahuayuan",
	]));
        set("outdoors","����");
        set("objects", ([
             __DIR__"obj/chahua2" : 1,
        ]));
        set("coor/x",-280);
  set("coor/y",-430);
   set("coor/z",-10);
   setup(); 
}

int valid_leave(object me, string dir)
{
/*      object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if(dir == "southdown"){
        while (i--)
        if( ob[i]->id("flower") && ob[i] > 2)
          return notify_fail("�����ô�໨��ȥ����\n");               
          }*/
	if ( dir == "southdown" )
        me->delete_temp("flower_paid");
	return ::valid_leave(me, dir);
}
