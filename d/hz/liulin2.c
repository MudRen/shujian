 // /u/beyond/hz/liulin2.c ����
 
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
������һ��Ƭ���֣������дУ�һ����������ͷ������������������ȥ
���ߣ���Ҫ�ҵ�������·���������˰�����ֻ���û���ҵ�������·��
LONG
        );
        set("exits", ([
        "east" : __FILE__,
        "south" : __FILE__,
        "north" : __DIR__"shanlu1",
        ]));
        set("coor/x",90);
  set("coor/y",-260);
   set("coor/z",0);
   setup();
}
