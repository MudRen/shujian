#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��÷��");
	set("long", @LONG
���ڵ����ʡ���������ƺ���黭��ȡ����÷���������Ҷ粴���Ѷ����
��ǰ��ֲ�����֦÷���Է���������Ϊ��ʱ�������顢�滭֮����
LONG
);      
        set("objects",([
        __DIR__"npc/binv" : 2,
        ]));  
	set("exits", ([
	"west" : __DIR__"zhenquting",
        "south" : __DIR__"lixuetang",
	]));
 	set("outdoors", "suzhou");
	set("coor/x",150);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}


