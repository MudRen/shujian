inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"Ϸ԰��"NOR);
        set("long", @LONG
����һ�����ݳ��ﶦ��������Ϸ԰��Ϸ԰��������������ī����һӦ��
ȫ������һ����Ϸ̨��̨�����ڳ��š�����������̨�²�ʱ�ش���Ʊ���ǵ�
��Ծ���Ȳ�������Ҳ�̲�ס������������Ϸ������һ�½�ǡ�
LONG
);
	set("exits", ([
		"northeast" : __DIR__"beidajie1",
		"north" : __DIR__"majiu",
	]));
	set("objects",([
		__DIR__"npc/piaoyou" : 2,
	]));
	set("incity",1);
	setup();
}
