// kefang.c

inherit ROOM;
#include "hmy_def.c"

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
����һ���Ѿ����˰��µĿͷ���������һ���������ƺ��������ص�Ů����
�ڻ����ԣ�����������ܻ��ӳ���������ϣ��������ޡ�
LONG
        );

//	set("no_sleep_room",1);
//	set("no_fight",1);
//	set("no_get",1);
        set("exits", ([
                "south" : __DIR__"kedian",
        ]));
        
/*
        set("objects", ([
                __HMY__"npc/yingying" : 1,
        ]));
*/
        setup();
}
