// Room: qingxinshe.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ������е�����Ϣ�ĵط������ڳ���򵥣�ǽ���Ϲ�������֯ë̺��
������Ϊ��ϸ��ǽ���м���Ӳľ�崲�����߷��������ɵ÷��ƵĹ��ӡ�
LONG
	);

	set("exits", ([
		"out" : __DIR__"chiyangmen",
	]));
        set("sleep_room",1);
        set("no_fight", 1);

	setup();
}
