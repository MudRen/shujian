// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
��������ʯש�̳ɵ�С·��·���ϼ�����һЩ��ɳ��С·���߳���һЩҰ
�ݣ���������Ұ��Ʈ�������㣬С·�Ƴ����䣬��֪ͨ���δ���
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"northeast" : __DIR__"xiaojing2",
		"southeast" : __DIR__"houyuan",
	]));

	setup();
}
