 // /u/beyond/hz/liulin.c ����
 
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
        "west" : __FILE__,
        "south" : __FILE__,
        "north" : __DIR__"liulin1",
        ]));
        set("coor/x",90);
  set("coor/y",-280);
   set("coor/z",0);
   setup();
}
