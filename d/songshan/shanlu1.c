// Room: /u/swl/songshan/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��·���ˣ���·��ʼ��᫲�ƽ��������ȥ���������˾���һ��ֻ��
��ɽ������ǰ��·���п�ʯ��(wall)����ɽ�����⡢���ֺ�������������
�����������Ŀ�������
LONG);
	set("exits", ([ 
            "west" : __DIR__"shanlu2",
            "down" : "/d/shaolin/shijie6",
        ]));
	set("item_desc", ([
             "wall" : "
          ******
          *    *
          * �� *
          *    *
          * �� *
          *    *
          * �� *
          *    *
          * ɽ *
          *    *
          ******\n",
]));
	set("outdoors", "��ɽ");
	set("coor/x",80);
  set("coor/y",150);
   set("coor/z",60);
   setup();
}
