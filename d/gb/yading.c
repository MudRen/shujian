#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�¶�");
        set("long", @LONG
վ���¶�����Լ���Կ���Զ���ɹŴ���Ĳ��ϳ��������˼�������������
����
LONG
        );

	set("outdoors", "�ƺ�");

        set("exits", ([
		"southdown" : __DIR__"xiaodao",
		"down" : "/d/nanyang/duanya",
	]));

        setup();
}
