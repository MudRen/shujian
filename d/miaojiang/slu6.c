// /u/dubei/�置


inherit ROOM;
#include "mjpoison.h"
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ��Сɽ�£�����������Ĺ�ľ�ԡ��Ա���һ�ô����������嶾����
��������Ѳ�ӡ�
LONG
        );

        set("exits", ([
            
                "southdown" : __DIR__"slu3",
                
        ]));
     
        set("objects",([
                __DIR__"npc/jiaozhong" : 2,

        ]));

       
        set("outdoors", "�置");

        setup();
  

}
