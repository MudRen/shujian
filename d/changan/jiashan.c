// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/jiashan.c

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
��ɫ��ɽ�εض���ɽ�忡�Σ�ɽ��Űأ�ɽ��Сͤ��ɽ�л���СԺ��ʯ
�š�ʯ�ҵȣ����ư��硣����СС�İ�ʯ���š����±��̵ĺ�ˮ������΢����
Զ���ĺ����ϴ���������������ߵ��������ź����ϴ�����΢��ʱ��ʱ��ҡ��
�š�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"jinghu",
        ]));

        set("incity",1);
	setup();
}