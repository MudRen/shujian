// cl2.c ����
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"����"NOR);
       set("long", @LONG
����һ�����ȡ�һ������שǽ�ڣ���һ���ǹ�ľ��ɵ�Χ��������ͨ������
ȴҲ�����������һ����ƶ��ϡ������Ǻ�ˮ�죬���������䳡��
LONG);    
        set("exits", ([
                "east" : __DIR__"shuiqi",
                "west" : __DIR__"wu3",
        ]));      
        set("outdoors", "���̹�����");       
        set("coor/x",-280);
 set("coor/y",190);
   set("coor/z",120);
   setup();
}

