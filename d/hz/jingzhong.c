// /u/beyond/hz/jingzhongbai.c ���Ұ�
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",GRN"���Ұ�"NOR);
        set("long", @LONG
Ĺ԰��������һ�����Ұء�ͤ�����ԡ���ʯ�����������ɼ��겻���ľ�
�񣬷�ӳ���������λ����Ӣ�۵ĳ羴������֮�顣
LONG
        );
        set("exits", ([
		"west" : __DIR__"yuanmen",
		"south" : __DIR__"mu",
	]));
	set("outdoors", "����");
	setup();
}
