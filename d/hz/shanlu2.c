// /d/hz/shanlu2.c ɽ·

inherit ROOM;
void create()
{
        set("short","ɽ·");
        set("long", @LONG
��ʯ�׵���ɽ�ۣ��������ţ�ӭ���С����ƻ��ɡ��ľ޷��ڻ����ٹ���
ͥ�����Ǹ��ǹۡ����ڹ�������������ϡ����Ƹ󡱿ɼ�ĿԶ��������Ⱥ
ɽ��������ɫ�����Լ��Ǯ��ɽˮ�����۵ף������̷ɶ�ʱ����ʹ������
������֮�С�
LONG
        );
	set("outdoors", "����");
	set("exits", ([
		"northdown" : __DIR__"zilaidong",
		"eastdown" : "/d/ningbo/qsddao1",
	]));
        set("objects", ([
                NPC_D("poorman") : 1,
        ]));
	setup();
}
