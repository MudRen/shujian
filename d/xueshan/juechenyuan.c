// Room: juechenyuan.c

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
�����Ǵ�����Ů���Ӱ��޵����ڣ����ڳ���򵥣���ɨ��һ����Ⱦ�����ǣ�
    һ�������в����а���ӯӯ��
    ľ���񼸣�����������
    �����������徻�޼š�
LONG
        );

	set("exits", ([
		"out" : __DIR__"yueliangmen",
	]));
        set("sleep_room",1);
        set("no_fight", 1);

	setup();
}
