// Room: /d/putian/road07.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ɽ·ƽ����Щ���Ա߳�����һ�鲻��С�Ŀյأ��յ����м�����һ��
��ͤ��ż���ɼ�����ɮ�����ŵ�ˮ�����Աߵ�С·�߹���������ɽȥ��ɮ�˵ĽŲ�
����ȥ������ʵ���ȡ�
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"road06",
                "southup" : __DIR__"road08",
                "enter" : __DIR__"liangt",
        ]));

        set("objects",([
                NPC_D("youke") : 2,
                __DIR__"npc/wuseng" : 1,
        ]));

        set("outdoors", "����");
        setup();
}

