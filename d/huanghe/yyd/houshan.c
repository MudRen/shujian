// houshan.c ��ɽ
// zly 99.7.28

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ɽ"NOR);
        set("long", @LONG
�����Ǻ�ɽ��һ�����ε�Сɽ�ȣ������˼����������й������죬����ɭ
ɭ����ʧΪһ����������ĺõط���ż����Զ������������������������
�����㣬��ֱ���������Լ�����������Դ��
LONG
        );
        set("exits", ([
		"south" : __DIR__"houyuan",
        ]));

        set("objects", ([
             __DIR__"npc/xiaozh" : 1,
             __DIR__"npc/yuangn" : 1,
        ]));
	set("outdoors", "�ƺ�");

        setup();
}
