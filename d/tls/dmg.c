inherit ROOM;

void create()
{
        set("short", "��ĸ��");
        set("long",@LONG
����������������ߵĵط��ˣ������϶����վ��������ˣ�����
С����ɽ���������ڵƻ�ͨ������վ���ſڣ�Զ�������£�ֻ��һƬ
�������಻�������Ǻƴ�
LONG);
        set("exits", ([
               "east" : __DIR__"road4",
//               "south" : __DIR__"yaofang",
               "north" : __DIR__"road6",
	]));
        set("coor/x",-360);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}
