// Room: /d/shaolin/huilang1.c
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
		"east" : __DIR__"fatang",
		"south" : __FILE__,
                "north" : __DIR__"huilang2",
                "west" : __FILE__,
	]));

	
	set("coor/x",40);
  set("coor/y",410);
   set("coor/z",130);
   set("coor/x",40);
 set("coor/y",410);
   set("coor/z",130);
   setup();
}

