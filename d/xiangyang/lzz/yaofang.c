// yafang.c 
// Looklove y2k 4/26

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIR"ҩ��"NOR);
    set("long",@LONG
����Ѧ����ҩ���������鵤��ҩ��ҽѧ�伮��Ӧ�о��С����в��ٶ�����
���Ϻ��Ѽ����ġ������и���ܣ�������ŴӸ����ռ�����ҽ��ҽ�䡣������
��Ʈ�㣬һ�����������㾫��һչ��������һ�����ȡ�
LONG);
        
        set("exits",([
                "north" :  __DIR__"chelang1",
                ]));
        
        set("coor/x",-50);
  set("coor/y",50);
   set("coor/z",0);
   setup();
}

