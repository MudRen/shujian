// Room: /d/putian/celang4.c ����
// lklv 2001.7.23

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ľ��ĳ��ȣ����ȶ��ϵĻ����ϻ��������еĹ��£�������
�Ǻ�ɫ�������ߣ���������һ��ϸ���ʯ�ӡ������и������ţ�ͨ������
�㳡��ż����Сɳ�ֵ���ͷ�Ҵ��߹���
LONG
        );

        set("exits", ([
                "north" : __DIR__"sengshe",
                "west" : __DIR__"xiaoyuan4",
                "south" : __DIR__"xj4",

        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        setup();
}


