// By River@SJ

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"���ɽ"NOR);
	set("long", @LONG
���ɽ��ľ���ף�����ʯ�棬���б���ɽ��֮�ۣ��ּ��Ϲ�ɽɫ֮�㣬��
����������ľ��ӡ���֬����ɽ�ϱ�������ȥ�������ڽ̽���Ϊ��ʮ����ɽ֮
һ�����ż�ʤ�����࣬�����ư��������ɽ�����ص���ɽʤ�������ű��µ���
̨��⣬���ص����׶���������ʤ�ĵ���Ͽ����ʯϿ����Ȼ���ۡ� 
LONG );
	set("exits", ([
		"northdown"  : __DIR__"shanlu1",
		"southwest" : __DIR__"jingyuan",
	]));

	set("outdoors", "����");
	setup();
}
