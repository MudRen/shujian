// /d/hmy/yiting.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������̵ľ��������ǽ������µĵط���ʱʱ���Լ�������ͬ����
��λ���������ڴ˹��̴�ƣ����и����������Ծ�̾����
LONG
	);
	set("exits", ([ 
	  "west" : __DIR__"changlang6",
	]));

	setup();
}
