// /u/beyond/hz/qsddao2.c ��ʯ���

inherit ROOM;
void create()
{
        set("short","��ʯ���");
        set("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο���������������������
�����֡���Ҳ���²����ؼ����ں��ݹ��������ķ羰�����������ͨ����Ȫ��
������������Ľ��������������һ�������
LONG
        );
	set("objects",([
		__DIR__"npc/you1" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"sudi",
		"northwest" : __DIR__"yuemiao",
		"southeast" : __DIR__"qsddao3",
		"west" : __DIR__"yuquan",
	]));
	set("outdoors", "����");
	setup();
}
