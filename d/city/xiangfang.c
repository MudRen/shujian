// Room: /d/city/xiangfang.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
�����ǳ�����Ŀͷ�����Ϊ�������Ҫ�����������Ƿ����ӣ����ԱȽ�
æ���������ڷ�����ٵ�Ե��������ʱ���ͷ���Ϊ�����ӵĵط����ͷ���һλ
��ɮ��æ�Ÿ���ҷַ����ӡ�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"chmiao.c",
	])); 
	set("objects", ([ 
		__DIR__"npc/monk" : 1, 
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	setup();
}
