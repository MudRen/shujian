// /u/beyond/hangzhou/huxinting.c ����ͤ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"����ͤ"NOR);
        set("long", @LONG
����Ϻ���ͤ����ĿԶ��������ɽɫһ�����࣬�����������¡�ˮ��һ
ɫ���羰���ѡ�ͤ����һ���������ӿ����Զ��ɽ��ˮɫ����д�Ի����
����ͤ�������ˣ������¥�����ڳ�御�,�������ݺ���ͤ�ľ��ɫ�ġ�
LONG
        );
        set("exits", ([
        "east" : __DIR__"santan",
        "west" : __DIR__"ruangong",
	]));
	set("outdoors", "����");
        setup();
}
