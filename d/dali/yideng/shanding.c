// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���������죬ͻ���ǳ�����ǰ�죬ԭ���ѵ��˷嶥����̤��ƽ�أ�������
��¡һ�����죬����ɽʯ���ѣ�������ţ������������һ���˴���ߺ�ȡ�
LONG
	);
	set("outdoors", "��Դ��");
	set("exits", ([
		"eastup" : __DIR__"shanpo",
	]));

	setup();
}
