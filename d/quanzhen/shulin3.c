// Code of ShenZhou
// road: /zhongnan/shulin3.c

inherit ROOM;

void create()
{
        set("short","����");

        set("long",@LONG
��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý�
��ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ��
���¡�ż��Զ�������޺�����������һ�����ܸС��������ϡ��Ͷ�����һ
��С����
LONG);

        set("exits",([ 
                "north" : __DIR__"shulin2",
                "south" : __DIR__"shulin4",
        ]));
        set("outdoors", "quanzhen");

        setup();

}

//#include "caiyao.h"

