// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С����");
	set("long", @LONG
����������֮ң������֮�ڽ���һ��С���̣����������˶��ڴ˴��ס�ꡣ
�Ĵ�һ�ʣ�֪������������Դ�ع�Ͻ��
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"east" : "/d/group/entry/dlstulin",
		"southwest" : __DIR__"xiaolu1",
	]));

	setup();
}
