//pingtai.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ƽ̨");
	set("long", @LONG
�����Ǵ��۱���ǰ��һ��ƽ̨������ȫ�µ����ĵ㣬���е��ش���
�ڴ˾��С������ǽ������������������
LONG
	);

	set("exits", ([
		"north" : __DIR__"daxiong",
                "east" : __DIR__"jnlwang",
                "west" : __DIR__"liuzu",
                "southdown" : __DIR__"dxshijie",
        ]));
        
        set("objects",([
        CLASS_D("shaolin") + "/hui-xiu" : 1,
        ]));

        set("valid_startroom",1);
        set("outdoors", "shaolin");
        "/clone/board/bonze_b"->foo();
	set("coor/x",50);
  set("coor/y",290);
   set("coor/z",120);
   setup();
}



