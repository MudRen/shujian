// room-ji.c ����

inherit ROOM;
#include <wanted.h>
void create()
{
	set("short", "����");
	set("long", @LONG
�����ڲ��嶫�����������һ�������������ǽ�ݶ�����ʽ�����ڵغ�
�˵�ש�ݣ�ֻ����Ϊ��ª���Ա���һ��Сˮ������ĵ�����С�ݺ��棬����
̽ͷ�Ӵ�����������������֪����������ͬʱ̽����������ȥ���Ǵ����ˡ�
LONG
	);
	set("exits", ([
		"enter" : __DIR__"room-ji1",
		"south" : __DIR__"road2",
		"northwest" : __DIR__"gebi1",
		"southeast" : __DIR__"caoyuan6",
	]));

	set("indoors", "��ԭ");

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northwest") {
		if (!userp(me))
			return 0;
		if (is_wanted(me))
			return 0;
	}
	return ::valid_leave(me, dir);
}
