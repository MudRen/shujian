// fyhouyuan.c ���ú�Ժ
// Looklove 2000/10/16

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "���ú�Ժ");
	set("long", @LONG
�����Ǹ��ú�Ժ���м��������������µؿ���ǽ�ǣ���ɹ̫�������졣��
����������������̲�˵���ˣ��׷����۽ǵ�������´������㡣һ�Եļ�ֻ
���ǹ���������ؿ��������������š�
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"dilao",
		"southeast" : __DIR__"ymzhengting",
	
	]));
        set("objects", ([
                 "clone/animal/langgou" : 4,
                __DIR__"npc/yayi" : 2,
        ]));
   	set("incity",1);
	setup();
}
