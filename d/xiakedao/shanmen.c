// shanmen.c ɽ��

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���
һ��ɽ����ɽ�����죬��ʱ�м��������ú���������߹������Ƕ�
�ǵ����͵���ר���书�ġ�ʯ���Ͽ����������� "���͵�" �����
�ǽ����ϴ��ŵ����͵���
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "south" :"/d/xiakedao/dating",
                "north" : "/d/xiakedao/haitan",
        ]));
        set("objects", ([
                "/d/xiangyang/npc/zhangsan" : 1]));
        setup();
        replace_program(ROOM);
}

