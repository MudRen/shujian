// Code of ShenZhou
// road: /zhongnan/dajiaochang.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"��У��"NOR);

        set("long", @LONG
����һ��λ�����ɽɽ����Բƺ������Ⱥɽ������ɽ������һ����ء�ÿ��
���£�ȫ���ɱ�춴˵ؾ��д�У���Կ������µ�������һ���Ľ�����������һ
����᫵�ɽ����������һ��ͨ���嶥��ɽ·�������б�����������ֻ��Զ��ʮ��
�������������������ɢ��ɽ�䡣
LONG );

        set("exits",([ "north" : "/d/quanzhen/jiaobei",
        ]));

        set("objects", ([
                CLASS_D("quanzhen") + "/zhao" : 1,
        ]));

        set("cost",1);
        set("outdoors", "zhongnan");
        setup();
}

//#include "/kungfu/class/quanzhen/beidou.h" 

