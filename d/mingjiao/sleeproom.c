// sleeproom.c ��Ϣ��
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","��Ϣ��");
         set("long", @LONG
����һ�乩���̵�����Ϣ�ķ��䣬����������֣�������Կ��������ƾ�
�ӵĵ���ƽ�ͣ�����ŵ��һ�Ŵ����ָɾ������ʣ����ϼ�֮����������Ĺ��ߣ�
�㲻������˿˿���⡣
LONG);
         set("exits", ([
                "west" : __DIR__"xting",
         ]));    
         set("no_fight", 1);
         set("sleep_room", 1);
         set("coor/x",-280);
  set("coor/y",210);
   set("coor/z",120);
   set("coor/x",-280);
 set("coor/y",210);
   set("coor/z",120);
   setup();
}
