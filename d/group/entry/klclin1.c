// Room: /u/qingyun/jyzj/conglin1.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ѩɽ����");
	set("long", @LONG
����һ���ܴ�Ĵ��֣���ľ��֦Ҷ�Ϲ����˱�ѩ��ѩ�׵�һ��Ƭ��������
�ȡ�������ɽ�����죬ֱ��ɽ�����ڴ�����΢¶��һ��С������ϡ���ϣ�����
��С���ϣ�ѩ��������һ�г�������ӡ��
LONG	);
	set("group", 1);
	set("exits", ([
		"northup" : "/d/fairyland/conglin2",
		"eastdown" : "/d/fairyland/shanxi",
	]));
	set("outdoors", "����ɽ");

	setup();
}
