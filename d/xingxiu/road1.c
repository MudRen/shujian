inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������ͨ�������˿���·�������ĳ���������������ţ�ӭ���
������������ˡ���ʱ��һ�Ӷ����˴�����߲��������
LONG
        );
        set("exits", ([
          "east" : "/d/xiangyang/shanxiroad2",
          "northwest" : __DIR__"road2",
        ]));

        set("outdoors", "jyg");

        set("coor/x",-10);
  set("coor/y",50);
   set("coor/z",0);
   setup();
}
