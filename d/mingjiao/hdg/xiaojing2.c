// С�� xiaojing2.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "С��");
        set("long", @LONG
���������ţ���ǰ�ĺ���Խ��Խ�࣬�򻨻�ף���ڻ��ϣ��������衣��
��Ҳ��η�ˣ��ɽ���ʱ��������ͷ�ϡ����ϡ�����ͣ���������Ѿ����˺���
���ˡ�
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "northeast" : __DIR__"kongdi",
            "south" : __DIR__"xiaojing1",
        ]));

        setup();
}
