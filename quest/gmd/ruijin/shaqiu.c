#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"Сɳ��"NOR);
       set("long", @LONG
����һ��������ɳ��Сɳ����һ̤��������ʧ�˷��򡣿���Ҫ�߳����
ɳĮ�������¡�
LONG);    

        set("exits", ([
                "westup" : __DIR__"shaqiu1",                                    
                "east" : __DIR__"ruijin"+(random(2)+1),
        ]));             
        
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}
//�Ǿ���
int is_mirror() { return 1; }