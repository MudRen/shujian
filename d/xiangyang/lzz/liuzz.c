// Room: liuzz.c
// Csl y2k/4/26
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
��ӭ����������������Ӳ��󣬵�����������ȴ������������Ϊ�����
����ס��һλ�����������ҽ������̸�������������϶��鲻�Խ�¶���Ժ���
��ɫ��������һ��С�ƹݣ�������������һ��С�ӡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
		"south" : __DIR__"xiaolu",
		"north" : __DIR__"xiaohe",
		"west" : __DIR__"jiuguan",
        ]));
	setup();
}
