//xiangfang2.c ����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIM"˯��"NOR);
        set("long", @LONG
�����۱�˫�ƣ�������ȼ�ţ����ŵ���һƬ�ۺ��ɫ������˯��������
�ÿ������£��������ٴ�����һ��ջ��辰�������������𣬱�������ɴᣣ�
�������ҳ��ֳ�һ�ɸ߽����š���
LONG
        );        	

        set("exits", ([
               "west" : __DIR__"xiangfang1",               
        ]));      

        set("objects", ([
               __DIR__"npc/qi" : 1,
        ]));

        setup();
}
