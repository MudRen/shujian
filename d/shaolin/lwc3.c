//lwc3.c

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
		"east" : __DIR__"lwc2",
		"south" : __DIR__"lwc5",
                "west" : __DIR__"lwc4",
		]));
         set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",10);
  set("coor/y",290);
   set("coor/z",120);
   set("coor/x",10);
 set("coor/y",290);
   set("coor/z",120);
   setup();

}

