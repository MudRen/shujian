//lwc11.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似���ϱ���
�������һ���䳡��
LONG
	);

	set("exits", ([
		"north" : __DIR__"lwc12",
		"east" : __DIR__"banruo5",
		"west" : __DIR__"lwc15",
		"south" : __DIR__"lwc19",
	]));

	set("outdoors", "shaolin");
	set("coor/x",100);
  set("coor/y",270);
   set("coor/z",110);
   setup();

}

