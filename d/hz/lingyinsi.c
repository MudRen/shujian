// /u/beyond/hz/lingyinsi.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
�����¾߽�����һǧ�������ʷ�ˣ��Ƿ������ʮɲ֮һ�������¹�ģ
���Ⱥ��������ǰ��һ�������ᾭ�������Խ��ʱ��ԭ���Ϊ���
LONG
        );
        set("exits", ([
            "west" : __DIR__"tianwang",
            "east" : __DIR__"qsddao3",
            
]));
        setup();
}
