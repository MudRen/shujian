//lwc5.c

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
		"east" : __DIR__"lwc",
		"north" : __DIR__"lwc3",
	        "west" : __DIR__ "lwc6",
                "south" : __DIR__ "lwc8",
        ]));
         set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",10);
  set("coor/y",280);
   set("coor/z",120);
   set("coor/x",10);
 set("coor/y",280);
   set("coor/z",120);
   setup();

}

