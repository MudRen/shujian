// Room: /d/shaolin/celang-4.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ����
ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡�����Ʈ�������׷���
���㣬����ɮ�������ŵ�ի�á�
LONG
	);

	set("exits", ([
		"east" : __DIR__"zhaitang",
		"south" : __DIR__"celang-3",
                "northwest" : __DIR__"sblu-1",
	]));

	
	set("coor/x",60);
  set("coor/y",240);
   set("coor/z",110);
   set("coor/x",60);
 set("coor/y",240);
   set("coor/z",110);
   setup();
}

