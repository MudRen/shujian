// /u/dubei/wudang/maowu

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIW+"é��"+NOR);
        set("long", @LONG
������һ�������Ӵ�ɵ�é�ݣ����ڰ�����ӡ������ǽ���Ϲ���һ��ɽ
ˮ��������һ������������һλ���ߡ�����һ�������ϰڷ�������鼮��
LONG                           
        );
       
        
        set("exits", ([               
                 "north" : __DIR__"taoyuan3",
        ]));
        set("objects",([
                   "/clone/npc/laoweng" : 1,
        ])); 
        setup();

}

 