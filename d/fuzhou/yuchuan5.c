// yuchuan5.c ؤ���洬

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�洬");
	set("long", @LONG
ͻȻ����ǰһ������������һ�Ҵ��ϣ��װ������ż�����ؤ��һ����׽
ʭ�ӣ� һ���þ����˫�۲�ͣ�ش������㡣������һ�����ţ�����ں����ģ�
��ʲôҲ�Ʋ�����
LONG
	);
	set("outdoors","����");

	set("exits",([
		"east" : __DIR__"yuchuan2",
		"south" : __FILE__,
		"enter" : __DIR__"fenduo1",
		"west"  : __DIR__"yuchuan4",
		"north" : __FILE__,
	]));
	setup();
}
