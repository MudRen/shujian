//lwc12.c


inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��Ĳ�
̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬���䳡����������һ���������ɵ�ľ
�ˣ�һЩ����ɮ������Χ����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"lwc13",
		"south" : __DIR__"lwc11",
	]));
           set("objects",([
		__DIR__"obj/mu-ren" : 1,
	]));

	set("outdoors", "shaolin");
	set("coor/x",100);
  set("coor/y",280);
   set("coor/z",110);
   setup();

}

