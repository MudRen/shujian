// /d/hmy/zhuquetang.c

inherit ROOM;

void create()
{
	set("short", "��ȸ��");
	set("long", @LONG
����ֻ������յ�͵ƣ���������������������Զ������ְ�����ϡ��
�������ڴ�������������ò��α��Ʋ�����ˡ�
LONG
	);
	set("exits", ([ 
          "east" : __DIR__"cddian",
	  "west" : __DIR__"baihutang",
	]));
	set("objects", ([ 
	  __DIR__"npc/bao" : 1,
	]));

	setup();
}
