// /u/beyond/hz/quanwu.c Ȫ��
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIY"Ȫ��"NOR);
        set("long", @LONG
Ȫ����������Ȫˮ��������Ȫ���͡����ϸ��Ȫ����������Ȫ��������
�ڳ����ýŶ�أ�����ˮ��������ӿ��״��һ�ſ����顣�����ϸ��Ȫ����
��Ȫ�۶��ϸ�ܣ�Ȫˮϸϸ��ӿ���������´�ˮ���Ͽ�ȥ���������㣬��
����������ϸ�ꡣ
LONG
        );
        set("exits", ([
            "south" : __DIR__"yuquan",
                        
]));
        setup();
}
