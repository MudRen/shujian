// Code of ShenZhou
// road: /zhongnan/shulin1.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС����������ϸ���һ��С
����
LONG);

        set("exits",([ 
 "north" : "d/gumu/shulin1",
                "south" : __DIR__"shulin2",
        ]));

        set("outdoors", "quanzhen");
        
        setup();

}

//#include "caiyao.h"

