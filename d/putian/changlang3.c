// Room: /d/putian/changlang3.c ����
// lklv 2001.7.22

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ľ��ĳ��ȣ����ȶ��ϵĻ����ϻ��������еĹ��£�������
�Ǻ�ɫ�������ߣ���������һ��ϸ���ʯ�ӡ��������涼�и������ţ�ż����
Сɳ�ֵ���ͷ�Ҵ��߹���
LONG
        );

        set("exits", ([
                "west" : __DIR__"jcyuan",
                "east" : __DIR__"nuange",

        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 4,
        ]));

        setup();
}

