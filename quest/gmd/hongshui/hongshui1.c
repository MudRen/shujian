#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"��ˮ��"NOR);
       set("long", @LONG
�����Ǻ�ˮ�졣������ʮ��������ˮ�����е��Ӹ�����ͨˮ�ԡ��򶫾�
��ͨ����ˮ��̶��ɽ��С·�ˡ�
LONG);    
        set("exits", ([
                "west" :  __DIR__"hongshui5",
                "east" : __DIR__"hongshui3",
                "south" :  __DIR__"hongshui2",
                "north" : __DIR__"hongshui4",
        ]));
                 
        
        set("outdoors", "���̹�����");
       
   setup();
}



   
//�Ǿ���
int is_mirror() { return 1; }
