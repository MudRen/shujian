// Code of ShenZhou
// road: /zhongnan/shulin6.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС��������ϸ���һ��С����
LONG);

        set("exits",([ 
                "north" : __DIR__"shulin5",
                "east" : __DIR__"milin",
        ]));
        set("outdoors", "quanzhen");

        setup();
        setup();

}

//#include "caiyao.h"
