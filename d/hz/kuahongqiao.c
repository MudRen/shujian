// /u/beyond/hangzhou/kuahongqiao.c �����
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"�����"NOR);
        set("long", @LONG
������ǻ���������ȫ��֮�أ��ǹ����յ̴���֮�����峿�ɹ�ƽ����
�����������Զ����ɽ¥�����ʺ磬��������ɹۡ�������Ҷ����̣�
ӳ�պɻ������족�ľ�ɫ��
LONG
        );
        set("exits", ([
        "north" : __DIR__"yingboqiao",
        "northwest" : __DIR__"quyuanfenghe",
        "west" : __DIR__"sudi",
]));
        setup();
}
