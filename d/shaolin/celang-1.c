// Room: /d/shaolin/celang-1.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ����
ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡��ɴ�����ͨ���¥��
������һƬ�㳡��
LONG
	);

	set("exits", ([
		"west" : __DIR__"gulou",
		"south" : __DIR__"gchang-2",
                "north" : __DIR__"celang-2",
	]));

	
	set("coor/x",40);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}

