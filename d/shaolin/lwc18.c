//lwc18.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似��������
�������һ���䳡��
LONG
	);

	set("exits", ([
		"north" : __DIR__"lwc15",
		"east" : __DIR__"lwc19",
		"west" : __DIR__"lwc17",
		]));
         set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",90);
  set("coor/y",260);
   set("coor/z",110);
   setup();

}

