// Room: /d/shaolin/huilang4.c
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
		"north" : __DIR__"dmyuan",
		"west" : __FILE__,
                "east" : __DIR__"huilang3",
                "south" : __FILE__,
	]));

	
	set("coor/x",20);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}

