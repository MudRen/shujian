//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
������ʯ�ţ������ĵĲ�ʯ��������û�б�������ֻ�б�صİ���ʯ��
�������������ʯ�ذ��������������İ���ʯ�̳ɵġ�ʱ���д����Ŀ�����
�ٸ������������û��ûҹ�Ŀ��ɰ���ʯ������˵��º��û����վ������
������һ������
LONG );
	set("exits", ([
                "west" : __DIR__"gccheng",
                "south"     : __DIR__"hongsx",
		"north"     : __DIR__"wufosi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
		__DIR__"npc/caishiren" : 2,
	]));

	set("outdoors", "����");
	setup();
}
