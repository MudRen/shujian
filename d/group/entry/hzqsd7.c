// /u/beyond/hz/qsddao4.c ��ʯ���
 
inherit ROOM;
void create()
{
	set("short","��ʯ���");
	set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡�Զ�����Ǻ��ݳ��ˣ���Ҳ�����ӿ�Ų������ݱ���չ���������ǰ��
LONG
        );
	set("outdoors","���ݳ�");
	set("exits", ([
		"south" : "/d/hz/beimen",
		"north" : "/d/hz/shanlu3",
	]));
	setup();
}
