// /d/hmy/xiangfang.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
���ڲ��õ�ʮ�����ʣ��ֱ�ڷ��ż��Ŵ󴲣������½�ͽ����Ϣ֮�á�
LONG
	);
	set("no_fight", "1");
	set("sleep_room", "1");
	set("exits", ([ 
	  "west" : __DIR__"pailou",
]));

	setup();
}
