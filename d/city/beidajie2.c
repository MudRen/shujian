// /d/city/beidajie2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң�����˶�
���ϱ���ȥ������ͨ��һ�����ֵĹ㳡��������һ��������¡�ı�����ջ����
�Ը��ص����ǽ�������������������һ�����ֺŵ�Ǯׯ����Ϊ���ի��������
�����������Ľ���������
LONG
        );
	set("outdoors", "����");

	set("exits", ([
                "east" : __DIR__"kedian",
                "south" : __DIR__"beidajie3",
                "west" : __DIR__"qianzhuang",
                "north" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("incity",1);
	setup();
}

void init()
{
        object me = this_player();

	if (userp(me) && me->query("combat_exp") >1000000 && (int)me->query("jingli") < 500) {
                message_vision(HIY"ֻ��$N����һ��������ˤ�˸�����ſ��ԭ��$N���˸�����Ƥ��\n"NOR,me);
                me->start_busy(2);
        }
        return;
}