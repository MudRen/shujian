// xiaolu1.c �ּ�С��
// by shang 97/6

inherit ROOM;
#include <ansi.h>
#include "xiaolu.h"

void create()
{
	set("short", GRN"С��"NOR);
	set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ��
������������������Ķ�����
LONG
	);
        set("outdoors", "�䵱");

        set("wdpass", 3);

	set("exits", ([
                "east" : __DIR__"xiaolu3",
                "west" : __DIR__"xiaolu4",
                "south" : __DIR__"xiaolu6",
                "north" : __FILE__,
	]));

        setup();
}
