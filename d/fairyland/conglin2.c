// Room: /u/qingyun/jyzj/conglin2.c
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
	set("exits", ([
		"westup" : __DIR__"xuanya",
		"southdown" : "/d/group/entry/klclin1",
	]));
	set("outdoors", "����ɽ");
	set("no_clean_up", 0);

	setup();
}
