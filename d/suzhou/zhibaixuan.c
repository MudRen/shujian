#include <room.h>

inherit ROOM;

void create()
{
	set("short", "Ҿ��ָ����");
	set("long", @LONG
��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ˵���дʫ��
��֮��������ȡ���䡰ǰҾ®ɽ��һ����塱�͸����ġ�Цָͥǰ�ء���ʫ
�⡣���ڰ�������ɫ��ƾ����������Ŀʯ����ᾣ��Ű��֦���ƣ�������
Դ��ʮ�˾���֮�ơ�
LONG
);
	set("exits", ([
	"southwest" :__DIR__"shizilin",
        ]));
 	set("outdoors", "suzhou");
	set("coor/x",130);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}


