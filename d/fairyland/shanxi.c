// Room: /u/qingyun/jyzj/shanxi.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ɽϪ��");
	set("long", @LONG
������һ��СϪ������ɽ�����ѩ�������������£����ֱ�ѩ�ڻ���ˮ��
�����СϪ��Ϫˮ���¶�������֪������η�������������һ������֡�
LONG	);
	set("exits", ([
		"westup" : "/d/group/entry/klclin1",
                "eastup" : __DIR__"hmzhuang",
	]));
	set("outdoors", "����ɽ");
	set("no_clean_up", 0);

	setup();
}
