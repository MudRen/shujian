#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "��·");
       set("long",@LONG
������һ��������խ��С·����Լֻ�������˲��Ŷ����������Ƶء�
LONG);

       set("exits",([
            "westdown" : __DIR__"xialu",
            "northwest"  : __DIR__"xiaolu2",
            
       ]));
       set("coor/x",-310);
  set("coor/y",110);
   set("coor/z",90);
   set("coor/x",-310);
 set("coor/y",110);
   set("coor/z",90);
   setup();
       set("outdoors", "���̹�����");
}
//�Ǿ���
int is_mirror() { return 1; }