//lwc.c

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
		"north" : __DIR__"lwc2",
		"east" : __DIR__"lhtang",
		"west" : __DIR__"lwc5",
		"south" : __DIR__"lwc9",
	]));

	set("outdoors", "shaolin");
	set("coor/x",20);
  set("coor/y",280);
   set("coor/z",120);
   set("coor/x",20);
 set("coor/y",280);
   set("coor/z",120);
   setup();

}

