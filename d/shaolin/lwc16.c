//lwc16.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬��ʮ����ɮ��������ϰ�似���ϱ���
�������һ�����䳡����������ϰ�书�õ��޺��Ų���
LONG
	);

	set("exits", ([
		"north" : __DIR__"lwc14",
		"east" : __DIR__"lwc15",
		"south" : __DIR__"lwc17",
                "west" : __DIR__"brtang",
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",270);
   set("coor/z",110);
   setup();

}

