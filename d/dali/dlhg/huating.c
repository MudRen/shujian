inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǵ���ʹ���������ֻ��������һ����ң�д�š������ʯ���ĸ���
�֣��������š���î���ʡ��ĸ�С�֣���������������ֻ�������վ��һ�ˣ�
��������������ȥ�е���֮�����Ķ������鷿�����������ŷ���������һ��
�ţ��ƺ���ͨ���󹬵����ȡ�
LONG);

	set("exits", ([
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"zoulang2",
		"east" : __DIR__"shufang",
		"west" : __DIR__"chufang",
	]));
	 set("objects", ([
            __DIR__"npc/duanzm" : 1
	]) );


	set("coor/x",-310);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
    if((dir=="north")
     &&(!me->query_temp("enter"))){
	return notify_fail("�����Ǻ󹬣���û��Ҫ�����²�Ҫ�Ҵ���\n");
        }	
      return ::valid_leave(me, dir);
}
