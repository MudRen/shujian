#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"����"NOR);
       set("long", @LONG
����һƬ�����֡���ʮ�ɸߵ���ľ����һ�飬��ʵ��֦Ҷ��һ�����ɡ��
������գ��������ڵ�˿��Ҳ�ޡ���һ�߽������������ɭ�ֵģ���ĸо���
���㣬�øϿ��뿪��
LONG);    
        set("exits", ([
                "southwest" : __DIR__"gmd",                                    
                "eastup" : __DIR__"shulin2",
        ]));             
        
        set("outdoors", "���̹�����");
        set("coor/x",-300);
  set("coor/y",170);
   set("coor/z",100);
   setup();
}
//�Ǿ���
int is_mirror() { return 1; }