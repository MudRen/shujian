//lwc6.c

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
		"north" : __DIR__"lwc4",
		"east" : __DIR__"lwc5",
		"south" : __DIR__"lwc7",
                "west" : __DIR__"luohan5",
	]));

	set("outdoors", "shaolin");
	set("coor/x",0);
  set("coor/y",280);
   set("coor/z",120);
   set("coor/x",0);
 set("coor/y",280);
   set("coor/z",120);
   setup();

}

