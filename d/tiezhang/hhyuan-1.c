//hhyuan-1.c ��԰

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ���������ŵĻ�԰��ֻ���������񣬲Դ���죬������ᶣ������
�������һ����ɽ�������Ǵ�Ƭ�Ļ��ԡ�������ͨ��ɽ�ϵ�·��
LONG
	);

	set("exits", ([ 
"north" : __DIR__"shanlu-3",
"south" : __DIR__"hxfang",
"west" : __DIR__"hhyuan-3",
"east" : __DIR__"hhyang-2",
]));

	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-330);
  set("coor/y",-230);
   set("coor/z",10);
   setup();
}
