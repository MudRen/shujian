// Room: /d/emei/jieyindian.c ������ ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "������" NOR);
	set("long", @LONG
�������ұ߱��£��ǽ���졣������һ���ʯ����״���ӣ���������ʯ����
������һʯ������ʮ���ɣ��С�����ʯ�����ɴ��������ʼ��������֣����¾�
����ʮ���̡���ϴ��ء�
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"basipan3",
		"westup" : __DIR__"wanxingan",
	]));

	set("valid_startroom",1);

	setup();
}
