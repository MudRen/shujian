// /area/jiangbei/wudang/leishen.c ����
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"����"NOR);
        set("long", @LONG
����λ��������չ����϶˵İ�ɽ��������ȫ���ǡ������ͻ��׾���ˮ
ʥ�������������䵱ɽ����������΢�׷�������ĳ�������˵����������Ƿ�
������ġ����񶴵�ʯ���﹩����Ǳ���˫�ᣬӥ�����۵��������������
�������̴ӣ�һ����˾�飬һ���л���Ҳ����˵��һ���ǹܵ����˼��ƶ�
����һ����ר�Ŷ��ж�֮�˽��гͷ���
LONG
        );

        set("exits", ([
             "northeast" : __DIR__"gsdao3",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/jxk" : random(2)+1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
