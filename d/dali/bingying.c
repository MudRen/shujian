// Room: /dali/bingying.c
// bbb 1997/06/11
// Modify By River 98/12
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�����Ǵ������־��ı�Ӫ���ٱ������佫��ָ�����жӲ�����������ô��
��û��ս�£��ٱ��ǻ�������������󣬶����������������ʿ���ǲ�������
����и������ɲ��������˵����ĵط�������û��ǸϿ��뿪��
LONG
	);

	set("exits", ([
                "west" : __DIR__"dongjie3",
	]));

	set("objects", ([
             	__DIR__"npc/huang" : 1,
		__DIR__"npc/zhangquan" : 1,
                __DIR__"npc/bing" : 3,
	]));
	set("coor/x",-280);
  set("coor/y",-410);
   set("coor/z",-20);
   setup();
}

