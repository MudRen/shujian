//lwc14.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ���������ɵ���
��ͭ�ˣ�һЩ׳��ɮ�����������������С�
LONG
	);

	set("exits", ([
		"east" : __DIR__"lwc13",
		"south" : __DIR__"lwc16",
	]));
          set("objects",([
		__DIR__"obj/tong-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",280);
   set("coor/z",110);
   setup();

}

