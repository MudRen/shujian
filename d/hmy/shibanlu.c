// /d/hmy/shibanlu.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ������ʯ��������ɵ�ʯ��·��ÿ��ʯ�嶼��ʮ�߼������޴�
�ޱȣ���·�����������½̵���ţ��ɴ�һֱ���ӵ�һ����ΰ��¥��֮ǰ��
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([ 
	  "south" : __DIR__"pailou",
	  "east" : __DIR__"qiandian",
]));
	setup();
}
