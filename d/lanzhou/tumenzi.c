//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ҳ����ǰפ���ĵط�����Χȫ��ɳĮ���м�һ��СС�����ޣ�����
�����е��ص������ס������ǰ��������һ������ռ��������������Ϊ��Ӫ
�ĳ����ӣ��޶�����
LONG );
	set("exits", ([
		"west"     : __DIR__"wuwei",
		"northeast" : "/d/group/entry/lzshixia",
	]));
	set("no_clean_up", 0);
	set("outdoors", "����");
	setup();
}
