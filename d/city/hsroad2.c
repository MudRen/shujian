// hsroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ��������ͨ������
�������������һ����·ͨ��ɽ�
LONG
	);
        set("outdoors", "wudang");

	set("objects", ([
		__DIR__"npc/dadao" : 1,
	]) );
	set("exits", ([
                "west" : "/d/huanghe/tiandi4",
            "east" : "/d/taishan/yidao2",
	]));

	set("coor/x",150);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

