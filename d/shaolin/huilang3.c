// Room: /d/shaolin/huilang3.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ�������Ļ��ȡ�����������������Ҳ�ò�������˸��ַ����
ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡����������Ǵ��̵���
����΢����ɳɳ���졣���ܾ����ĵģ�ֻ�����Լ��ĽŲ����ڶ��߻ص���
LONG
	);

	set("exits", ([
		"west" : __DIR__"huilang4",
		"north" : __FILE__,
                "east" : __DIR__"huilang2",
                "south" : __FILE__,
	]));

	
	set("coor/x",30);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}

