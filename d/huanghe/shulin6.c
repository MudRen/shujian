// BY XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ
��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ��
������ԥ��ǰ���ĽŲ���
LONG );
	set("exits", ([
		"east"  : "/d/group/entry/hhshulin5",
                "north"  : __DIR__"fendi",
	]));

	set("outdoors", "�ƺ�");
	setup();
}
