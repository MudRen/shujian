// Room: /d/shaolin/celang-2.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ԵĲ��ȡ�����������������Ҳ�ò�������˸��ַ����
ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡����洫������ľ���
�û�����������󳪡�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"sblu-1",
		"south" : __DIR__"celang-1",
                "west" : __DIR__"zdyuan",
	]));

	
	set("coor/x",40);
  set("coor/y",240);
   set("coor/z",110);
   setup();
}

