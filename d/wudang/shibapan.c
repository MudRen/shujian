// /d/wudang/shibapan.c ʮ����
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"ʮ����"NOR);
        set("long", @LONG
��������һ���ܴ��б�£��׳�ʮ���̣���ʯ��һ��һ����ֱ���ϣ��ķ�
�����������м���ɽ�񿪵�С�꣬�ο͵�������СϢ������������ǰʮ��֮��
�����䵱�ص�������ˡ�
LONG
        );
        set("exits", ([
                "southup" : __DIR__"fuzhen",
                "northdown" :__DIR__"caihong",
        ]));
        set("outdoors","�䵱");
        setup();

}
