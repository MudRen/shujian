#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
set("short",HIY"������"NOR);
set("long", @LONG
�����ź�������ݵ��˺�֮�ϣ�����������������������Ϊ���š�����
�����������������������ű��г����С��ߺ�ȡ������ţ���������������
�Ƿ������������ڱ̲�֮�ϣ���Ӧ���ԣ�����ཾ���������������µ�һ��
����֮�ء�
LONG
);
 set("outdoors", "suzhou");
 set("objects",([
          __DIR__"npc/xiaofan" :  1,
       ]));

  set("exits",([
    "north" : __DIR__"canglangting",
    "south" : __DIR__"nandajie1",
    "northeast" : __DIR__"dongdajie3",
    "northwest" : __DIR__"xidajie1",
    ]));
	set("coor/x",110);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}
