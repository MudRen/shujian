// /d/hmy/baihutang.c

inherit ROOM;

void create()
{
	set("short", "�׻���");
	set("long", @LONG
�����ڰڷ��Ÿ��ָ��������������в�ͬ��С��ɳ����ʯ����ʯ�̵����ߣ�
���뻹�����ż�ʮ���ߵͲ��ȵ�ľ׮�����е��Ӷ��ڴ���ϰ���ա� 
LONG
	);
	set("exits", ([ 
	  "east" : __DIR__"zhuquetang",
	  "south" : __DIR__"changlang",
	]));
	set("objects", ([ 
	  __DIR__"npc/sang" : 1,
	]));

	setup();
}
