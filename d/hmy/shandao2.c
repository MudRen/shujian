// /d/hmy/shandao2.c ɽ��

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��һ·��ɽ�����Ƽ��գ�������������ȣ���ɽ����֮����խС������һ
�����񣬱ؽ���ɥ�ڴˡ�
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([ 
	 "westup" : __DIR__"baichi",
	 "eastdown" : __DIR__"shandao",
]));
        setup();
}