// Room: /d/shaolin/celang-3.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ����
ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡��ɴ���ͨ����¥��
������һƬ�㳡��
LONG
	);

	set("exits", ([
		"east" : __DIR__"zhonglou",
		"south" : __DIR__"gchang-3",
                "north" : __DIR__"celang-4",
	]));

	
	set("coor/x",60);
  set("coor/y",230);
   set("coor/z",110);
   set("coor/x",60);
 set("coor/y",230);
   set("coor/z",110);
   setup();
}

