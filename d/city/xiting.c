// Room: /d/city/xiting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ�����������֪�����鷿���鰸�����ҵط��ż������ƵĹż�
��һЩ���ڡ�ǽ�Ϲ������ݵ����ĵ�ͼ���������������ȦȦ��㣬����ϸ��
ȥ����������ξֵ�λ�á�
LONG
	);
	set("exits", ([
		"east" : __DIR__"ymzhengting",
	]));

	set("coor/x",90);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

