// Room: /d/emei/qingshijie.c

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
�Ѿ��Ƕ���ɽ�����ˡ�����һ��ͨ�����ҵ���ʯ�ף�����������Σ�����
ʮ�����¡����Ϸ�ͨ����گ�Ĵ���������ߺ������˴��˸�С���
LONG
	);
	set("outdoors", "��üɽ");
	set("no_clean_up", 0);
	set("exits", ([ 
	  "southup" : __DIR__"baoguosm.c",
           "west" : __DIR__"caopeng",
          "east" : "/d/chengdu/tulu1",
]));

	set("coor/x",-180);
  set("coor/y",-110);
   set("coor/z",0);
   setup();
}
