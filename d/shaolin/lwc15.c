//lwc15.c

inherit ROOM;

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ����������Ľ�
�ˣ���λ��ɮ��ɫׯ�ϣ���̤���Է�λΧ�ƣ��������С�
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc11",
		"north" : __DIR__"lwc13",
	        "west" : __DIR__ "lwc16",
                "south" : __DIR__ "lwc18",
        ]));
         set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",90);
  set("coor/y",270);
   set("coor/z",110);
   setup();

}

